#include <communication/communication.h>

Communication::Communication(QWidget * parent) :QDialog(parent),
      mCommunicationType(Type::None),mainWindow((MainWindow *) parentWidget()),
      mPort(new QSerialPort),mPortFixedQueryThread(new SerialFixedQueryThread),
      mPortFixedQueryTimer(new QTimer(this)),mPortSetQueryWorker(new SerialSetQuery(mPort)),mPortSetQueryThread(new QThread),
      mHostName(tr("192.168.200.100")),mHostPort(30000),mTcpSocket(new QTcpSocket),mTcpFixedQueryThread(new QThread),
      mTcpFixedQueryWorker(new TcpQuery(mTcpSocket)),mTcpFixedQueryTimer(new QTimer(this))
{
          setFont(QFont("Times New Roman",12));
          resize(600,200);
          setWindowFlag(Qt::Window); // 设置window属性就不会总是让监控界面在前了
          setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
          setWindowFlag(Qt::WindowMinimizeButtonHint);
          setWindowModality(Qt::NonModal);
          setWindowIcon(QIcon(":/images/communication.png"));
          initUI();  
          initSerialConnections();
          initTcpConnections();
}

void Communication::paintEvent(QPaintEvent *e)
{
    QPainter p;
    p.begin(this);
    p.setOpacity(0.5);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    QPixmap pix(":/images/communication.jpg");
    p.drawPixmap(QPoint(0,0),pix);
    p.end();
    Q_UNUSED(e);
}

void Communication::closeEvent(QCloseEvent *e)
{
      if (PortDisconnectBtn->isEnabled() | TCPDisconnectBtn->isEnabled()) //如果没有关闭运行直接退出可能导致线程还在运行却无法停止会出现异常错误
      {
          QMessageBox::information(this,tr("消息"),tr("请先断开串口/TCP连接再关闭!"));
          e->ignore();
          return;
      }
      e->accept();
}

// UI布局
void Communication::initUI()
{
       PortLabel = new QLabel(tr("串口通信："));
       PortConnectBtn = new QPushButton(tr("连接"));
       PortConfigureBtn = new QPushButton(tr("配置"));
       PortDisconnectBtn = new QPushButton(tr("断开"));
       PortConfigureBtn->setIcon(QIcon(":/images/portsettings.png"));
       PortConnectBtn->setIcon(QIcon(":/images/portconnect.png"));
       PortDisconnectBtn->setIcon(QIcon(":/images/portdisconnect.png"));
       PortConnectBtn->setEnabled(false); // 必须先配置才能连接
       PortDisconnectBtn->setEnabled(false); // 必须已连接才能断开

       TCPLabel = new QLabel(tr("TCP通信："));
       TCPConnectBtn = new QPushButton(tr("连接"));
       TCPDisconnectBtn = new QPushButton(tr("断开"));
       TCPConfigureBtn = new QPushButton(tr("配置"));
       TCPConfigureBtn->setIcon(QIcon(":/images/portsettings.png"));
       TCPConnectBtn->setIcon(QIcon(":/images/tcp_connect.png"));
       TCPDisconnectBtn->setIcon(QIcon(":/images/tcp_disconnect.png"));
       TCPConnectBtn->setEnabled(false); // 同理
       TCPDisconnectBtn->setEnabled(false);

       mainLayout = new QGridLayout(this);
       mainLayout->addWidget(PortLabel,0,0);
       mainLayout->addWidget(PortConfigureBtn,0,1);
       mainLayout->addWidget(PortConnectBtn,0,2);
       mainLayout->addWidget(PortDisconnectBtn,0,3);
       mainLayout->addWidget(TCPLabel,1,0);
       mainLayout->addWidget(TCPConfigureBtn,1,1);
       mainLayout->addWidget(TCPConnectBtn,1,2);
       mainLayout->addWidget(TCPDisconnectBtn,1,3);
}

// 配置串口按钮的槽函数
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

// 比较串口配置界面当前的设置和上次保存的设置mPortSettings是否一致
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

// 配置TCP的槽函数
void Communication::on_TCPConfigureBtn()
{
      QDialog * dlg = new QDialog;
      QPalette pal = dlg->palette();
      pal.setBrush(QPalette::Background,QBrush(QPixmap(":/images/tcp.jpg")));
      dlg->setPalette(pal);
      dlg->setFont(QFont("Times New Roman",12));

      QLabel * IP = new QLabel(tr("IP地址："));
      QLabel * Port = new QLabel(tr("端口号："));
      QLineEdit * IPEdit = new QLineEdit(mHostName); // 保留上次的设置
      QLineEdit * PortID = new QLineEdit(QString::number(mHostPort));
      QIntValidator *val = new QIntValidator(0,400000);
      PortID->setValidator(val); // 设置输入必须是范围内的整数
      QPushButton * okBtn = new QPushButton(tr("确定"));
      QPushButton * cancelBtn = new QPushButton(tr("取消"));
      QGridLayout * layout = new QGridLayout(dlg);

      connect(okBtn,&QPushButton::clicked,this,[=]{
            mHostName = IPEdit->text();
            mHostPort = PortID->text().toUShort();
            QHostAddress addr;
            if (!addr.setAddress(mHostName))
            {
                QMessageBox::critical(this,tr("错误"),tr("IP地址格式不合法!"));
            }
            else dlg->accept();
      });
      connect(cancelBtn,SIGNAL(clicked()),dlg,SLOT(reject()));

      layout->addWidget(IP,0,0);
      layout->addWidget(IPEdit,0,1);
      layout->addWidget(Port,1,0);
      layout->addWidget(PortID,1,1);
      layout->addWidget(okBtn,2,0);
      layout->addWidget(cancelBtn,2,1);

      int ret = dlg->exec();

      if (ret == QDialog::Accepted)
      {
            mHostName = IPEdit->text();
            mHostPort = PortID->text().toUShort();
            TCPConnectBtn->setEnabled(true); //配置过就可用
      }
      delete dlg;
}
