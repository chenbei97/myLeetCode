#include "../../inc/widgets/gradienthiddenanimation.h"

GradientHiddenAnimation::GradientHiddenAnimation(QObject *parent) : QPropertyAnimation(parent)
{
    meffect = new QGraphicsOpacityEffect;
    meffect->setOpacity(1.0);

    setTargetObject(meffect);
    setPropertyName("opacity");
    setEasingCurve(QEasingCurve::InSine);
    setDuration(1500);
    setStartValue(0.0);
    setEndValue(1.0);
}

void GradientHiddenAnimation::setEffect(QGraphicsEffect *effect)
{
    setTargetObject(effect);
}

QGraphicsOpacityEffect * GradientHiddenAnimation::effect() const
{
    return meffect;
}
