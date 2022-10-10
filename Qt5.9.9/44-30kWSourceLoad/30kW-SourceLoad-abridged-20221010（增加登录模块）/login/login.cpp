#include <login/login.h>

Login::Login(QWidget*parent ):QDialog(parent)
  , UserNameLabel(new QLabel(tr("用户名称："))), UserNameEdit(new QLineEdit)
  , PassWordLabel(new QLabel(tr("用户密码："))), PassWordEdit(new QLineEdit)
  , ForgetPassWordBtn(new QPushButton(tr("忘记密码")))
  , CreateCountBtn(new QPushButton(tr("注册用户")))
  , OkBtn(new QPushButton(tr("确定"))),CancelBtn(new QPushButton(tr("取消")))
  , IsExist(false),tryCount(0),mPaswordModifier(new RetrievePassword)
{
    initUI();
    initConnections();
}

void Login::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) //左键按下,说明想要拖动
    {
          mMouseMove = true;
          mMouseLastPos = e->globalPos() - pos(); // 鼠标在电脑屏幕的位置-窗口的位置等于相对窗口的位置
    }
    return QDialog::mousePressEvent(e);//事件转交给父类对话框窗口执行
}

void Login::mouseMoveEvent(QMouseEvent *e)
{
      bool isLeftButton = e->buttons() & Qt::LeftButton; // 是左键按下
      bool isDrag = (e->globalPos() - mMouseLastPos).manhattanLength()  > QApplication::startDragDistance();

      if (mMouseMove && isLeftButton && isDrag)
      {
          move(e->globalPos()-mMouseLastPos);//窗口移动到新的位置
          mMouseLastPos = e->globalPos()-pos();//新的相对位置
      }
      return QDialog::mouseMoveEvent(e);
}

void Login::mouseReleaseEvent(QMouseEvent *e)
{
      mMouseMove = false;
      Q_UNUSED(e);
}

void Login::paintEvent(QPaintEvent *e)
{
    QPainter p;
    p.begin(this);
    p.setOpacity(0.5);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    QPixmap pix(":/images/login_back.jpg");
    pix.scaled(size());
    p.drawPixmap(QPoint(0,0),pix);
    p.end();
    Q_UNUSED(e);
}

bool Login::usernameIsExist()
{
      QDir currentDir = QDir::current();
      currentDir.cdUp();
      QFile file(currentDir.path()+"/config.xml");
      //qDebug()<<QFileInfo("config.xml").absoluteFilePath();
      QXmlStreamReader stream(&file);
      file.open(QIODevice::ReadOnly);
      while (!stream.atEnd())
      {
          if (!file.isOpen()) file.open(QIODevice::ReadOnly);
          if (stream.qualifiedName() == "username")
          {
              if (stream.readElementText() == mUserName)
              {
                  file.close();
                  return true;
              }
          }
          stream.readNext();
      }
      file.close();
      return false;
}

bool Login::passwordIsCorrect()
{
      QDir currentDir = QDir::current();
      currentDir.cdUp();
      QFile file(currentDir.path()+"/config.xml");
      QXmlStreamReader stream(&file);
      file.open(QIODevice::ReadOnly);
      while (!stream.atEnd())
      {
          if (stream.qualifiedName() == "username")
          {
              QString username = stream.readElementText();
              if (username == mUserName) // 用户名正确
              {
                  stream.readNext(); // 下一行不是密码,而是换行符
                  stream.readNext();// 再下一行就是密码了
                  QString pwd = stream.readElementText();
                  if (pwd == mPassWord) // 且密码正确
                  {
                          file.close();
                          return true;
                  }
              }
          }
          stream.readNext();
      }
      file.close();
      return false;
}
