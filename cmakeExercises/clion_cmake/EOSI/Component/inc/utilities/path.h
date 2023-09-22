#ifndef PATH_H
#define PATH_H

#include "qstandardpaths.h"
#include "qdir.h"

static QString appDataStandardPath() noexcept
{
    return QStandardPaths::standardLocations(QStandardPaths::DataLocation).at(0);
}

static QString getAppDataStandardPath(const QString& filename) noexcept
{
    return appDataStandardPath()+"/"+filename;
}

static bool pathExisted(const QString& path) noexcept
{
    QDir dir;
    if (dir.exists(path))
        return true;
    return false;
}

static bool appDataStandardPathExisted() noexcept
{
    auto appdataPath = appDataStandardPath();
    return pathExisted(appdataPath);
}

static bool createPath(const QString& path) noexcept
{
     QDir dir;
     dir.mkpath(path);
     return pathExisted(path);
}

#define  CheckAndCreateStandardPath   {if (!appDataStandardPathExisted()) \
                        createPath(appDataStandardPath());}

#endif // PATH_H
