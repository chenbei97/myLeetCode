#include <QCoreApplication>
#include <QStorageInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
        if (storage.isValid() && storage.isReady()) {
            if (!storage.isReadOnly()) {
                qDebug()<<"rootPath() = "<<storage.rootPath()
                               <<"  bytesAvailable() = "<<storage.bytesAvailable()
                               <<"  bytesFree() = "<<storage.bytesFree()
                               <<"  bytesTotal() = "<<storage.bytesTotal()
                                <<"  blockSize() = "<<storage.blockSize()
                                <<"  device() = "<<storage.device()
                                <<"  subvolume() = "<<storage.subvolume()
                                <<"  displayName() = "<<storage.displayName()
                                <<"  name() = "<<storage.name()
                                <<"  rootPath() = "<<storage.rootPath()
                                <<"  isRoot() = "<<storage.isRoot();
            }
        }
    }
    return a.exec();
}
