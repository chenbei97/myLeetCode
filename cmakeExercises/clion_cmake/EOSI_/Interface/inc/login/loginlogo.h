#ifndef LOGINLOGO_H
#define LOGINLOGO_H

#include "../../../include/widgets/label.h"
#include "../../../include/widgets/lcdtimeshow.h"
#include "../../../include/widgets/label.h"

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
