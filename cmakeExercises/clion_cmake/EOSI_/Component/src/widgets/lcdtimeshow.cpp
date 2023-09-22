#include "../../inc/widgets/lcdtimeshow.h"

LCDTimeShow::LCDTimeShow(QWidget *parent) : QWidget(parent)
{
    mDateTime = new Label(QTime::currentTime().toString("hh:mm:ss")+QDate::currentDate().toString());
    mDateTime->setFixedSize(LoginDateTimeWidth,LoginDateTimeHeight);
    mDateTime->setAlignment(Qt::AlignRight);
    mDateTime->setStyleSheet("color:white;");

    mTimer = new QTimer;
    mTimer->setInterval(TimerDuration_1000ms);
    mTimer->setTimerType(Qt::PreciseTimer); // 毫秒精度
    connect(mTimer,&QTimer::timeout,this,[=]{
        mDateTime->setText(QTime::currentTime().toString("hh:mm:ss\n")+QDate::currentDate().toString());
    });
    mTimer->start();

    mLayout = new QHBoxLayout;
    mLayout->addWidget(mDateTime);

    setLayout(mLayout);

    INIT_FONT;
}

