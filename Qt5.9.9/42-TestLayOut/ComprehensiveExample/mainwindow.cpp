#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QFrame(parent)
  ,stackWindow(new QStackedWidget)
  ,baseinfo(new BaseInfo)
  ,concact(new Contact)
  ,detail(new Detail)
  ,AmendBtn(new QPushButton("修改"))
  ,CloseBtn(new QPushButton("关闭"))
  ,HLayout(new QHBoxLayout)
  ,mainLayout(new QVBoxLayout)
{
    stackWindow->setFrameStyle(QFrame::Panel | QFrame::Raised);
    stackWindow->addWidget(baseinfo);
    stackWindow->addWidget(concact);
    stackWindow->addWidget(detail);

    HLayout->setMargin(5);
    HLayout->setSpacing(5);
    HLayout->addStretch(); // 占位符
    HLayout->addWidget(AmendBtn);
    HLayout->addWidget(CloseBtn);

    mainLayout->setMargin(20);
    mainLayout->setSpacing(10);
    mainLayout->addWidget(stackWindow);
    mainLayout->addLayout(HLayout);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    //QObject::connect(AmendBtn,SIGNAL(clicked()),this,SLOT(hide())); //自身不是顶级窗口,要在main.cpp关闭
    //QObject::connect(CloseBtn,SIGNAL(clicked()),this,SLOT(close()));
    this->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{

}

