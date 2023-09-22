#ifndef LOGINSQLITEREADWRITE_H
#define LOGINSQLITEREADWRITE_H

#include "loginsqlreadwrite.h"
#include "sqlitereadwrite.h"

class COMPONENT_IMEXPORT LoginSqliteReadWrite : public LoginSqlReadWrite
{
public:
    QString mSqliteDir; // sqlite可以指定保存目录
    SQLType type() const override;// 返回数据库类型
    virtual bool openDB(QCVariant param) override;
    virtual bool dbExisted(QCVariant param) override;
    virtual bool userExisted(QCString user) override;
    virtual bool pwdExisted(QCString pwd) override;
    virtual bool userCreated(QCString user,QCString pwd) override;
    virtual bool pwdUpdated(QCString user,QCString pwd) override;
    virtual bool haveUser(QCString user) override;
    virtual bool havePwd(QCString user,QCString pwd) override;
    virtual QString encryUser(QCString user) override;
    static LoginSqliteReadWrite& instance();
private:
    LoginSqliteReadWrite();
};

#endif // LOGINSQLITEREADWRITE_H
