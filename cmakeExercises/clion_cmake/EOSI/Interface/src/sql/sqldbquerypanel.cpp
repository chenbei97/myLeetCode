#include "../../inc/sql/sqldbquerypanel.h"

SqlDBQueryPanel::SqlDBQueryPanel(QWidget *parent) : QWidget(parent)
{
        auto box1 = initleft();
        auto box2 = initright();
        mStatusBar = new QStatusBar;

        auto lay = new QHBoxLayout;
        lay->addWidget(box1);
        lay->addWidget(box2);
        box2->hide(); // 不显示命令行参数

        auto mlay = new QVBoxLayout(this);
        mlay->addLayout(lay);
        mlay->addWidget(mStatusBar);

        connect(mStartDateEdit,&QDateEdit::dateChanged,this,&SqlDBQueryPanel::onDateChanged);
        connect(mEndDateEdit,&QDateEdit::dateChanged,this,&SqlDBQueryPanel::onDateChanged);
        connect(mTableFields,&ComboBox::currentTextChanged,this,&SqlDBQueryPanel::onFieldChanged);
        connect(mKeyWordEdit,&LineEdit::textEdited,this,&SqlDBQueryPanel::onTextEdited);
        connect(mFilterBtn,&QPushButton::clicked,this,&SqlDBQueryPanel::onFilterBtn);
        connect(mExecBtn,&QPushButton::clicked,this,&SqlDBQueryPanel::onQueryBtn);
        connect(mClearBtn,&QPushButton::clicked,this,[=]{mPanel->clear();});
        connect(mCommand,SIGNAL(currentIndexChanged(QString)),this,SLOT(onCommandChanged(QString)));

}

GroupBox* SqlDBQueryPanel::initleft()
{
    mStartDateEdit = new DateEdit;
    mEndDateEdit = new DateEdit;
    mStartDateEdit->setMaximumDate(QDate::currentDate());
    mEndDateEdit->setMaximumDate(QDate::currentDate());
    mStartDateEdit->setDate(QDate(2021,7,1));
    mEndDateEdit->setDate(QDate::currentDate());

    mTableFields = new ComboBox;
    mSymbols = new ComboBox;
    mTableFields->setAlignment(Qt::AlignCenter);
    mSymbols->setAlignment(Qt::AlignCenter);
    mSymbols->addItems(QStringList()<<"="<<"<="<<">="<<"<"<<">"<<"!=");
    mSymbols->hide(); // 不要这个
    mKeyWordEdit = new LineEdit;
    mFilterBtn = new PushButton(tr("过滤"));
    //mTableFields->setMinimumWidth(100);
    //mSymbols->setMinimumWidth(100);
    mFilterBtn->setMaximumWidth(100);
    //mKeyWordEdit->setMinimumWidth(100);

    QFormLayout * top = new QFormLayout;
    top->addRow(tr("开始时间:"),mStartDateEdit);
    top->addRow(tr("结束时间:"),mEndDateEdit);
    top->labelForField(mStartDateEdit)->setFont(QFont(DefaultFontFamily,DefaultFontSize));
    top->labelForField(mEndDateEdit)->setFont(QFont(DefaultFontFamily,DefaultFontSize));

    QHBoxLayout * btm = new QHBoxLayout;
    btm->addWidget(mTableFields);
    btm->addWidget(mSymbols);
    btm->addWidget(mKeyWordEdit);
    btm->addWidget(mFilterBtn);

    auto lay = new QVBoxLayout;
    lay->addLayout(top);
    lay->addLayout(btm);

    GroupBox * box = new GroupBox;
    box->setLayout(lay);
    return box;
}

GroupBox* SqlDBQueryPanel::initright()
{
    mCommand = new ComboBox;
    mPanel = new LineEdit(tr("sql command..."));

    mExecBtn = new PushButton(tr("查询"));
    mClearBtn = new PushButton(tr("清除"));
    QHBoxLayout * bottomlay = new QHBoxLayout;
    bottomlay->addWidget(mExecBtn);
    bottomlay->addWidget(mClearBtn);

    QVBoxLayout * lay = new QVBoxLayout;

    lay->addWidget(mPanel);
    lay->addWidget(mCommand);
    lay->addLayout(bottomlay);

    auto box = new GroupBox(tr("命令行筛选"));
    box->setLayout(lay);
    return  box;
}

void SqlDBQueryPanel::showQueryResult(const QString& result)
{
    mStatusBar->showMessage(result);
}

void SqlDBQueryPanel::updateCommand(const QString& table,const QStringList&fields)
{
    mCommand->clear();
    mCommand->addItem("select * from "+table);
    mCommand->addItem("select * from "+table + " where ...");
    mCommand->addItem("select count(*) from "+table);
    mCommand->addItem("select count(*) from "+table +" where ...");
    foreach (auto field, fields)
        mCommand->addItem("select "+field+" from "+table);
}

void SqlDBQueryPanel::updateKeywords(const QString& table,const QStringList&fields)
{// 双击表后使用表的字段去更新下拉框
    Q_UNUSED(table);
    mTableFields->blockSignals(true); // 防止触发onFieldChanged造成一个轮回,双击表格无法显示原表
    mTableFields->clear();
    foreach (auto field, fields)
        mTableFields->addItem(field);
    mTableFields->blockSignals(false);
}

void SqlDBQueryPanel::onQueryBtn()
{
     auto text = mPanel->text();
     if (text.isEmpty()) return;
     if (!text.contains("select")) {
         QMessageBox::warning(this,tr("警告"),tr("只支持查询命令select!"));
         return;
     }
     if (text.count("select")>1) {
         QMessageBox::warning(this,tr("警告"),tr("多语句查询只以最后一句为准!"));
         int index = text.lastIndexOf("select");
         text.remove(0,index);

     }
    emit queryCommand(text);
}

void SqlDBQueryPanel::onCommandChanged(const QString& command)
{
    mPanel->setText(command);
}

//#define UseSetFilter 0
void SqlDBQueryPanel::onFilterBtn()
{
#ifdef UseSetFilter
    auto text = mKeyWordEdit->text().simplified();
    if (text.isEmpty()) return;
    auto key = mTableFields->currentText(); // 要过滤的列字段
    QString filter;
    if (mSymbols->isVisible()) // 如果可见,就用运算符>,<,>=等等,否则只匹配字符串
        filter = key +" " + mSymbols->currentText() + " \'" + text+"\'";
    else filter = key + " like \'%" + text + "%\' "; // select * from experments where type like 'jf%'
    emit filterField(filter); // filter => id = '2'
#else
    auto key = mKeyWordEdit->text().simplified();
    if (key.isEmpty()) return;
    auto field = mTableFields->currentText(); // 要过滤的列字段
    emit filterField(field,key); // filter => id = '2'
#endif
}

void SqlDBQueryPanel::onFieldChanged(const QString& field)
{
    Q_UNUSED(field);
    onFilterBtn(); // 手动触发
}

void SqlDBQueryPanel::onTextEdited(const QString& text)
{
    if (text.isEmpty()) return;
#ifdef UseSetFilter
    auto key = mTableFields->currentText(); // 要过滤的列字段
    QString filter;
    if (mSymbols->isVisible()) // 如果可见,就用运算符>,<,>=等等,否则只匹配字符串
        filter = key +" " + mSymbols->currentText() + " \'" + text+"\'";
    else filter = key + " like \'%" + text + "%\' "; // select * from experments where type like 'jf%'
    emit filterField(filter); // filter => id = '2'
#else
    auto field = mTableFields->currentText();
    emit filterField(field,text);
#endif
}

void SqlDBQueryPanel::onDateChanged()
{
    auto s = mStartDateEdit->date().toString("yyyy/MM/dd"); // 不加斜杠sqlite是查不出来的
    auto e = mEndDateEdit->date().toString("yyyy/MM/dd"); // 统一用斜杠
    emit dateChanged(s,e);
}
