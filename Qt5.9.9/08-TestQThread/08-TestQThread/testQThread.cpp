#include "testQThread.h"
#include "ui_testQThread.h"

TestQThread::TestQThread(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestQThread)
{
    ui->setupUi(this);
    this->rolldice = new rollDice();
    this->ui->LabPic->setPixmap(QPixmap(":/images/d0.jpg"));
    this->initialize_button_enable();
    this->initialize_signals_slots_connection();
}

TestQThread::~TestQThread()
{
    delete ui;
}

// 1. 初始化信号与槽链接
void TestQThread::initialize_signals_slots_connection()
{
       connect(this->rolldice,SIGNAL(started()),this,SLOT(thread_status_show()));
       connect(this->rolldice,SIGNAL(finished()),this,SLOT(thread_status_show()));
       connect(this->rolldice,SIGNAL(transmit_dice_val_fre(int,int)),this,SLOT(dice_show(int,int)));
       // connect(this->rolldice, &QThread::finished, this->rolldice, &QObject::deleteLater);//释放线程资源
}

// 2. 初始化使能函数
void TestQThread::initialize_button_enable()
{
     // 开始掷骰子、暂停掷骰子、停止线程都得事先开启线程才能执行
    ui->btnStartThread->setEnabled(true); // 开始线程
    ui->btnDiceBegin->setEnabled(false); // 开始掷骰子
    ui->btnDicePause->setEnabled(false); // 暂停掷骰子
    ui->btnStopThread->setEnabled(false); // 停止线程
}

// 3.状态显示,回应thread的finished和started信号
void TestQThread::thread_status_show()
{
       if (this->rolldice->isRunning())
           ui->LabA->setText("Thread状态：thread is running!");
       if (this->rolldice->isFinished())
           ui->LabA->setText("Thread状态：thread is finished!");
}

// 4.骰子点数、次数和图片显示，回应thread自定义的信号
void TestQThread::dice_show(int val,int fre)
{
    QString str = QString::asprintf("第 %d 次掷骰子，点数为 %d",fre,val);
    ui->plainTextEdit->appendPlainText(str);
    QPixmap pix; // 图片显示
    QString filename = QString::asprintf(":/images/d%d.jpg",val);
    pix.load(filename);
    ui->LabPic->setPixmap(pix);
}

// 5. 开启线程=>pushbutton的槽函数
void TestQThread::on_btnStartThread_clicked()
{
        this->rolldice->start(); // 线程开始,button的槽函数通过start()=>控制run()
        ui->btnStartThread->setEnabled(false); // 开始线程
        ui->btnDiceBegin->setEnabled(true); // 开始掷骰子
        ui->btnDicePause->setEnabled(false); // 暂停掷骰子
        ui->btnStopThread->setEnabled(true); // 停止线程
}

// 6. 停止线程=>pushbutton的槽函数
void TestQThread::on_btnStopThread_clicked()
{
        this->rolldice->stopDice();
        this->rolldice->wait(); // 阻塞此线程,防止启动,除非唤醒
        this->initialize_button_enable(); // 重新初始化使能
}

// 7. 开始掷骰子=>pushbutton的槽函数
void TestQThread::on_btnDiceBegin_clicked()
{
        this->rolldice->startDice(); // 开始掷骰子,内部设置dpause=false,run()就会执行
        ui->btnDiceBegin->setEnabled(false); // 开始掷骰子
        ui->btnDicePause->setEnabled(true); // 暂停掷骰子
}

// 8.暂停掷骰子=>pushbutton的槽函数
void TestQThread::on_btnDicePause_clicked()
{
        this->rolldice->pauseDice(); // 开始掷骰子,内部设置dpause=false,run()就会执行
        ui->btnDiceBegin->setEnabled(true); // 开始掷骰子
        ui->btnDicePause->setEnabled(false); // 暂停掷骰子
}

// 9.清空文本=>pushbutton的槽函数
void TestQThread::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}

// 10.重载虚函数,确保关闭窗口后线程能够关闭
void TestQThread::closeEvent(QCloseEvent *event)
{
    if (this->rolldice->isRunning())
    {
        this->rolldice->stopDice();
        this->rolldice->wait();
    }
    event->accept();
}
