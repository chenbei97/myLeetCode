#include <monitor/monitor.h>

Monitor::Monitor(WORKMODE  workmode,QWidget *parent) : QMainWindow(parent),mWorkMode(workmode)
{
        resize(1200,800);
        setFont(QFont("Times New Roman",12)); //格式和字体要先初始化,然后基于此时窗口初始化布局,放在后头就会错误
        setWindowIcon(QIcon(":/images/monitorInterface.png"));
        QString title;
        if (workmode == WORKMODE::CV)
        {
              initCVUI();
              title = tr("监控界面(CV模式)");
        }
        else {
              initCCUI();
              title = tr("监控界面(CC模式)");
        }
        setWindowTitle(title);
}

void Monitor::paintEvent(QPaintEvent *e)
{
      QPainter p;
      p.begin(this);
      p.setOpacity(1.0);
      p.setRenderHint(QPainter::SmoothPixmapTransform);
      QPixmap pix(":/images/serial.jpg");
      pix.scaled(QSize(1200,800));
      p.drawPixmap(QPoint(0,0),pix);
      p.end();
      Q_UNUSED(e);
}

WORKMODE Monitor::workMode() const
{
      return mWorkMode;
}

void Monitor::setMessageState(TIMEOUTCODE code)
{
      QString errorString = translateErrorCode(code);
      if (code == TIMEOUTCODE::RequestNormal || code == TIMEOUTCODE::RequestTimeout) // 字符串变量需要使用QT_TR_NOOP标记翻译
          MessageRequestState->setText(tr("消息请求状态：%1").arg(QT_TR_NOOP(errorString))); // 请求状态
      else MessageResponseState->setText(tr("消息回复状态：%1").arg(QT_TR_NOOP(errorString))); // 回复状态
}

void Monitor::setConnectState(SERIALERROR error)
{
      QString errorString = translateErrorCode(error);
      ConnectState->setText(tr("串口连接状态：%1").arg(QT_TR_NOOP(errorString)));
}

void Monitor::setConnectState(TCPERRORSTATE error)
{
      QString errorString = translateErrorCode(error);
      ConnectState->setText(tr("TCP连接状态：%1").arg(QT_TR_NOOP(errorString)));
}

void Monitor::showMeasureState(const QList<QByteArray> &data)
{
      //Q_ASSERT(data.size() == 3);
    qDebug()<<"data = "<<data;
      if (data.size() != 3)
      {
          //QMessageBox::critical(this,tr("错误"),tr("串口/TCP数据格式解析错误"));
          qDebug()<<"串口/TCP数据格式解析错误 => "<<data;
          return;
      }
      ShowVoltage->setText(data.at(0)+QStringLiteral(" V"));
      ShowCurrent->setText(data.at(1)+QStringLiteral(" A"));
      ShowPower->setText(data.at(2)+QStringLiteral(" W"));
}

void Monitor::showSetState(bool ret, SETTINGVARIABLE role)
{
      QString roleString = translateErrorCode(role);
      QString retString = ret ? tr("设定成功"):tr("设定失败");
      MessageSetState->setText(tr("设定状态：%1%2").arg(QT_TR_NOOP(roleString)).arg(QT_TR_NOOP(retString)));
}

// 翻译错误码
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

QString Monitor::translateErrorCode(TCPERRORSTATE code)
{
      QString s ;
      switch (code)
      {
            case TCPERRORSTATE::ConnectionRefusedError:  s = tr("连接被拒绝"); break;
            case TCPERRORSTATE::RemoteHostClosedError:s = tr("远程服务器关闭");break;
            case TCPERRORSTATE::HostNotFoundError:s = tr("未找到服务器");break;
            case TCPERRORSTATE::SocketAccessError:s = tr("套接字没有权限");break;
            case TCPERRORSTATE::SocketResourceError:s = tr("套接字资源错误");break;
            case TCPERRORSTATE::SocketTimeoutError:s = tr("套接字连接超时");break;
            case TCPERRORSTATE::DatagramTooLargeError:s = tr("数据报太大");break;
            case TCPERRORSTATE::NetworkError:s = tr("网络错误");break;
            case TCPERRORSTATE::AddressInUseError:s = tr("远程服务器已被占用");break;
            case TCPERRORSTATE::SocketAddressNotAvailableError:s = tr("套接字地址无效");break;
            case TCPERRORSTATE::UnsupportedSocketOperationError:s = tr("不支持的套接字操作");break;
            case TCPERRORSTATE::ProxyAuthenticationRequiredError:s = tr("套接字代理需要身份验证");break;
            case TCPERRORSTATE::SslHandshakeFailedError:s = tr("SSL/TLS 握手失败");break;
            case TCPERRORSTATE::UnfinishedSocketOperationError:s = tr("未完成的套接字操作");break;
            case TCPERRORSTATE::ProxyConnectionRefusedError:s = tr("连接代理服务器被拒绝");break;
            case TCPERRORSTATE::ProxyConnectionClosedError:s = tr("代理服务器意外关闭");break;
            case TCPERRORSTATE::ProxyConnectionTimeoutError:s = tr("连接代理服务器超时");break;
            case TCPERRORSTATE::ProxyNotFoundError:s = tr("未找到代理服务器");break;
            case TCPERRORSTATE::ProxyProtocolError:s = tr("连接代理服务器失败");break;
            case TCPERRORSTATE::OperationError:s = tr("套接字处于不允许的操作");break;
            case TCPERRORSTATE::SslInternalError:s = tr("SSL库内部错误");break;
            case TCPERRORSTATE::SslInvalidUserDataError:s = tr("无效的SSL证明");break;
            case TCPERRORSTATE::TemporaryError:s = tr("临时错误");break;
            case TCPERRORSTATE::UnknownSocketError:s = tr("未知错误");break;

            case TCPERRORSTATE::UnconnectedState: s = tr("未连接");break;
            case TCPERRORSTATE::HostLookupState: s = tr("正在查找主机");break;
            case TCPERRORSTATE::ConnectingState:s = tr("正在连接");break;
            case TCPERRORSTATE::ConnectedState:s = tr("已连接");break;
            case TCPERRORSTATE::BoundState:s = tr("阻塞");break;
            case TCPERRORSTATE::ClosingState:s = tr("即将关闭");break;
            case TCPERRORSTATE::ListeningState:s = tr("正在监听");break;
            default:break;
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
