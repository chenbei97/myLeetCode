#include "helloworld.h" // contains helloWorld
#include "ui_helloworld.h" // contains Ui::helloWorld ->public ui_helloWorld
#include <chrono>
#include <thread>
#include  <QPalette>
#include <QObject>
#include  <QColor>
#include  <QLabel>
#include  <QString>
#include  <QIcon>
helloWorld::helloWorld(QWidget *parent) // 类构造函数的定义
    : QMainWindow(parent) // 借助QMainWindow列表初始化QWidget对象
    , ui(new Ui::helloWorld) // ui私有属性可以new一个类对象,Ui::helloWorld定义在"ui_helloworld.h"
{
    ui->setupUi(this); // Ui::helloWorld有setupUi函数初始化,还有个retranslateUi函数,继承于ui_hello_world
    this->setWindowTitle("baby");
    QIcon icon (":/icons/Nevermore.ico");
    this->setWindowIcon(icon);
    init();
    QObject::connect(this->ui->rbt_red,&QRadioButton::clicked,this,&helloWorld::setTextColor);
    QObject::connect(this->ui->rbt_green,&QRadioButton::clicked,this,&helloWorld::setTextColor);
    QObject::connect(this->ui->rbt_blue,&QRadioButton::clicked,this,&helloWorld::setTextColor);
    //  QObject::connect(this->ui->rbt_blue,SIGNAL(clicked()),this,&helloWorld::setTextColor);// 语法有问题

    // 这样语法没问题,但是从结果看并没有响应,SIGNAL(clicked()),SIGNAL(click()),SIGNAL(this->ui->rbt_blur->click())都不起作用
    // 找到原因,这种情况用于带参数的槽函数和信号进行连接,不带参数应该使用函数指针的形式传递
     //QObject::connect(this->ui->rbt_blue,SIGNAL(clicked()),this,SLOT(setTextColor()));
}

helloWorld::~helloWorld()
{
    delete ui; // 析构时删除指针指向的内存
}


void helloWorld::on_btnclose_clicked()
{
    if (this->ui->handsome->isChecked()){
        this->close();
    }
    else{
        this->close();
        std::chrono::milliseconds dura(500);
        std::this_thread::sleep_for(dura);
        this->show();
    }
    return;
}
// 注意on和stateChanged之间的名称要和控件的名称一致
void helloWorld::on_handsome_stateChanged(int arg1)
{
    // printf("arg1 = %d\n",arg1); // 经实际测试,勾选状态arg1=2,否则为0
    if(arg1)
        this->ui->statusbar->showMessage("你终于承认我最帅了!");
    else
        this->ui->statusbar->showMessage("难道我不帅吗?");
}

void helloWorld::on_sexBox_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
                this->ui->statusbar->showMessage("你是男人");
                break;
        case 1:
                this->ui->statusbar->showMessage("你是女人");
                break;
       case 2:
                this->ui->statusbar->showMessage("你是人妖");
                break;
    }
}
void helloWorld::setTextColor(){
    // QPalette p; 直接p或者下方的p都可以
   // auto p = this->ui->widget->palette();
    auto p = this->palette();
    // this->ui->widget->setForegroundRole(QPalette::Foreground);
    // https://blog.csdn.net/ppss177/article/details/106269316
    if (this->ui->rbt_red->isChecked()){
          printf("signal = %d\n", 0);
          p.setColor(QPalette::Active,QPalette::Foreground,Qt::red); //  QPalette::ColorRole(0)=WindowText
          p.setColor(QPalette::Active,QPalette::Text,Qt::green);

    }else if (this->ui->rbt_green->isChecked()){
         printf("signal = %d\n", 1);
         p.setColor(QPalette::Active,QPalette::Foreground,QColor(0,255,0));
         p.setColor(QPalette::Active,QPalette::Text,Qt::blue);
      }
    else{
        printf("signal = %d\n", 2);
        p.setColor(QPalette::Active,QPalette::Text,Qt::red);
        p.setBrush(QPalette::Foreground,QBrush(QColor(0,0,255))); // Text是输入控件.wintext一般是显示控件
      }
    this->setPalette(p); // 必须用这个才能设置
    // this->ui->widget->setPalette(p); 用这个不起作用
}

void helloWorld::on_actionclose_triggered()
{
    this->close();
}

void helloWorld::on_actionreboot_triggered()
{
   this->close();
  std::chrono::milliseconds dura(1000);
  std::this_thread::sleep_for(dura);
  this->show();
}

void helloWorld::init()
{

     // 添加工具栏
     toolbar = new QToolBar(QString("toobar"));
     this->addToolBar(Qt::ToolBarArea::TopToolBarArea,toolbar); // 顶端构建
     // this->toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); // 显示文字在图标旁边
//     this->toolbar->setIconSize(QSize(24,24));

     // 设置SpinBox
     this->fontSizeBox = new QSpinBox;
     this->fontSizeBox->setValue(16);// 默认16号字
     this->fontSizeBox->setMinimum(5);// 最小5号字
     this->fontSizeBox->setMaximum(20) ;//最大20号字
     this->fontSizeBox->setMinimumWidth(10); // 控件最小宽度10
     this->toolbar->addWidget(new QLabel("字体大小"));
     this->toolbar->addSeparator(); // 添加分隔符
     this->toolbar->addWidget(fontSizeBox); // 添加进工具栏
     connect(this->fontSizeBox,SIGNAL(valueChanged(int)),this,SLOT(on_fontSizeBox_valueChanged(int))); // 连接好信号和槽函数
     // 设置进度条
     this->progressbar = new QProgressBar;
     this->progressbar->setMinimum(0);
     this->progressbar->setMaximum(100);
     this->progressbar->setValue(0);
     this->progressbar->setMinimumWidth(500);
     this->statusBar()->addWidget(progressbar); // 添加进状态栏
     // 菜单兰添加一个动作用于运行进度条
     // addAction和addMenu是这样用的,他们会返回指向新建的项地址
     QMenu * qm = this->menuBar()->addMenu("执行");
     qm->show();
     QAction * qac = qm->addAction("进度条");
     qac->setIcon(QIcon(":/icons/Saw.ico"));
     qac->setIconVisibleInMenu(true);
     qac->setIconText("Saw");
     if (qac->icon().isNull()) printf("the icon is empty!\n");
     else printf("not empty but couldn't show!\n");
     //printf("qm->icon().isNull()=%d",qm->icon().isNull());

     this->startProgressbar = qac; // 让这个指针指向new出来的
     connect(this->startProgressbar,&QAction::triggered,this,&helloWorld::on_startProgressbar_triggered);

}
void helloWorld::on_fontSizeBox_valueChanged(int fontsize)
{
    QFont font;
    font.setPointSize(fontsize);
    this->setFont(font);
}

void helloWorld::on_startProgressbar_triggered()
{
  for(int i = 1; i <= 100;++i){
     this->progressbar->setValue(i);
     std::chrono::milliseconds dura(100);
     std::this_thread::sleep_for(dura);
      QCoreApplication::processEvents(QEventLoop::AllEvents, 100); // 加上这句不会线程阻塞出bug
      // https://blog.csdn.net/hellokandy/article/details/106757349?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-1-106757349-blog-80063960.pc_relevant_aa&spm=1001.2101.3001.4242.2&utm_relevant_index=3
  }
}
