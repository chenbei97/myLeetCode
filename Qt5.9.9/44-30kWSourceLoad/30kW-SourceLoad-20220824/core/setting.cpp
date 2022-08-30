#include "mainwindow.h"
#include "dialog/BasicSettings.h"

void MainWindow::on_SystemSettingsAct()
{

}

void MainWindow::on_BasicSettingsAct()
{
      BasicSettings * dialog = new BasicSettings(this);
      dialog->setSettings(mBasicSettings); //用户设置完后按照习惯那些参数还能保留,首次调用时也没有问题,因为mBasicSettings默认构造已初始化可以赋值
      Qt::WindowFlags flags = dialog->windowFlags();
      dialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);//设置为固定大小
      // 基本设置窗口的basicSettings信号连接,此窗口是即开即删,所以在这里连接槽函数可以在mainwindow存储拿到的数据,也可以使用公共函数
      // connect(dialog,SIGNAL(basicSettings(const BasicSettings::Settings &)),this,SLOT(on_basicSettings(const BasicSettings::Settings &)));

      int ret = dialog->exec(); // 模态方式显示对话框
      if (ret == QDialog::Accepted) // 如果是接受的话要把设置的全部信息储存并提供给外部
      {
          mBasicSettings = dialog->settings(); // 其实不使用信号与槽机制也可以,提供公共函数来读取
      }
      delete  dialog;
}

void MainWindow::on_basicSettings(const BasicSettings::Settings &settings)
{
        mBasicSettings = settings;//从结果来看,默认构造函数有效,无需手动编写（因为是聚合类型的结构体）
}

void MainWindow::on_UserSettingsAct()
{

}
