#ifndef SQLITEREADWRITE_H
#define SQLITEREADWRITE_H

#include "sqlreadwrite.h"
#include "path.h"

class COMPONENT_IMEXPORT SqliteReadWrite : public SqlReadWrite
{
    Q_OBJECT
public:
    static SqliteReadWrite& instance();
    bool open(QCString db,QCString path = QString());
    bool haveDataSource(QCString source,QCString path = QString());
    bool createDataSource(QCString source,QCString path = QString());
    bool dropDataSource(QCString source,QCString path = QString());
    virtual QDateTime lastVisitTime(QCString table = "") override;
    virtual QDateTime lastUpdateTime(QCString table = "") override;
    virtual QDateTime createTime(QCString table = "") override;
private:
    explicit SqliteReadWrite(QObject*parent = nullptr);
    ~SqliteReadWrite();
    QString mStandardPath;
};


#endif // SQLITEREADWRITE_H
