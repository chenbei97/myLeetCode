#include "mainwindow.h"
#include "ui_mainwindow.h"

// 新建文档
void MainWindow::on_actNew_triggered()
{
    MyTextEdit * window = new MyTextEdit;// 新建文本编辑窗口
    ui->mdiArea->addSubWindow(window); // mdiarea区域添加窗口

    //在文本编辑中选择或取消选择文本时发出此信号,选择了文本就设为true
    // 可以进行复制和剪切操作,否则如果是取消选择文本就什么也不做
    connect(window,SIGNAL(copyAvailable(bool)),ui->actCut,SLOT(setEnabled(bool))); //控制动作是否可用
    connect(window,SIGNAL(copyAvailable(bool)),ui->actCopy,SLOT(setEnabled(bool)));

    window->newDoc(); // 调用公共函数创建新窗口
    window->show();
    setFormatMenuActEnabled(true); // 让格式菜单栏相关动作可用
}

// 打开文档
void MainWindow::on_actOpen_triggered()
{
    QString docName = QFileDialog::getOpenFileName(this, tr("打开"), QString(), tr("HTML 文档 (*.htm *.html);;所有文件 (*.*)"));
    if (!docName.isEmpty())
    {
        QMdiSubWindow *exist = findChildWnd(docName); // 找到这个活动子窗口
        if (exist)
        {
            ui->mdiArea->setActiveSubWindow(exist); //如果已存在不必新建否则自动创建新窗口
            return;
        }
        MyTextEdit *childwnd = new MyTextEdit;
        ui->mdiArea->addSubWindow(childwnd);
        connect(childwnd, SIGNAL(copyAvailable(bool)), ui->actCut, SLOT(setEnabled(bool)));
        connect(childwnd, SIGNAL(copyAvailable(bool)), ui->actCopy, SLOT(setEnabled(bool)));
        if (childwnd->loadDoc(docName))
        {
            statusBar()->showMessage(tr("文档已打开"), 2000);
            childwnd->show();
            setFormatMenuActEnabled(true);
        } else {
            childwnd->close();
        }
    }
}

void MainWindow::on_actSave_triggered()
{
    if (activateTextWindow() && activateTextWindow()->saveDoc())
        statusBar()->showMessage(tr("保存成功"), 2000);
}

void MainWindow::on_actSaveAs_triggered()
{
    if (activateTextWindow() && activateTextWindow()->saveAsDoc())
        statusBar()->showMessage(tr("保存成功"), 2000);
}

void MainWindow::on_actPrint_triggered()
{
    QPrinter pter(QPrinter::HighResolution);
    QPrintDialog *pdlg = new QPrintDialog(&pter, this);
    if (activateTextWindow()->textCursor().hasSelection())
        pdlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    pdlg->setWindowTitle(tr("打印文档"));
    if (pdlg->exec() == QDialog::Accepted)
        activateTextWindow()->print(&pter);
    delete pdlg;
}

void MainWindow::on_actPrintPreview_triggered()
{
    QPrinter pter(QPrinter::HighResolution);
    QPrintPreviewDialog pview(&pter, this);
    connect(&pview,static_cast<void (QPrintPreviewDialog::*)(QPrinter*)>(&QPrintPreviewDialog::paintRequested),this,
          [=](QPrinter * printer){
            activateTextWindow()->print(printer);
    });
    pview.exec();
}
