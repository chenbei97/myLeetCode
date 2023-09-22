#ifndef LOGINNEWUSER_H
#define LOGINNEWUSER_H

#include "widgets/pushbutton.h"
#include "widgets/lineedit.h"
#include "qvalidator.h"
#include "qregexp.h"
#include "loginverifydb.h"

class LoginNewUser : public QDialog
{
    Q_OBJECT
public:
    explicit LoginNewUser(QWidget*parent=nullptr);
    void updateState();
private:
    QVBoxLayout * mLay;
    PushButton * mNewBtn;
    LineEdit * mUserEdit;
    LineEdit * mPwdEdit;
    LineEdit * mVerifyPwdEdit;
    void init();
    void onUserEditFinished();
    void onPwdEditFinished();
    void onVerifyPwdEditFinished();
    void onNewBtn();
private:
    bool userIsRight;
    bool pwdIsRight;
    bool pwdIsSame;
};

#endif // LOGINNEWUSER_H
