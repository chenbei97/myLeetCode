#ifndef LOGINMYSQLREADWRITE_H
#define LOGINMYSQLREADWRITE_H

#include "loginsqlreadwrite.h"
#include "mysqlreadwrite.h"

class COMPONENT_IMEXPORT LoginMysqlReadWrite : public LoginSqlReadWrite
{
public:
    /*mysql 默认路径在C:\ProgramData\MySQL\MySQL Server 8.0\Data,且在my.ini的datadir字段已经设置好,所以才能不需完整路径就打开对应表*/
    virtual SQLType type() const override;
    virtual bool openDB(QCVariant param) override;
    virtual bool dbExisted(QCVariant param) override;
    virtual bool userExisted(QCString user) override;
    virtual bool pwdExisted(QCString pwd) override;
    virtual bool userCreated(QCString user,QCString pwd) override;
    virtual bool pwdUpdated(QCString user,QCString pwd) override;
    virtual bool haveUser(QCString user) override;
    virtual bool havePwd(QCString user,QCString pwd) override;
    virtual QString encryUser(QCString user) override;
    static LoginMysqlReadWrite& instance();
private:
    LoginMysqlReadWrite();
};

#endif // LOGINMYSQLREADWRITE_H
