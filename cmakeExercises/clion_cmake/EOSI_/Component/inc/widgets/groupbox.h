#ifndef GROUPBOX_H
#define GROUPBOX_H

#include "qgraphicseffect.h"
#include "qgroupbox.h"
#include "qpropertyanimation.h"
#include "../public.h"

class COMPONENT_IMEXPORT GroupBox : public QGroupBox
{
    Q_OBJECT
private:
    QGraphicsOpacityEffect * mEffect;
    QPropertyAnimation * mAnimation;
    bool mEffectSwitch;
public:
    explicit GroupBox(QWidget*parent=nullptr);
    explicit GroupBox(const QString&title,QWidget*parent=nullptr);
    ~GroupBox();
    void enableEffect();
    void disableEffect();
    void hideEvent(QHideEvent*e) override;
    void showEvent(QShowEvent*) override;
    void resizeEvent(QResizeEvent *event) override;
signals:
    void currentSize(const QSize& size);
};

#endif // GROUPBOX_H
