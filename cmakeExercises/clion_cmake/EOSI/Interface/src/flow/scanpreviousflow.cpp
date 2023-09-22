#include "../../inc/flow/scanpreviousflow.h"

ScanPreviousFlow::ScanPreviousFlow(QWidget *parent) : GradientHiddenWidget(parent)
{
    mSqlDlalog = new ScanPreviousFromSql;
    mSqlDlalog->setStyleSheet(styleSheet());
    mFromSql = new PushButton(tr("来自数据库"));
    mFromJson = new PushButton(tr("来自文件"));

    auto lay1 = new QHBoxLayout;
    lay1->addWidget(mFromSql);
    lay1->addStretch();

    auto lay2 = new QHBoxLayout;
    lay2->addWidget(mFromJson);
    lay2->addStretch();

    header->setText(tr("请选择来自数据库还是来自文件?"));
    mainlay->addStretch();
    mainlay->addSpacing(10);
    mainlay->addLayout(lay1);
    mainlay->addSpacing(ScanPreviousFlowSpacing);
    mainlay->addLayout(lay2);
    mainlay->addSpacing(ScanPreviousFlowSpacing);

    connect(mFromSql,&PushButton::clicked,this,&ScanPreviousFlow::onFromSql);
    connect(mFromJson,&PushButton::clicked,this,&ScanPreviousFlow::onFromJson);
}

void ScanPreviousFlow::onFromJson()
{
    auto path = appDataStandardPath();
    auto name = QFileDialog::getOpenFileName(this,tr("打开文件"),path,"*.json");
    if (name.isEmpty()) return;

    config.clear(); // 确保不被上次影响
    QByteArray content;

    QFile file(name);
    if (file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        int lineCount = 0;
        while (!file.atEnd()) {
            file.readLine();
            lineCount++; // 先算出总行数
        }
        file.seek(0);
        QProgressDialog * progress = new QProgressDialog("parsing files ...", "abort parse", 0, lineCount, this);
        progress->setWindowModality(Qt::WindowModal);
        progress->setAttribute(Qt::WA_DeleteOnClose);
        progress->setFixedSize(600,200); // 必须固定
        //progress->resize(600,300);
        progress->show();
        qApp->processEvents();
        lineCount = 0;
        while (!file.atEnd()) {
            content += file.readLine();
            lineCount ++;
            progress->setValue(lineCount);
            //LOG<<progress->wasCanceled(); // 不使用事件循环这里全部都打印执行完了
            if (progress->wasCanceled())
            {
                wasCanceled = true; // 标记是被取消的
                progress->close();
                file.close();
                return; // 注意是返回而不是break,否则wasCanceled总是false
            }
            QEventLoop loop;
            QTimer timer;
            timer.setSingleShot(true);
            connect(&timer, &QTimer::timeout, &loop,&QEventLoop::quit);
            connect(&timer, &QTimer::timeout, progress,[=]{progress->setValue(lineCount);});
            //timer.start(1000*lineCount); // 有了事件循环不需要变长延时了
            timer.start(qrand() %5); // 随机效果更真实
            loop.exec();
        } // 结束后progress自动关闭

        wasCanceled = false;
        //LOG<<"wasCanceled? "<<wasCanceled;
        //progress->close(); // 如果是被取消的不能这里关,还会弹出然后立刻消失
        file.close();
    }
    if (wasCanceled == true)
        return;
    ScanJsonReadWrite m;
    m.parseJson(content);
    config = m.map();
   // LOG<<"config.isEmpty() = "<<config.isEmpty();
}

void ScanPreviousFlow::onFromSql()
{
    config.clear(); // 确保不被上次影响
    int ret = mSqlDlalog->exec();
    if (ret == ScanPreviousFromSql::Accepted) {
        config = mSqlDlalog->configdata();
        //LOG<<config;
    }
}

QVariantMap ScanPreviousFlow::parseData()
{
    //LOG<<config;
    if (config.isEmpty())
        QMessageBox::critical(this,tr("错误"),tr("当前并无来自数据库或文本的配置解析结果!"));
    return config;
}

void ScanPreviousFlow::setCurrentUser(const QString& user)
{
    mSqlDlalog->setCurrentUser(user);
}

void ScanPreviousFlow::setStyle(QCString style)
{
    setStyleSheet(style);
    mSqlDlalog->setStyleSheet(style); // 样式手动传递给这个窗口
}
