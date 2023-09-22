#ifndef LOGINMODIFYPWD_H
#define LOGINMODIFYPWD_H

#include "widgets/pushbutton.h"
#include "widgets/lineedit.h"
#include "widgets/label.h"
#include "loginverifydb.h"

class LoginModifyPwd : public QDialog
{
    Q_OBJECT
public:
    explicit LoginModifyPwd(QWidget*parent = nullptr);
    void updateState();

    void setCurrentUser(const QString&user);
    QString lastModifiedUser() const;
private:
    PushButton * mModifyBtn;
    LineEdit * mUserEdit;
    LineEdit * mOldPwdEdit;
    LineEdit * mNewPwdEdit;
    Label * mShowInfo;
    QVBoxLayout * mLay;
    void init();
    void onUserEditFinished();
    void onOldPwdEditFinished();
    void onNewPwdEditFinished();
    void onModifyBtn();
private:
    bool userIsRight;
    bool oldpwdIsRight;
    bool newpwdIsRight;
    void setShowInfo();
    QString mModifyUser;
};

#endif // LOGINMODIFYPWD_H
