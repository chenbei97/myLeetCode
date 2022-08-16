#include "baseinfo.h"
BaseInfo::BaseInfo(QWidget *parent) : QWidget(parent)
    ,UserNameLabel(new QLabel("用户名："))
    ,UserNameEdit(new QLineEdit("Phy-U"))
    ,NameLabel(new QLabel("姓名："))
    ,NameEdit(new QLineEdit("陈北"))
    ,AgeLabel(new QLabel("年龄："))
    ,AgeEdit(new QLineEdit("24"))
    ,DepartLabel(new QLabel("部门："))
    ,DepartEdit(new QLineEdit("军工部"))
    ,SexLabel(new QLabel("性别："))
    ,SexCombo(new QComboBox)
    ,RemarkLabel(new QLabel("备注：幽默理工男"))
    ,LeftLayout(new QGridLayout)
    ,HeadLabel(new QLabel("头像："))
    ,HeadImage(new QLabel)
    ,UpdateHeadBtn(new QPushButton("更新头像"))
    ,RightTopLayout(new QHBoxLayout)
    ,IntroLabel(new QLabel("自我介绍："))
    ,IntroEdit(new QTextEdit)
    ,RightLayout(new QVBoxLayout)
{

          // （1）左侧
          SexCombo->addItems(QStringList{"男","女","人妖"});
          RemarkLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);
          LeftLayout->addWidget(UserNameLabel,0,0); LeftLayout->addWidget(UserNameEdit,0,1);
          LeftLayout->addWidget(NameLabel,1,0); LeftLayout->addWidget(NameEdit,1,1);
          LeftLayout->addWidget(AgeLabel,2,0); LeftLayout->addWidget(AgeEdit,2,1);
          LeftLayout->addWidget(DepartLabel,3,0); LeftLayout->addWidget(DepartEdit,3,1);
          LeftLayout->addWidget(SexLabel,4,0); LeftLayout->addWidget(SexCombo,4,1);
          LeftLayout->addWidget(RemarkLabel,5,0,1,2); // 横跨2列
          LeftLayout->setColumnStretch(0,1);
          LeftLayout->setColumnStretch(1,3); // 1/3
          // （2）右侧
          HeadImage->setPixmap(QIcon(":/head.png").pixmap(QSize(128,64)));
          RightTopLayout->setSpacing(20);
          RightTopLayout->addWidget(HeadLabel);
          RightTopLayout->addWidget(HeadImage);
          RightTopLayout->addWidget(UpdateHeadBtn);

          RightLayout->setMargin(10);
          RightLayout->addLayout(RightTopLayout);
          RightLayout->addWidget(IntroLabel);
          RightLayout->addWidget(IntroEdit);
          // （3）主布局
          QGridLayout * mainLayout  = new QGridLayout(this);
          mainLayout ->setMargin(5);
          mainLayout ->setSpacing(10);
          mainLayout ->addLayout(LeftLayout,0,0);
          mainLayout ->addLayout(RightLayout,0,1);
          mainLayout->setColumnStretch(0,2);
          mainLayout->setColumnStretch(1,3);
          mainLayout ->setSizeConstraint(QLayout::SetFixedSize);

          this->setWindowTitle("基本信息修改");
          this->resize(800,600);
}
