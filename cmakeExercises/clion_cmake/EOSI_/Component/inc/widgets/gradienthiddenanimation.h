#ifndef GRADIENTHIDDENANIMATION_H
#define GRADIENTHIDDENANIMATION_H

#include "qpropertyanimation.h"
#include "qgraphicseffect.h"
#include "../public.h"

class COMPONENT_IMEXPORT GradientHiddenAnimation : public QPropertyAnimation
{
    Q_OBJECT
public:
    explicit GradientHiddenAnimation(QObject *parent = nullptr);
    QGraphicsOpacityEffect * effect() const;
    void setEffect(QGraphicsEffect*effect);
private:
    QGraphicsOpacityEffect * meffect;
signals:

};

#endif // GRADIENTHIDDENANIMATION_H
