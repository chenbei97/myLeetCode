//
// Created by chenbei on 2023/9/20.
//

#ifndef TEST01_LABEL_H
#define TEST01_LABEL_H

#include <QLabel>
#include "public.h"

class Label : public QLabel
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


#endif //TEST01_LABEL_H
