#include "../../inc/widgets/groupbox.h"

GroupBox::GroupBox(QWidget*parent):QGroupBox(parent)
{
    mEffectSwitch = false;
    mEffect = nullptr;
    mAnimation = nullptr;
    INIT_FONT;
    //INIT_MINHEIGHT(200);
}

GroupBox::GroupBox(const QString&title,QWidget*parent):QGroupBox(parent)
{
    mEffectSwitch = false;
    mEffect = nullptr;
    mAnimation = nullptr;
    setTitle(title);
    INIT_FONT;
    //INIT_MINHEIGHT(200);
}

void GroupBox::enableEffect()
{
    mEffectSwitch = true;
    mEffect = new QGraphicsOpacityEffect(this);
    mEffect->setOpacity(1.0);
    setGraphicsEffect(mEffect);

    mAnimation = new QPropertyAnimation(mEffect,"opacity",this);
    mAnimation->setEasingCurve(QEasingCurve::Linear);
    mAnimation->setDuration(AnimationDuration_1000ms);
    mAnimation->setStartValue(0.0);
    mAnimation->setEndValue(1.0);
}

void GroupBox::disableEffect()
{
    mEffectSwitch = false;
}

GroupBox::~GroupBox()
{
    delete mAnimation;
    delete mEffect;
}

void GroupBox::hideEvent(QHideEvent *e) // 隐藏事件不需要,显示有动画效果即可,因为一开始就是隐藏的
{
//    mAnimation->setStartValue(1.0);
//    mAnimation->setEndValue(0.0);
//    mAnimation->start(QAbstractAnimation::KeepWhenStopped);
    QGroupBox::hideEvent(e);
}

void GroupBox::showEvent(QShowEvent *e)
{
    if (mEffectSwitch) {
        mAnimation->start(QAbstractAnimation::KeepWhenStopped);
    }
     QGroupBox::showEvent(e);
}

void GroupBox::resizeEvent(QResizeEvent *event)
{
    emit currentSize(event->size());
    QGroupBox::resizeEvent(event);
}
