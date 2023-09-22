#include "../../inc/main/mainsplash.h"

MainSplash::MainSplash(const QPixmap &pixmap,int duration,QWidget *parent)
    : QSplashScreen(parent),mDuration(duration)
{
    setPixmap(pixmap);
    setWindowFlag(Qt::WindowStaysOnTopHint);

    // 1. 处理splash的尺寸的位置
    auto rect = screen()->availableGeometry();
    resize(rect.width()/2,rect.height()/2 * 0.618);

    // 2. 初始化进度条
    mBar = new ProgressBar(this);
    mBar->setGeometry(0,height()-mBarHeight,width(),mBarHeight);  // 高度-25是Y位置,也就到底部距离25
//    mBar->setStyleSheet("QProgressBar {color:black;font:30px;text-align:center; }"
//                        "QProgressBar::chunk {background-color:none}" //  rgb(202, 165, 14);
//                        );
    mBar->setRange(0, SplashProgressBarMaxLimit);
    mBar->setValue(0);

    mController = new UpdateProgressController(mBar,mDuration);

    connect(mController,&UpdateProgressController::endSplash,this,&MainSplash::close);
    connect(mController,&UpdateProgressController::endSplash,this,&MainSplash::endSplashInner);
    connect(mController,&UpdateProgressController::endSplash,this,&MainSplash::setEndSplash);

    QVBoxLayout * lay = new QVBoxLayout(this);
    lay->addStretch();
    lay->addWidget(mBar);

}

void MainSplash::startSplash() // 外部的接口会启动splash更新
{
    //LOG<<"current thread id = "<<QThread::currentThreadId();
    show();
    mController->startSplash();
}

void MainSplash::setEndSplash()
{
    mEndSplash = true;
}

bool MainSplash::isEndSplash() const
{
    return  mEndSplash;
}

void MainSplash::mousePressEvent(QMouseEvent *e)
{
    e->ignore();
}

void MainSplash::resizeEvent(QResizeEvent *e)
{
    //pixmap().scaled(e->size());
    auto pix = pixmap();
    pix.scaled(e->size());
    setPixmap(pix);
    mBar->setGeometry(0,height()-mBarHeight,width(),mBarHeight);
    //repaint();
    auto rect = screen()->availableGeometry();
    move((rect.width()-width())/2,(rect.height()-height())/2);
    e->accept();
}

MainSplash::~MainSplash()
{

}

