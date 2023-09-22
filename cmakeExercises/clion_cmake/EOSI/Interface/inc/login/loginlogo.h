#ifndef LOGINLOGO_H
#define LOGINLOGO_H

#include "widgets/label.h"
#include "widgets/lcdtimeshow.h"
#include "widgets/label.h"

class LoginLogo : public QHBoxLayout
{
    Q_OBJECT
private:
    Label * mLogo;
    Label * mText;
    LCDTimeShow * mTime;
public:
    explicit LoginLogo();
};

#endif // LOGINLOGO_H
