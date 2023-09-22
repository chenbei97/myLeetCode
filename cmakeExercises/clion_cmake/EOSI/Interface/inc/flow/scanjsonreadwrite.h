#ifndef SCANJSONREADWRITE_H
#define SCANJSONREADWRITE_H

#include "utilities/jsonreadwrite.h"

#if defined(Q_CC_GNU) && defined(QT_DEBUG)
    #if defined(INTERFACE_LIBRARY)
    #  define INTERFACE_IMEXPORT Q_DECL_EXPORT
    #else
    #  define INTERFACE_IMEXPORT Q_DECL_IMPORT
    #endif
class  INTERFACE_IMEXPORT ScanJsonReadWrite : public JsonReadWrite
#else
    class  ScanJsonReadWrite : public JsonReadWrite
#endif
{
    Q_OBJECT
public:
    explicit ScanJsonReadWrite(QObject *parent = nullptr);
    void parseSpecialObject(const QJsonValue &key,const QJsonValue &value) override;
};
#endif // SCANJSONREADWRITE_H
