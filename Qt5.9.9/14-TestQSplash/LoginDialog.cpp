#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include    <QMouseEvent>
#include    <QSettings>
#include    <QByteArray>
#include    <QCryptographicHash>
#include    <QMessageBox>
#include    <QDebug>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
        ui->setupUi(this);
        ui->editPSWD->setEchoMode(QLineEdit::Password); //密码输入编辑框设置为密码输入模式
        this->setAttribute(Qt::WA_DeleteOnClose);//设置为关闭时删除
        this->setWindowFlags(Qt::SplashScreen); //设置为SplashScreen, 窗口无边框,不在任务栏显示(唯一的一句用到QSplash)
        // this->setWindowFlags(Qt::FramelessWindowHint);//无边框，但是在任务显示对话框标题
        this->readSettings(); //读取存储的用户名和密码
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
// 1. 鼠标按键被按下事件
void LoginDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) // 如果是左键按下
    {
        this->m_moving = true; // 说明窗口将在鼠标操作下拖动
        //记录下鼠标相对于窗口的位置
        //event->globalPos()鼠标按下时，鼠标相对于整个屏幕位置
        //pos() this->pos()鼠标按下时，窗口相对于整个屏幕位置

        this->m_lastPos = event->globalPos() - this->pos(); // 鼠标位置减去窗口位置是鼠标相对窗口的位置
        qDebug()<<"鼠标位置="<<event->globalPos()<<" 窗口位置="<<this->pos()<<" 相对位置="<<this->m_lastPos;
    }
    return QDialog::mousePressEvent(event);  // 事件传入对话框的鼠标按键事件
}

// 2. 鼠标按下左键移动
void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
    // (event->buttons() && Qt::LeftButton)说明按下是左键,且要移动时会执行代码
    // 鼠标移动事件需要移动窗口,窗口移动到哪里呢？就是要获取鼠标移动中，窗口在整个屏幕的坐标，然后move到这个坐标，怎么获取坐标？
    // 通过事件event->globalPos()知道鼠标坐标，鼠标坐标减去鼠标相对于窗口位置，就是窗口在整个屏幕的坐标
    auto diff = event->globalPos()-this->m_lastPos;
    auto length = diff.manhattanLength(); // 勾股定理
    auto minDragDist = QApplication::startDragDistance();//拖放要求的最小距离
    qDebug()<<"鼠标相对上次的鼠标位置="<<diff
           <<" 直线距离="<<length<<" 拖放最小距离="<<minDragDist;
    // 鼠标相对上次的鼠标位置= QPoint(1561,364)  直线距离= 1925  拖放最小距离= 10（固定10）
    if (this->m_moving && (event->buttons() && Qt::LeftButton)
        && length > minDragDist)// 移动的距离最少大于拖放要求的最小距离
    {
        this->move(event->globalPos()-this->m_lastPos);
        this->m_lastPos = event->globalPos() - this->pos();
    }
    return QDialog::mouseMoveEvent(event);
}

// 3. 鼠标按键释放
void LoginDialog::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_moving=false; //停止移动
}


// 4. 读取存储的用户名和密码, 密码是经过加密的
void LoginDialog::readSettings()
{
    QString organization="WWB-Qt";// 用于注册表,注册表以键值对进行存储
    QString appName="TestQSplash"; // HKEY_CURRENT_USER/Software/WWB-Qt/TestQSplash(regedit打开注册表查找该目录就可以找到)
    QSettings   settings(organization,appName);//创建注册表设置

    // value() 返回设置键的值,如果设置不存在,则返回缺省值
    // 设置3个键值对.除了用户名和密码以外,saved来记录是否已经保存过

    bool saved=settings.value("saved",false).toBool();//读取saved键的值,缺省值是false(没保存过),所以saved其实就是false

    this->m_user=settings.value("Username", "cb").toString();//读取Username 键的值,缺省为"cb",用来给this->m_user初始化

    QString defaultPSWD=this->encrypt("123"); //缺省密码是"123"加密后的数据,encrypt是加密函数
    this->m_pswd=settings.value("PSWD",defaultPSWD).toString();//读取PSWD 键的值,缺省值是加密后的密码,用来给this->m_psw的初始化

    if (saved) //如果密码已经是保存过的会显示在文本编辑框内
        ui->editUser->setText(this->m_user);

    ui->chkBoxSave->setChecked(saved); // 密码的保存状态要和组件的checked状态一致
}

// 5.  保存用户名，密码等设置
void LoginDialog::writeSettings()
{
    QSettings   settings("WWB-Qt","TestQSplash"); //注册表键组
    settings.setValue("Username",this->m_user); //用户名
    settings.setValue("PSWD",this->m_pswd);   //密码,经过加密的
    settings.setValue("saved",ui->chkBoxSave->isChecked()); //"saved"键保存是否勾选密码
}

// 6. 字符串MD5算法加密
QString LoginDialog::encrypt(const QString &str)
{
    QByteArray btArray;
    btArray.append(str);//加入原始字符串
    QCryptographicHash hash(QCryptographicHash::Md5);  //Md5加密算法
    hash.addData(btArray);  //添加数据到加密哈希值
    QByteArray resultArray =hash.result();  //返回最终的哈希值
    QString md5 =resultArray.toHex();//转换为16进制字符串

    return  md5; // 加密后的16进制字符串
}

// 7. 确定按钮的槽函数
void LoginDialog::on_btnOK_clicked()
{
    QString user=ui->editUser->text().trimmed();//输入用户名
    QString pswd=ui->editPSWD->text().trimmed(); //输入密码

    QString encrptPSWD= this->encrypt(pswd); //对输入密码进行加密

    if ((user==this->m_user)&&(encrptPSWD==this->m_pswd)) //如果用户名和密码正确
    {
        this->writeSettings();// 保存设置
        this->accept(); //对话框 accept()，关闭对话框
    }
    else
    {
        m_tryCount++; //错误次数
        if (m_tryCount>3)
        {
            QMessageBox::critical(this, "错误", "输入错误次数太多，强行退出");
            this->reject(); //退出
        }
        else
            QMessageBox::warning(this, "错误提示", "用户名或密码错误");
    }
}

// 8. 取消按钮的槽函数
void LoginDialog::on_btnCancel_clicked()
{
    this->reject();
}
