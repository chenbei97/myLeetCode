﻿#ifndef LOGINNEXT_H
#define LOGINNEXT_H

#include "widgets/label.h"
#include "widgets/pushbutton.h"

class LoginNext: public QHBoxLayout
{
    Q_OBJECT
private:
    PushButton * mBtn;
    Label * mMachineInfo;
public:
    explicit LoginNext();
    void updateMachineInfo(bool isConnected);
signals:
    void clicked();
};

#endif // LOGINNEXT_H
