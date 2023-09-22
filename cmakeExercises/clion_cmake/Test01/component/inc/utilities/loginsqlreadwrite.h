#ifndef LOGINSQLREADWRITE_H
#define LOGINSQLREADWRITE_H

#include <QtSql>
#include "dialog.h"
#include "../public.h"
#include "sqlstatements.h"
#include "sqlreadwrite.h"
#include "encry.h"

struct COMPONENT_IMEXPORT DBConfig{
    QString dbname;
    QString username;
    QString password;
    QString ip;
    QString port;
};

Q_DECLARE_METATYPE(DBConfig);

class LoginSqliteReadWrite;
class LoginMysqlReadWrite;

class COMPONENT_IMEXPORT LoginSqlReadWrite : public QObject
{
    Q_OBJECT
protected:
     QString mCurrentUser; // 方便validatePwd使用,验证好用户后就保存在这里给其使用,否则外部还要传递用户名进来
     QString mCurrentPwd;
    public:
        // 对外的6个接口,内部调用的是子类重实现的虚函数
        explicit LoginSqlReadWrite(QObject*parent = nullptr);
        bool open(QCVariant param);
        bool validateDB(QCVariant param);
        bool validateUser(QCString user);
        bool validatePwd(QCString pwd);
        bool createUser(QCString user,QCString pwd); // 创建用户
        bool updatePwd(QCString user,QCString pwd); // 更新密码
        virtual SQLType type() const = 0;
        virtual ~LoginSqlReadWrite(){}
private:
        virtual bool openDB(QCVariant param) = 0;
        virtual bool dbExisted(QCVariant param) = 0;
        virtual bool userExisted(QCString user) = 0;
        virtual bool pwdExisted(QCString pwd) = 0;
        virtual bool userCreated(QCString user,QCString pwd) = 0;
        virtual bool pwdUpdated(QCString user,QCString pwd) = 0;

        virtual bool haveUser(QCString user) = 0;
        virtual bool havePwd(QCString user,QCString pwd) = 0;
        virtual QString encryUser(QCString user) = 0;
signals:
        void validateDBStarted();
        void validateDBFinished();
};


#endif // LOGINSQLREADWRITE_H
