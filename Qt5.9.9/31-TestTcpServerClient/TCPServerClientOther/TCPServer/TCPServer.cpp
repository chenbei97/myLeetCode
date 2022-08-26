#include "TCPServer.h"
#include <QIntValidator>
TCPServer::TCPServer(QWidget *parent)
  : QDialog(parent)
{
      setWindowTitle("TCPServer");
      setFont(QFont("Times New Roman",12));
      resize(400,300);

      Content = new QListWidget;
      PortLabel = new QLabel("端口：");
      PortEdit = new QLineEdit(QString::number(8080));//默认8080
      QValidator * validator = new QIntValidator(1000,10000);
      this->PortEdit->setValidator(validator); // 端口号只能在[1000,10000]范围
      CreateBtn = new QPushButton("创建聊天室");
      connect(CreateBtn,SIGNAL(clicked()),this,SLOT(onCreateBtnClicked()));
      mainLayout = new QGridLayout(this);

      mainLayout->addWidget(Content,0,0,1,2);
      mainLayout->addWidget(PortLabel,1,0,1,1);
      mainLayout->addWidget(PortEdit,1,1,1,1);
      mainLayout->addWidget(CreateBtn,2,0,1,2);
}

void TCPServer::onCreateBtnClicked()
{
      port = this->PortEdit->text().toUInt(); // 获取输入的端口号,默认8080
      tcpServer = new mServer(this,port);//创建1个服务器对象
      // 服务器对象有1个信号,携带了来自mSocket的信息，连接到槽函数来显示到界面上
      connect(tcpServer,SIGNAL(updateServer(QString,qint64)),this,SLOT(onUpdateServer(QString,qint64)));
      CreateBtn->setEnabled(false);//开启后不能再创建
}


void TCPServer::onUpdateServer(QString msg,qint64 length)
{
      // 拿到的信息是为了显示在UI界面上
      Content->addItem(msg.left(length));
}

