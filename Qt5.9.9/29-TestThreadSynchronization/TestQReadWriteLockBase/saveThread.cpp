#include "saveThread.h"
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QCoreApplication>
extern QQueue<int> buffer;
extern QReadWriteLock Lock; // 全局读写锁
// 改用基于读写操作的锁,这样2个读线程可以同时使用lockForRead不要排队也不会造成阻塞,它只会在写操作时才会阻塞
// 这里的代码是读线程

void saveThread::run()
{
    isSave = true;
    QReadLocker Locker(&Lock);

    QDir currDir = QDir::current();
    currDir.cdUp();
    currDir.cd("TestQReadWriteLockBase");
    qDebug()<<currDir.path();
    QString filename = currDir.path()+"/save.txt";
    QFile aFile(filename);

    if (!aFile.exists())
    {
        aFile.setFileName(filename);
        qDebug()<<"创建文件成功";
    }

    if (!aFile.open(QIODevice::Text| QIODevice::WriteOnly| QIODevice::Append))
    {
        QMessageBox::critical(nullptr,"错误","save.txt打开失败!");
        return;
    }

    int i  = 0;

    QTextStream out(&aFile); // 绑定输入流
    out.setAutoDetectUnicode(true);
    for(i = pos; i < buffer.size(); ++i) // 从暂停位置开始保存
    {
        if (!isSave)
        {
            this->pos = i ;//更新暂停保存位置
            emit saveValue(-2); // 暂停保存
            break;
        }
        emit saveValue(buffer[i]);
        out<<"The "<<i<<"-th data saved is "<<buffer[i]<<"\n";
        msleep(50);
    }
    if (i == buffer.size()) emit saveValue(-1) ; // 没有新数据可以保存
    this->pos = i;
    qDebug()<<"pos = "<<pos;
    aFile.close();
    quit();
}

void saveThread::stopSave()
{
    this->isSave= false;
}

// 把文件保存的内容也清空
void saveThread::reset()
{
    this->isSave = false;
    this->pos = 0;

    QDir currDir = QDir::current();
    currDir.cdUp();
    currDir.cd("TestQReadWriteLockBase");
    qDebug()<<currDir.path();
    QString filename = currDir.path()+"/save.txt";
    QFile aFile(filename);
    if (!aFile.open(QIODevice::Text| QIODevice::WriteOnly| QIODevice::Truncate))
    {
        QMessageBox::critical(nullptr,"错误","save.txt清空失败!");
        return;
    }
    aFile.close();
}
saveThread::saveThread()
{
    pos = 0;
}
