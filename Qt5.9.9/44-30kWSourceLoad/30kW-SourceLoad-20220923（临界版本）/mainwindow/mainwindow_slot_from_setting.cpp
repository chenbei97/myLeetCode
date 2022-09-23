#include "mainwindow.h"

void MainWindow::on_SystemSettingsAct()
{

}

void MainWindow::on_BasicSettingsAct()
{
      BasicSettings * dialog = new BasicSettings(this);
      dialog->setSettings(mBasicSettings); //用户设置完后按照习惯那些参数还能保留,首次调用时也没有问题,因为mBasicSettings默认构造已初始化可以赋值
      Qt::WindowFlags flags = dialog->windowFlags();
      dialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);//设置为固定大小
      int ret = dialog->exec(); // 模态方式显示对话框
      if (ret == QDialog::Accepted) // 如果是接受的话要把设置的全部信息储存并提供给外部
      {
          mBasicSettings = dialog->settings(); // 其实不使用信号与槽机制也可以,借助提供公共函数来读取基本设置的信息
      }
      delete  dialog;
}

void MainWindow::on_UserSettingsAct()
{

}
