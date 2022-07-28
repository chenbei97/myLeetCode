#include "TestQMutexBased.h"
#include "ui_TestQMutexBased.h"

TestQMutexBased::TestQMutexBased(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestQMutexBased)
{
        ui->setupUi(this);
        this->rolldice = new rollDice();
        this->ui->LabPic->setPixmap(QPixmap(":/images/d0.jpg"));
        this->initialize_button_enable();
        this->initialize_signals_slots_connection();
}

TestQMutexBased::~TestQMutexBased()
{
    delete ui;
}

// 1. 初始化信号与槽链接
void TestQMutexBased::initialize_signals_slots_connection()
{
    connect(this->rolldice,SIGNAL(started()),this,SLOT(thread_status_show()));
    connect(this->rolldice,SIGNAL(finished()),this,SLOT(thread_status_show()));
    // connect(this->rolldice,SIGNAL(transmit_dice_val_fre(int,int)),this,SLOT(dice_show(int,int))); 不使用信号槽机制(注释掉)
    // connect(this->rolldice, &QThread::finished, this->rolldice, &QObject::deleteLater);//释放线程资源

    connect(&this->mTimer,SIGNAL(timeout()),this,SLOT(onTimeOut())); // 第4个区别:记得绑定链接
}

// 2. 初始化使能函数
void TestQMutexBased::initialize_button_enable()
{
     // 开始掷骰子、暂停掷骰子、停止线程都得事先开启线程才能执行
    ui->btnStartThread->setEnabled(true); // 开始线程
    ui->btnDiceBegin->setEnabled(false); // 开始掷骰子
    ui->btnDicePause->setEnabled(false); // 暂停掷骰子
    ui->btnStopThread->setEnabled(false); // 停止线程
}

// 3.状态显示,回应thread的finished和started信号
void TestQMutexBased::thread_status_show()
{
       if (this->rolldice->isRunning())
           ui->LabA->setText("Thread状态：thread is running!");
       if (this->rolldice->isFinished())
           ui->LabA->setText("Thread状态：thread is finished!");
}

// 4.骰子点数、次数和图片显示，回应thread自定义的信号
//void TestQMutexBased::dice_show(int val,int fre)
//{
//    QString str = QString::asprintf("第 %d 次掷骰子，点数为 %d",fre,val);
//    ui->plainTextEdit->appendPlainText(str);
//    QPixmap pix; // 图片显示
//    QString filename = QString::asprintf(":/images/d%d.jpg",val);
//    pix.load(filename);
//    ui->LabPic->setPixmap(pix);
//}
// 第5个区别,onTimeOut()代替dice_show(int val,int fre)的功能
void TestQMutexBased::onTimeOut()
{
    int val = 0 , fre = 0;
    bool valid = this->rolldice->transmit_dice_val_fre(&val,&fre); //定时读取返回的值,但是不保证每次读取的就是新的数据,很可能工作线程来不及修改
    if (valid && (this->diceFrequency != fre)) // 数据有效,而且是新数据
    {
        this->diceFrequency = fre;
        this->diceValue = val; // 保存2个值用于下次比较
        QString str = QString::asprintf("第 %d 次掷骰子，点数为 %d",this->diceFrequency,this->diceValue);
        ui->plainTextEdit->appendPlainText(str);
        QPixmap pix; // 图片显示
        QString filename = QString::asprintf(":/images/d%d.jpg",this->diceValue);
        pix.load(filename);
        ui->LabPic->setPixmap(pix);
    }
}

// 5. 开启线程=>pushbutton的槽函数
void TestQMutexBased::on_btnStartThread_clicked()
{
        this->diceFrequency = 0; //  第6个区别,每当点击开始时记得初始化为0
        this->rolldice->start(); // 线程开始,button的槽函数通过start()=>控制run()
        ui->btnStartThread->setEnabled(false); // 开始线程
        ui->btnDiceBegin->setEnabled(true); // 开始掷骰子
        ui->btnDicePause->setEnabled(false); // 暂停掷骰子
        ui->btnStopThread->setEnabled(true); // 停止线程
}

// 6. 停止线程=>pushbutton的槽函数
void TestQMutexBased::on_btnStopThread_clicked()
{
        this->rolldice->stopDice(); // 停止线程
        this->rolldice->pauseDice(); // 也要暂停线程,否则下次启动线程直接就可以掷骰子了
        this->rolldice->wait(); // 阻塞此线程,防止启动,除非唤醒
        this->initialize_button_enable(); // 重新初始化使能
}

// 7. 开始掷骰子=>pushbutton的槽函数
void TestQMutexBased::on_btnDiceBegin_clicked()
{
        this->rolldice->startDice(); // 开始掷骰子,内部设置dpause=false,run()就会执行
        this->mTimer.start(100);// 第6个区别,定时器设置定时,在开始掷骰子而不是开启线程设置,因为此时才会有新数据准备读取它
        ui->btnDiceBegin->setEnabled(false); // 开始掷骰子
        ui->btnDicePause->setEnabled(true); // 暂停掷骰子
}

// 8.暂停掷骰子=>pushbutton的槽函数
void TestQMutexBased::on_btnDicePause_clicked()
{
        this->rolldice->pauseDice(); // 开始掷骰子,内部设置dpause=false,run()就会执行
        this->mTimer.stop(); // 第7个区别,不掷骰子了没有数据没必要再定时读取
        ui->btnDiceBegin->setEnabled(true); // 开始掷骰子
        ui->btnDicePause->setEnabled(false); // 暂停掷骰子
}

// 9.清空文本=>pushbutton的槽函数
void TestQMutexBased::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}

// 10.重载虚函数,确保关闭窗口后线程能够关闭
void TestQMutexBased::closeEvent(QCloseEvent *event)
{
    if (this->rolldice->isRunning())
    {
        this->rolldice->stopDice();
        this->rolldice->wait();
    }
    event->accept();
}
