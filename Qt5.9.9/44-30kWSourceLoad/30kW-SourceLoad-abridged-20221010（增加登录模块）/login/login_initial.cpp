#include <login/login.h>

void Login::initUI()
{
      //QPalette palette;
      //palette.setColor(QPalette::ColorRole::WindowText,Qt::blue);

      UserNameLabel->setBuddy(UserNameEdit);
      //UserNameLabel->setFrameShape(QFrame::Box);
      UserNameLabel->setFrameShadow(QFrame::Sunken);
      UserNameLabel->setAlignment(Qt::AlignCenter);
      //UserNameLabel->setPalette(palette);
      PassWordLabel->setBuddy(PassWordEdit);
      //PassWordLabel->setFrameShape(QFrame::Box);
      PassWordLabel->setFrameShadow(QFrame::Sunken);
      PassWordLabel->setAlignment(Qt::AlignCenter);

      UserNameEdit->setFocus();
      UserNameEdit->setFrame(false);
      PassWordEdit->setEchoMode(QLineEdit::Password);
      PassWordEdit->setFrame(false);

      ForgetPassWordBtn->setIcon(QIcon(":images/login_forgetpwd.png"));
      ForgetPassWordBtn->setIconSize(QSize(32,32));
      CreateCountBtn->setIcon(QIcon(":images/login_newaccount.png"));
      CreateCountBtn->setIconSize(QSize(32,32));
      OkBtn->setDefault(true);

      setWindowIcon(QIcon(":/images/login_back.png"));
      setFont(QFont("Times New Roman",12));
      setFixedSize(400,270);
      setAttribute(Qt::WA_DeleteOnClose);
      //setWindowFlag(Qt::SplashScreen);
      //setWindowFlag(Qt::FramelessWindowHint);

      QGridLayout * layout0 = new QGridLayout;
      layout0->addWidget(UserNameLabel,0,0,Qt::AlignRight);
      layout0->addWidget(UserNameEdit,0,1,Qt::AlignCenter);
      layout0->addItem(new QSpacerItem(100,30),1,0);
      layout0->addItem(new QSpacerItem(100,30),1,1);
      layout0->addWidget(PassWordLabel,2,0,Qt::AlignRight);
      layout0->addWidget(PassWordEdit,2,1,Qt::AlignCenter);
      layout0->setAlignment(Qt::AlignCenter);
      layout0->setSpacing(5);

      QHBoxLayout * layout1 = new QHBoxLayout;
      layout1->addWidget(ForgetPassWordBtn,1,Qt::AlignRight);
      layout1->addWidget(CreateCountBtn,1,Qt::AlignLeft);

      QHBoxLayout * layout2 = new QHBoxLayout;
      layout2->addStretch();
      layout2->addWidget(OkBtn);
      layout2->addWidget(CancelBtn);

      QVBoxLayout * mainLayout = new QVBoxLayout(this);
      //mainLayout->addItem(new QSpacerItem(100,10));
      mainLayout->addLayout(layout0);
      mainLayout->addItem(new QSpacerItem(100,15));
      mainLayout->addLayout(layout1);
      mainLayout->addItem(new QSpacerItem(100,15));
      mainLayout->addLayout(layout2);
}

void Login::initConnections()
{
    // 如果有此信号传出来,说明需要先创建用户,之前没有用户无法修改密码
    connect(mPaswordModifier,&RetrievePassword::createAccount,CreateCountBtn,&QPushButton::click);

    connect(UserNameEdit,static_cast<void (QLineEdit::*)(const QString&)>(&QLineEdit::textChanged),
            this,[=](const QString&username){
                mUserName = username;
                if (!usernameIsExist())
                {UserNameEdit->setToolTip(tr("已检测到该用户名不存在,请重新输入!"));IsExist=false;}
                else
                {UserNameEdit->setToolTip(tr("该用户名存在"));IsExist=true;}
    });

    connect(ForgetPassWordBtn,&QPushButton::clicked,this,[=]{
              mPaswordModifier->process();
    });

    connect(CreateCountBtn,&QPushButton::clicked,this,[=]{
            CreateAccount * dlg = new CreateAccount;
            int ret = dlg->exec();
            if (ret == QDialog::Accepted) QMessageBox::information(dlg,tr("消息"),tr("创建新用户成功"));
            else QMessageBox::information(dlg,tr("消息"),tr("已取消创建新用户"));
            delete  dlg;
    });

    connect(OkBtn,&QPushButton::clicked,this,[=]{
            mUserName = UserNameEdit->text().trimmed();
            mPassWord = PassWordEdit->text().trimmed();
            if (mUserName.isEmpty() || mPassWord.isEmpty())
            {
                QMessageBox::critical(this,tr("错误"),tr("用户名或密码不允许为空!"));
                return;
            }
            bool isCorrect = passwordIsCorrect();
            if (!IsExist  || !isCorrect)
            {
                ++tryCount;
                QMessageBox::critical(this,tr("错误"),tr("用户名或密码不正确,请重新输入!"));
                UserNameEdit->clear();
                PassWordEdit->clear();
                if (tryCount>4)
                {
                    QMessageBox::critical(this,tr("错误"),tr("输入错误次数超过5次，强制退出!"));
                    reject();
                }
                return;
            }
            accept();
    });

    connect(CancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
}
