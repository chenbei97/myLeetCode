#include "monitor/monitor.h"

// 响应来自固定查询线程发送的VAPR数据信号、串口错误码、超时错误码信号
// 以及定义了3个翻译错误码变为中文的私有函数
void Monitor::on_Communication_AvailableFixedQueryData(const QList<QByteArray> &data) // 处理来自通讯模块发送来的串口固定查询数据
{
      Q_ASSERT(data.size() == 3);
      ShowVoltage->setText(data.at(0)+QStringLiteral(" V"));
      ShowCurrent->setText(data.at(1)+QStringLiteral(" A"));
      ShowPower->setText(data.at(2)+QStringLiteral(" W"));
}

void Monitor::on_Communication_ErrorCode(SERIALERROR code) // 处理来自固定查询的串口错误
{
        QString errorString = translateErrorCode(code);
        ConnectState->setText(tr("连接状态：%1").arg(errorString)); // 用arg考虑到翻译,拼接字符串的翻译会有问题

}

void Monitor::on_Communication_ErrorCode(TIMEOUTCODE code) // 处理来自固定查询的超时错误
{
        QString errorString = translateErrorCode(code);
        if (code == TIMEOUTCODE::RequestNormal || code == TIMEOUTCODE::RequestTimeout) // 请求的状态
        {
            MessageRequestState->setText(tr("消息请求状态：%1").arg(errorString));
        }
        else MessageReceiveState->setText(tr("消息回复状态：%1").arg(errorString));
}

void Monitor::on_Communication_ErrorCode(bool failed,SETTINGVARIABLE role)
{
      QString roleString = translateErrorCode(role);
      if (failed) MessageSetState->setText(tr("设定状态：%1%2").arg(roleString).arg("设定失败"));
      else MessageSetState->setText(tr("设定状态：%1%2").arg(roleString).arg("设定成功"));
}


QString Monitor::translateErrorCode(SERIALERROR code)
{
      QString s = tr("没有错误");
      switch (code)
      {
            case  SERIALERROR::OpenError: s = tr("打开错误");break;
            case  SERIALERROR::ReadError: s = tr("读取错误");break;
            case  SERIALERROR::WriteError: s = tr("写入错误");break;
            case  SERIALERROR::ParityError: s = tr("奇偶校验错误");break;
            case  SERIALERROR::FramingError: s = tr("帧错误");break;
            case  SERIALERROR::NotOpenError: s = tr("未打开错误");break;
            case  SERIALERROR::TimeoutError: s = tr("超时错误");break;
            case  SERIALERROR::ResourceError: s = tr("资源错误");break;
            case  SERIALERROR::PermissionError: s = tr("占用错误");break;
            case  SERIALERROR::BreakConditionError: s = tr("中断错误");break;
            case  SERIALERROR::DeviceNotFoundError: s = tr("设备未找到错误");break;
            case  SERIALERROR::UnsupportedOperationError: s = tr("不支持的操作错误");break;
            case  SERIALERROR::UnknownError: s = tr("未知错误");break;
            default: break;
      }
      return s;
}

QString Monitor::translateErrorCode(TIMEOUTCODE code)
{
      QString ret = tr("请求超时");
      switch (code)
      {
            case TIMEOUTCODE::ReceiveNormal: ret = tr("回复正常");break;
            case TIMEOUTCODE::RequestNormal: ret = tr("请求正常");break;
            case TIMEOUTCODE::ReceiveTimeout:ret = tr("回复超时");break;
            default: break;
      }
      return ret;
}

QString Monitor::translateErrorCode(SETTINGVARIABLE role)
{
      QString ret;
      switch (role)
      {
            case SETTINGVARIABLE::PowerSource: ret = tr("源功率");break;
            case SETTINGVARIABLE::PowerLoad: ret = tr("载功率");break;
            case SETTINGVARIABLE::ResistanceSource:ret = tr("源内阻");break;
            case SETTINGVARIABLE::ResistanceLoad: ret = tr("载内阻");break;
            case SETTINGVARIABLE::Voltage: ret = tr("电压");break;
            case SETTINGVARIABLE::CurrentSource: ret = tr("源电流");break;
            case SETTINGVARIABLE::CurrentLoad: ret = tr("载电流");break;
            case SETTINGVARIABLE::Current: ret = tr("电流");break;
            case SETTINGVARIABLE::VoltageSource: ret = tr("源电压");break;
            case SETTINGVARIABLE::VoltageLoad: ret = tr("载电压");break;
            default: break;
      }
      return ret;
}
