#ifndef LOGINVERIFYDB_H
#define LOGINVERIFYDB_H

#include "../../../include/utilities/dialog.h"
#include "../../../include/widgets/lineedit.h"
#include "../../../include/widgets/pushbutton.h"
#include "../../../include/utilities/loginmysqlreadwrite.h"
#include "../../../include/utilities/loginsqlitereadwrite.h"

class LoginVerifyDB : public QDialog
{
    Q_OBJECT
public:
    explicit LoginVerifyDB(QWidget*parent = nullptr);

    void updateState();

    QString dbName() const;
private:
    QVBoxLayout * mLay;

    PushButton * mVerifyBtn;
    PushButton * mCancelBtn;

    LineEdit * mDatabaseName;
    LineEdit * mUserName;
    LineEdit * mPassWord;
    LineEdit * mIPAddress;
    LineEdit * mPort;
private slots:
     void onVerifyBtn();
};

#endif // LOGINVERIFYDB_H
