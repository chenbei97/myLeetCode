#ifndef SCANJSONREADWRITE_H
#define SCANJSONREADWRITE_H

#include "../../../include/utilities/jsonreadwrite.h"

class ScanJsonReadWrite : public JsonReadWrite
{
    Q_OBJECT
public:
    explicit ScanJsonReadWrite(QObject *parent = nullptr);
    void parseSpecialObject(const QJsonValue &key,const QJsonValue &value) override;
};
#endif // SCANJSONREADWRITE_H
