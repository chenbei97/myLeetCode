#include "TCPClient.h"
#include <QDebug>

TCPClient::TCPClient(QWidget *parent)
  : QDialog(parent)
  , state(false)
  , port(8080)
  , serverAddr(new QHostAddress)
  , Content(new QListWidget)
  , SendMsgEdit(new QLineEdit("hello! 你还好吗?"))
  , SendBtn(new QPushButton("发送"))
  , UserNameLabel(new QLabel("用户名："))
  , UserNameEdit(new QLineEdit("chenbei"))
  , ServerAddrLabel(new QLabel("服务器地址："))
  , ServerAddrEdit(new QLineEdit("127.0.0.1"))
  , PortLabel(new QLabel("端口："))
  , PortEdit(new QLineEdit("8080"))
  , ChatBtn(new QPushButton("进入聊天室"))
  , mainLayout(new QGridLayout(this))
{
      setWindowTitle("TCPClient");
      setFont(QFont("Times New Roman",12));
      resize(400,300);

      mainLayout->addWidget(Content,0,0,1,2);
      mainLayout->addWidget(SendMsgEdit,1,0,1,1);
      mainLayout->addWidget(SendBtn,1,1,1,1);
      mainLayout->addWidget(UserNameLabel,2,0);
      mainLayout->addWidget(UserNameEdit,2,1);
      mainLayout->addWidget(ServerAddrLabel,3,0);
      mainLayout->addWidget(ServerAddrEdit,3,1);
      mainLayout->addWidget(PortLabel,4,0);
      mainLayout->addWidget(PortEdit,4,1);
      mainLayout->addWidget(ChatBtn,5,0,1,2);

      // 2个按钮的信号连接
      connect(SendBtn,SIGNAL(clicked()),this,SLOT(onSendBtn()));
      connect(ChatBtn,SIGNAL(clicked()),this,SLOT(onChatBtn()));
      SendBtn->setEnabled(false); // 进入聊天室才能发消息
}

void TCPClient::onChatBtn()
{
      if (!state) //如果未连接
      {
            QString addr = ServerAddrEdit->text();//输入的服务器地址需要检验是否合法
            if (!serverAddr->setAddress(addr)) // 说明输入地址格式不合法
            {
                  QMessageBox::critical(this,"错误","IP地址格式非法!");
                  return;
            }

            if (UserNameEdit->text() == "") // 没有用户名
            {
                QMessageBox::information(this,"提醒","必须输入一个用户名!");
                return;
            }

            userName = UserNameEdit->text(); // 拿到用户名
            port = PortEdit->text().toUInt();// 拿到端口号
            tcpSocket = new QTcpSocket; // 创建1个套接字
            // 连接套接字的3个信号
            connect(tcpSocket,SIGNAL(connected()),this,SLOT(onConnected()));
            connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisConnected()));
            connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
            // 开始连接指定的IP地址和端口
            tcpSocket->connectToHost(*serverAddr,port);
      }
      else //如果已连接,此时那个按钮是离开聊天室，这个时候点击就是离开
      {
          QString msg = "\""+userName+"\" 离开了聊天室";
          QByteArray bytes = msg.toLocal8Bit();
          int length = tcpSocket->write(bytes,bytes.length());
          if (length != bytes.length()) return; // 发送失败
          // 上边这段程序必须在这里写才有离开聊天室的效果，必须在disconnectFromHost之前才能发出去
          // 所以这段程序不能写在onDisconnected函数中
          tcpSocket->disconnectFromHost();//断开连接
      }
}

void TCPClient::onConnected() // 客户端连接上服务器后就把消息发出去
{
      SendBtn->setEnabled(true);//连接上才能发消息
      ChatBtn->setText("离开聊天室");
      state = true; // 已连接
      QString msg = QStringLiteral("\"")+userName+QStringLiteral("\" 进入了聊天室");
      QByteArray bytes = msg.toLocal8Bit();
      int length = tcpSocket->write(bytes,bytes.length());
      if (length != bytes.length()) return; // 发送失败
}

void TCPClient::onDisConnected()
{
    SendBtn->setEnabled(false); // 离开聊天室不能发消息
    ChatBtn->setText("进入聊天室");
    state = false;
//    QString msg = "\""+userName+"\" 离开了聊天室";
//    QByteArray bytes = msg.toLocal8Bit();
//    int length = tcpSocket->write(bytes,bytes.length());
//    if (length != bytes.length()) return; // 发送失败
}

void TCPClient::onSendBtn() // 点击发送一条消息
{
      if (SendMsgEdit->text() == "") return; //没有消息
      QString msg = "\"" + userName+"\"："+SendMsgEdit->text();
      QByteArray bytes = msg.toLocal8Bit();
      tcpSocket->write(bytes,bytes.length());
      SendMsgEdit->clear();
}

void TCPClient::onReadyRead() // 客户端读取来自服务器的消息
{
      while (tcpSocket->bytesAvailable() > 0)
      {
            QByteArray datagram;
            datagram.resize(tcpSocket->bytesAvailable());
            tcpSocket->read(datagram.data(),datagram.size());
            QString msg = QString::fromLocal8Bit(datagram);
            Content->addItem(msg);
      }
}
