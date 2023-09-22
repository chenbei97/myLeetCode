#ifndef JSONREADWRITE_H
#define JSONREADWRITE_H

#include "qjsonarray.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "path.h"
#include "../public.h"

class COMPONENT_IMEXPORT JsonReadWrite : public QObject
{
    Q_OBJECT
public:
    explicit JsonReadWrite(QObject *parent = nullptr);
    QByteArray readJson(const QString&path);

    void parseJson(const QByteArray&json);

    void writeJson(const QString&path,const QJsonObject&object);
    void writeJson(const QString&path,const QJsonArray&array);
    void writeJson(const QString&path,const QByteArray&json);

    QVariantMap map() const;
    QVariantList list() const;
private:
    void parseObject(const QJsonObject& object);
    void parseArray(const QJsonArray& array);
protected:
    void setSpecialObjectKeys(const QStringList& keys);
    virtual void parseSpecialObject(const QJsonValue &key,const QJsonValue &value);
    QStringList specialObjectKeys;
    QVariantMap parseData;
    QVariantList constantData;
signals:

};

#endif // JSONREADWRITE_H
