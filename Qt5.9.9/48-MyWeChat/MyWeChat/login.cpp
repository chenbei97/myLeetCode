#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Login)
{
      ui->setupUi(this);
      setFont(QFont("Times New Roman",12));
      ui->userEdit->setFocus(); // 初始焦点置于输入用户名处

      connect(ui->pushButton,&QPushButton::clicked,this,[=]{
             if (ui->userEdit->text().isEmpty() || ui->pwdEdit->text().isEmpty())
             {
                QMessageBox::warning(Q_NULLPTR,"提示","请先输入用户名和密码!");
                return;
             }
             QDir currentPath = QDir::current();
             currentPath.cdUp();
             QFile file(currentPath.path()+"/userlog.xml");
             mXmlDoc.setContent(&file); // 设置文档内容
             QDomElement  root = mXmlDoc.documentElement(); // 返回文档的根元素
             if (root.hasChildNodes())
             {
                  QDomNodeList  userList = root.childNodes(); // 获取子节点列表
                  bool exist = false; // 用户是否存在
                  for (int i = 0; i < userList.count(); ++i)
                  {
                        QDomNode user = userList.at(i);//获取用户节点,用基类统一表示
                        QDomNodeList info = user.childNodes(); // 该用户的所有信息
                        // 获取用户名和密码,info has 2 nodes
                        QString username = info.at(0).toElement().text();  // 获取文本需要先转换为元素
                        QString password = info.at(1).toElement().text();
                        if (username == ui->userEdit->text()) // 用户名匹配
                        {
                            exist = true;
                            if (!(password == ui->pwdEdit->text())) // 但是密码错误
                            {
                                  QMessageBox::warning(Q_NULLPTR,tr("提示"),tr("密码错误,请重新输入!"));
                                  ui->pwdEdit->clear();
                                  ui->pwdEdit->setFocus();
                                  return;
                            }
                        }
                  }
                  if (!exist) // 如果遍历后exist还是false也就是用户名不存在
                  {
                       QMessageBox::warning(Q_NULLPTR,tr("提示"),tr("用户不存在,请重新输入"));
                       ui->userEdit->clear();
                       ui->pwdEdit->clear();
                       ui->userEdit->setFocus();
                       return;
                  }

                  // 说明用户存在且密码正确
                  mMainWindow = new MainWindow(Q_NULLPTR); // 显示主窗口
                  mMainWindow->setWindowTitle(ui->userEdit->text());
                  mMainWindow->show();
                  this->close();
             }
      });
}

