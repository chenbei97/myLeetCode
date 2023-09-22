#ifndef BUTTON_H
#define BUTTON_H

#include "qpushbutton.h"
#include "qpropertyanimation.h"
#include "qgraphicseffect.h"
#include "../public.h"

class COMPONENT_IMEXPORT Button : public QPushButton
{
    Q_OBJECT
private:
    QGraphicsOpacityEffect * mEffect;
    QPropertyAnimation * mAnimation;
    bool mEffectSwitch;
public:
    bool mState;
    explicit Button(QWidget* parent = nullptr);
    explicit Button(const QString&text,QWidget* parent = nullptr);

    void resizeEvent(QResizeEvent*e) override;

    void enableEffect();
    void disableEffect();
signals:
};

#endif // BUTTON_H
