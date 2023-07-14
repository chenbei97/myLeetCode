#include "TestMultiWindow.h"
#include "ui_TestMultiWindow.h"
// 关闭tabWidget的指定页,因为初始化时设置了ui->tabWidget->tabsClosable();
void TestMultiWindow::on_tabWidget_tabCloseRequested(int index)
{
// 之所以要写这个槽函数,是单击分页的关闭按钮不能关闭窗口
    if (index<0)
        return;

    QWidget* aForm=ui->tabWidget->widget(index); // 获取该页对应的窗口
    aForm->close();
}
// 切换页的槽函数
void TestMultiWindow::on_tabWidget_currentChanged(int index)
{
    ui->statusbar->showMessage(QString::asprintf("当前正在浏览第%d页",index));
    bool  en=ui->tabWidget->count()>0; //如果没有页了不能再切
    ui->tabWidget->setVisible(en); // 根据有无分页设置tabWidget是否可见
}
