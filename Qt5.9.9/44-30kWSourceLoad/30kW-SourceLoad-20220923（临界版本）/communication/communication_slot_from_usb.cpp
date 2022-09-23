#include "communication/communication.h"

// 通讯界面串口通信：连接、断开、配置串口按钮clicked的槽函数
void Communication::on_PortConnectBtn()
{
      // 连接之前保证了串口已被配置
      mainWindow->openMonitor(); // 打开监控界面
      mFixedQueryTimer->start(); // 只控制start,不要控制串口的开启,在子线程中完成
      PortConnectBtn->setEnabled(false);
      PortDisconnectBtn->setEnabled(true); // 断开按钮可以使用
      PortConfigureBtn->setEnabled(false);// 配置按钮禁用
      quitBtn->setEnabled(false);// 运行状态不能退出
}

void Communication::on_PortDisconnectBtn()
{
      mFixedQueryTimer->stop(); // 只控制stop,不要控制串口的关闭,在子线程中完成
      PortConfigureBtn->setEnabled(true);
      PortConnectBtn->setEnabled(true);
      PortDisconnectBtn->setEnabled(false);
      quitBtn->setEnabled(true);// 停止运行后才能退出
      mainWindow->closeMonitor();
}

void Communication::on_PortConfigureBtn()
{
      SerialConfig * serialConfig = new SerialConfig;
      if (hasChanged(serialConfig->settings())) // 第一次进入时串口的serialConfig->settings()和私有属性mPortSettings都是默认设置，是相等的故第一次这里不执行
          serialConfig->setSettings(mPortSettings); // 第二次进入时如果串口设置发生过改变会通知更新设置,此时mPortSettings就和serialConfig不一样
          // 因为用户习惯是上次的设置保留,所以要把上次的更新同步到界面显示

      Qt::WindowFlags flags = serialConfig->windowFlags();
      serialConfig->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);//设置为固定大小
      int ret = serialConfig->exec();
      if (ret == QDialog::Accepted)
      {
          if (hasChanged(serialConfig->settings())) // 串口的新设置和之前的不一样
          {
              mPortSettings = serialConfig->settings();
              emit updatePortSettings(); // 发射信号通知串口设置发生了改变,然后立即调用on_UpdatePortSettings()函数更新mPort的设置
          }
      }
      delete  serialConfig;
}

// 比较串口配置界面当前的设置和上次保存的设置mPortSettings是否一直
bool Communication::hasChanged(SerialConfig::Settings settings)
{
      // 如果2个值不相等,说明串口对应属性改变了 bool = true, 字符串不需要再比,因为字符串是依据实数值生成的
      bool portChanged = settings.Name != mPortSettings.Name;
      bool baudrateChanged = settings.BaudRate != mPortSettings.BaudRate;
      bool databitChanged = settings.DataBit != mPortSettings.DataBit;
      bool stopbitChanged = settings.StopBit != mPortSettings.StopBit;
      bool parityChanged = settings.Parity != mPortSettings.Parity;
      bool flowcontrolChanged = settings.FlowControl != mPortSettings.FlowControl;

      // 有1个为真就返回真
      return portChanged || baudrateChanged || databitChanged || stopbitChanged || parityChanged || flowcontrolChanged;
}
