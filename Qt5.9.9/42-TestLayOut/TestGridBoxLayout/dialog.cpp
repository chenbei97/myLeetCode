#include "dialog.h"
#include <QDir>
#include <QDebug>

Dialog::Dialog(QWidget *parent)
  : QDialog(parent)
{
      this->setWindowTitle(tr("用户信息"));
      this->setFont(QFont("Time New Roman",12));
      this->resize(623,385); // 这个数值是根据警告信息推荐的

      /*****************左侧布局开始*******************/
      UserNameLabel = new QLabel(tr("用户名："));
      UserNameEdit = new QLineEdit;
      NameLabel = new QLabel(tr("姓名："));
      NameEdit = new QLineEdit;
      SexLabel = new QLabel(tr("性别："));
      SexCombo = new QComboBox;
      SexCombo->addItems(QStringList({"男","女"}));
      DepartmentLabel = new QLabel(tr("部门："));
      DepartmentEdit = new QLineEdit;
      AgeLabel = new QLabel(tr("年龄："));
      AgeEdit = new QLineEdit;
      RemarkLabel = new QLabel(tr("备注："));
      RemarkLabel->setFrameStyle(QFrame::Panel| QFrame::Sunken); // 设置形状带有边框并具备阴影效果

      LeftLayout = new QGridLayout;
      LeftLayout->addWidget(UserNameLabel,0,0);
      LeftLayout->addWidget(UserNameEdit,0,1);
      LeftLayout->addWidget(NameLabel,1,0);
      LeftLayout->addWidget(NameEdit,1,1);
      LeftLayout->addWidget(AgeLabel,2,0);
      LeftLayout->addWidget(AgeEdit,2,1);
      LeftLayout->addWidget(DepartmentLabel,3,0);
      LeftLayout->addWidget(DepartmentEdit,3,1);
      LeftLayout->addWidget(SexLabel,4,0);
      LeftLayout->addWidget(SexCombo,4,1);
      LeftLayout->addWidget(RemarkLabel,5,0,1,2); // 让备注占据2列1行
      LeftLayout->setColumnStretch(0,1);
      LeftLayout->setColumnStretch(1,3); // 第1列和第2列的比例是1/3
      // this->setLayout(LeftLayout); //测试用
     /*****************左侧布局结束*******************/


     /*****************右侧布局开始*******************/
      HeadLabel = new QLabel(tr("头像："));
      HeadImage = new QLabel; // 展示头像
      QIcon icon("head1.png");// ":/head1.png",QDir::currentPath()+"/head1.png"
      //QPixmap  pixmap;
      //pixmap.load(":/head1.png");
      HeadImage->setPixmap(icon.pixmap(QSize(128,64))); // 可以调整大小
      UpdateHeadImage = new QPushButton(tr("更新头像"));

      RightTopLayout = new QHBoxLayout; // 头像的水平布局
      RightTopLayout->setSpacing(20); // 3个控件的间距为20
      RightTopLayout->addWidget(HeadLabel);
      RightTopLayout->addWidget(HeadImage);
      RightTopLayout->addWidget(UpdateHeadImage);
      //this->setLayout(RightTopLayout);

      IntroductionLabel = new QLabel(tr("自我介绍："));
      IntroductionEdit = new QTextEdit;

      RightLayout = new QVBoxLayout; // 右侧的整体垂直布局
      RightLayout->setMargin(10);
      RightLayout->addLayout(RightTopLayout);
      RightLayout->addWidget(IntroductionLabel);
      RightLayout->addWidget(IntroductionEdit);
      //this->setLayout(RightLayout);
     /*****************右侧布局结束*******************/


    /*****************底部布局开始*******************/
    OkBtn = new QPushButton(tr("确定"));
    CancelBtn = new QPushButton(tr("取消"));
    BottomLayout = new QHBoxLayout;

    BottomLayout->addStretch(); // 按钮之前添加一个占位符使两个按钮能右对齐,对话框大小发生变化时按钮也不会变化
    BottomLayout->addWidget(OkBtn);
    BottomLayout->addWidget(CancelBtn);
    //this->setLayout(BottomLayout);
    /*****************底部布局结束*******************/


    /*****************主布局开始*******************/
    QGridLayout * mainLayout = new QGridLayout(this); // 指定父窗口this
    mainLayout->setMargin(15);// 主布局到窗口边缘距离15
    mainLayout->setSpacing(10);// 布局间距10
    mainLayout->addLayout(LeftLayout,0,0);// 左布局
    mainLayout->addLayout(RightLayout,0,1); // 右布局
    mainLayout->addLayout(BottomLayout,1,0,1,2); // 底部布局要横跨2列
    mainLayout->setSizeConstraint(QLayout::SetFixedSize); // 不加限制的话主窗口会自动变大,指定都按照sizeHint大小显示
    /*****************主布局结束*******************/

    connect(OkBtn,SIGNAL(clicked()),this,SLOT(accept()));
    connect(CancelBtn,SIGNAL(clicked()),this,SLOT(reject()));
}

Dialog::~Dialog()
{
}

