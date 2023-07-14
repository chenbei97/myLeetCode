#include "TestMultiWindow.h"
#include "ui_TestMultiWindow.h"

// 1. 嵌入式Widget窗体，并在tabWidget中显示
void TestMultiWindow::on_actWidgetInsite_triggered()
{
    QFormDoc *formDoc = new QFormDoc(this); //这里指定父窗口，单独用show()方法显示
    formDoc->setAttribute(Qt::WA_DeleteOnClose); //关闭时自动删除

    formDoc->setWindowFlag(Qt::Widget,true); // 看成是嵌入式部件不是窗口
    formDoc->setWindowFlag(Qt::CustomizeWindowHint,false);
    formDoc->setWindowFlag(Qt::WindowMinMaxButtonsHint,false);

//    formDoc->setWindowState(Qt::WindowMaximized); // 不要最大化
    formDoc->setWindowOpacity(0.5);
    formDoc->setWindowModality(Qt::WindowModal);

//    formDoc->show(); //不要在单独的窗口中显示
   // formDoc->setWindowTitle("基于QWidget的嵌入式窗口(有父窗口)，关闭时会自动删除释放对象"); // 这个文字不会显示,非窗口类没有标题栏
    int cur=ui->tabWidget->addTab(formDoc, // 可以多次创建.这样就可以生成多个页
            QString::asprintf("Doc %d",ui->tabWidget->count())); // 获取当前有的页数进行索引设置
    ui->tabWidget->setCurrentIndex(cur);
    ui->tabWidget->setVisible(true);
}

// 2. 独立的Widget窗口
void TestMultiWindow::on_actWidget_triggered()
{
    QFormDoc *formDoc = new QFormDoc(); //这里不指定父窗口this，用show()显示

    // 如果希望创建1次窗口后不能再创建可以包含以下2行代码,否则注释掉即可
    /********************************************************************/
    connect(formDoc,SIGNAL(isAboutClosed(bool)),this,SLOT(setActWidgetEnable(bool)));
    if (formDoc != nullptr) ui->actWidget->setEnabled(false);
    /********************************************************************/

    formDoc->setAttribute(Qt::WA_DeleteOnClose); //关闭时自动删除
    formDoc->setWindowTitle("基于QWidget的独立窗口(无父窗口)，关闭时会自动删除释放对象");

    formDoc->setWindowFlag(Qt::Window,true); // 表明此部件是个窗口,会带有窗口系统框架和标题栏
    formDoc->setWindowFlag(Qt::CustomizeWindowHint,true);// 关闭默认窗口标题提示
    formDoc->setWindowFlag(Qt::WindowMinMaxButtonsHint,true);// 添加最小化和最大化按钮
    formDoc->setWindowFlag(Qt::WindowCloseButtonHint,true); // 添加关闭按钮
    // formDoc->setWindowFlag(Qt::WindowStaysOnTopHint,true);// 通知窗口系统该窗口应位于所有其他窗口的顶部
    // formDoc->setWindowState(Qt::WindowMaximized); // 最大化状态
    formDoc->setWindowOpacity(0.9); // 透明度
    formDoc->setWindowModality(Qt::WindowModal); // 是否模态

    formDoc->show(); //在单独的窗口中显示
}

// 3. 嵌入式window
void TestMultiWindow::on_actWindowInsite_triggered()
{
    QFormTable *formTable = new QFormTable(this); // 有父窗口
    formTable->setAttribute(Qt::WA_DeleteOnClose); //关闭时自动删除
    //    aTable->setWindowTitle("基于QWidget的窗口，无父窗口，关闭时删除");
    int cur=ui->tabWidget->addTab(formTable,
              QString::asprintf("Table %d",ui->tabWidget->count()));
    ui->tabWidget->setCurrentIndex(cur);
    ui->tabWidget->setVisible(true);
}

// 4. 独立式window
void TestMultiWindow::on_actWindow_triggered()
{
    QFormTable* formTable = new QFormTable(this); // 有父窗口,区别是任务栏有没有显示,显示的话是没有this的
    //QFormTable* formTable = new QFormTable(); //无父窗体,在windows任务栏上有显示
    formTable->setAttribute(Qt::WA_DeleteOnClose); //对话框关闭时自动删除对话框对象,用于不需要读取返回值的对话框
    formTable->setWindowTitle("基于QMainWindow的独立窗口(无父窗口)，关闭时会自动删除释放对象");
    formTable->show();
}
