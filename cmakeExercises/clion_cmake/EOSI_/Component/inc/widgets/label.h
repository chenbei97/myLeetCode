#ifndef LABEL_H
#define LABEL_H

#include "qlabel.h"
#include "qgraphicseffect.h"
#include "qpropertyanimation.h"
#include "../public.h"

class COMPONENT_IMEXPORT Label : public QLabel
{
    Q_OBJECT
private:
    QGraphicsOpacityEffect * mEffect;
    QPropertyAnimation * mAnimation;
    bool mEffectSwitch;
    bool mPressEvent;
    QString mWarningInfo;
public:
    explicit Label(QWidget*parent=nullptr);
    explicit Label(const QString&text,QWidget*parent=nullptr);

    void setWaringInfo(const QString&info);
    QString warningInfo() const;

    ~Label();

    void enableEffect();
    void disableEffect();
    void mousePressEvent(QMouseEvent *e) override;

    void enablePressEvent();
    void disablePressEvent();
    void showEvent(QShowEvent*) override;

};

#endif // LABEL_H
