#ifndef GRADIENTHIDDENWIDGET_H
#define GRADIENTHIDDENWIDGET_H

#include "label.h"
#include "qframe.h"
#include "gradienthiddenanimation.h"

class COMPONENT_IMEXPORT GradientHiddenWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GradientHiddenWidget(QWidget *parent = nullptr);
    void showEvent(QShowEvent *event) override;
    void enableEffect();
    void disableEffect();
private:
    Label * headerLabel() const;
    QFrame * horline() const;
protected:
    Label * header;
    QFrame * line;
    QVBoxLayout * mainlay;
private:
    QPropertyAnimation * animation;
    bool enabled = true;
signals:

};

#endif // GRADIENTHIDDENWIDGET_H
