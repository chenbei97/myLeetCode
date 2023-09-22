#ifndef LOGINTOOL_H
#define LOGINTOOL_H

#include "../../../include/widgets/button.h"
#include "../../../include/widgets/groupbox.h"
#include "../../../include/widgets/multilinelayout.h"
#include "../../../include/widgets/lineedit.h"
#include "../../../include/widgets/pushbutton.h"
#include "../../../include/widgets/combobox.h"
#include "../../../include/utilities/encry.h"
#include "../../../include/tcp/tcploader.h"
#include "../../../include/tcp/tcpquery.h"
#include "../../../include/tcp/tcpassemblercontroller.h"
#include "../main/initconfig.h"
#include "loginmodifypwd.h"
#include "loginnewuser.h"
#include "loginverifydb.h"
#include "qpropertyanimation.h"
#include "qvalidator.h"

#define MySqlOption "MYSQL"
#define SqliteOption "SQLITE"

class LoginTool : public QWidget
{
    Q_OBJECT

private:
    QTimer mCheckConnectedTimer;
    bool isUnexpectedExit = true;
    QVector<bool> mCanLoadMain;
public:
    explicit LoginTool(QWidget *parent = nullptr);
    void closeCheckConnectedTimer();

    QString ip() const;
    QString username() const;
    QString password() const;
    QString dbdir() const;
    QString dbtype() const;
    bool canLoadMain() const;
private:
    void initObject();
    void initSize();
    void initStyle();
    void initEffect();
    void initChildWin();
    void initConfig();
    void initLayout();
    void initConnections();
    void sendEquipmentNumberToSocket();
private slots:
    void onCheckConnectedState();
    void onAutoConnection();
    void onManualConnection();
    void onValidateUser();
    void onCreateUser();
    void onValidatePwd();
    void onModifyPwd();
    void onValidateDir();
    void changeSqlType(int idx);
    void onUserTextChanged(const QString&text);
    void onIdentifyMachine();
    void onUserName();
    void onPassWord();
    void onDbDir();
private:
    Button * mIdentifyMachineBtn;
    Button * mUserNameBtn;
    Button * mPassWordBtn;
    Button * mDbDirBtn;

    PushButton * mAutoConnectBtn;
    PushButton * mManualConnectBtn;
    LineEdit * mIPEdit;

    PushButton * mUserValidateBtn;
    PushButton * mUserCreateBtn;
    LineEdit * mUserEdit;

    PushButton * mPwdValidateBtn;
    PushButton * mPwdModifyBtn;
    PushButton * mDbDirValidateBtn;
    ComboBox * mDbTypeCombo;
    LineEdit * mPwdEdit;
    Label * mDbDirShowLab;

    GroupBox * mConnectBox;
    GroupBox * mUserBox;
    GroupBox * mPwdBox;
    GroupBox * mDbDirBox;

    Label * mValidateFlagSocket;
    Label * mValidateFlagUser;
    Label * mValidateFlagPwd;
    Label * mValidateFlagDir;

    QPixmap * mOkPix;
    QPixmap * mNotOkPix;

    MultilineLayout * mLay;

    LoginVerifyDB * mVerifyDB; // 验证数据库的对话框
    LoginModifyPwd * mModifyPwd; // 修改密码的对话框
    LoginNewUser * mNewUser; // 新建用户的对话框

signals:
    void socketConnectedState(bool isConnected);
};

#endif // LOGINTOOL_H
