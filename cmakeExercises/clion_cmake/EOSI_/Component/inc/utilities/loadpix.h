#ifndef LOADPIX_H
#define LOADPIX_H

#include "QtConcurrent"
#include "qeventloop.h"
#include "qpixmap.h"
#include "qimagereader.h"
#include "../public.h"
/*
 *
 *  直接加载一般是最慢的
 *  通过imageReader比较实质,加载的是缩放之后的Size,不是先加载再缩放
 *  concurrent对于单图没有imageReader快，多图明显快，需要带事件循环loop才能打印时间
 *  mapped加载需要传入的必须是带迭代器的，所以单图的话内部还必须先转换，同时返回结果只能拿到1个，无法统计真实时间
 *  blockingmapped 可以直接得到列表图像，多图比mapped快，单图慢
loadPixmapDirect time =  34  ms
loadPixmapByImageReader time =  7  ms
loadPixmapByConcurrent time =  15  ms √
loadPixmapByConcurrentMapped time =  0  ms  x
loadPixmapByConcurrentBlockingMapped time =  15  ms √

loadPixmapsDirect time =  213  ms
loadPixmapsByImageReader time =  164  ms
loadPixmapsByConcurrent time =  30  ms √
loadPixmapsByConcurrentMapped time =  249  ms x
loadPixmapsByConcurrentBlockingMapped time =  70  ms
总结： 多图使用concurrent，单图concurrent或mappedblocking均可，但平均来看，单次可能concurrent更容易短
*/


static QTime loadPixTimer;

#define PrintLoadPixTime (qDebug()<<__FUNCTION__<<"time = "<<loadPixTimer.elapsed()<<" ms" )

static QPixmap loadPixmapDirect(const QString& imgpath, qreal scale_w, qreal scale_h)
{
    loadPixTimer.start();
    auto pix = QPixmap(imgpath);
    auto p = pix.scaled(scale_w,scale_h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    PrintLoadPixTime;
    return p;
}

static QPixmap loadPixmapDirect(const QString& imgpath, const QSize& targetsize)
{
    auto w = targetsize.width();
    auto h = targetsize.height();
    return loadPixmapDirect(imgpath,w,h);
}

static QPixmap* loadPixmapPointerDirect(const QString& imgpath, qreal scale_w, qreal scale_h)
{
    loadPixTimer.start();
    auto pix = QPixmap(imgpath);
    auto p = pix.scaled(scale_w,scale_h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    PrintLoadPixTime;
    return new QPixmap(p);
}

static QPixmap* loadPixmapPointerDirect(const QString& imgpath, const QSize& targetsize)
{
    auto w = targetsize.width();
    auto h = targetsize.height();
    return loadPixmapPointerDirect(imgpath,w,h);
}

static QList<QPixmap> loadPixmapsDirect(const QStringList& files, qreal scale_w, qreal scale_h)
{
    loadPixTimer.start();
    QList<QPixmap> pixs;
    foreach(auto file,files) {
        auto pix = QPixmap(file);
        auto p = pix.scaled(scale_w,scale_h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        pixs.append(p);
    }

    PrintLoadPixTime;
    return pixs;
}

static QList<QPixmap> loadPixmapsDirect(const QStringList& files, const QSize&s)
{
    return  loadPixmapsDirect(files,s.width(),s.height());
}

static QPixmap loadPixmapByImageReader(const QString& imgpath, qreal scale_w, qreal scale_h)
{
    loadPixTimer.start();
    QImageReader reader;
    reader.setFileName(imgpath);
    reader.setAutoTransform(true); // reader.read()会自动进行元数据转换

    auto source_size = reader.size();
    auto target_size = source_size.scaled(scale_w,scale_h,Qt::KeepAspectRatio); // 原尺寸=>目标尺寸的保持纵横比尺寸

    reader.setScaledSize(target_size);
    auto pix = QPixmap::fromImageReader(&reader);
    PrintLoadPixTime;
    return pix;
}

static QPixmap loadPixmapByImageReader(const QString& imgpath, const QSize& targetsize)
{
    auto w = targetsize.width();
    auto h = targetsize.height();
    return  loadPixmapByImageReader(imgpath,w,h);
}

static QPixmap* loadPixmapPointerByImageReader(const QString& imgpath, qreal scale_w, qreal scale_h)
{
    loadPixTimer.start();
    QImageReader reader;
    reader.setFileName(imgpath);
    reader.setAutoTransform(true); // reader.read()会自动进行元数据转换

    auto source_size = reader.size();
    auto target_size = source_size.scaled(scale_w,scale_h,Qt::KeepAspectRatio); // 原尺寸=>目标尺寸的保持纵横比尺寸

    reader.setScaledSize(target_size);
    auto pix = new QPixmap(QPixmap::fromImageReader(&reader));
    PrintLoadPixTime;
    return pix;
}

static QPixmap* loadPixmapPointerByImageReader(const QString& imgpath, const QSize& targetsize)
{
    auto w = targetsize.width();
    auto h = targetsize.height();
    return  loadPixmapPointerByImageReader(imgpath,w,h);
}

static QList<QPixmap> loadPixmapsByImageReader(const QStringList& files, qreal w, qreal h)
{
    loadPixTimer.start();

    QImageReader reader;
    reader.setAutoTransform(true); // reader.read()会自动进行元数据转换

    QList<QPixmap> pixs;
    foreach(auto file,files) {
        reader.setFileName(file);
        auto source_size = reader.size();
        auto target_size = source_size.scaled(w,h,Qt::KeepAspectRatio);
        reader.setScaledSize(target_size);
        auto pix = QPixmap::fromImageReader(&reader);
        pixs.append(pix);
    }
    PrintLoadPixTime;
    return pixs;
}

static QList<QPixmap> loadPixmapsByImageReader(const QStringList& files,const QSize&s)
{
    return loadPixmapsByImageReader(files,s.width(),s.height());
}

static QPixmap loadPixmapByConcurrent(const QString&file,qreal w,qreal h)
{
    auto func = [=] ()->QPixmap{
        auto pix = QPixmap(file);
        auto p = pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        return p;
    };

    QEventLoop loop; // 用于同步子线程
    QFutureWatcher<QPixmap> watcher ; // 用于监控异步计算的类
    QObject::connect(&watcher,&QFutureWatcher<QPixmap>::started,[&]{loadPixTimer.start();});
    //QObject::connect(&watcher,&QFutureWatcher<QPixmap>::finished,[&]{PrintLoadPixTime;});
    QObject::connect(&watcher,&QFutureWatcher<QPixmap>::finished,&loop,&QEventLoop::quit);

    watcher.setFuture(QtConcurrent::run(func));
    loop.exec();
    PrintLoadPixTime;
    auto pix = watcher.future().result(); // 同步后拿到结果,不然子线程直接退出了
   // while (!watcher->isFinished()) qApp->processEvents(QEventLoop::AllEvents, 5);
//    if (watcher->isFinished()) {
//        PrintLoadPixTime;
//    }
    return pix;
}

static QPixmap loadPixmapByConcurrent(const QString&file,const QSize&s)
{
    return loadPixmapByConcurrent(file,s.width(),s.height());
}

static QPixmap* loadPixmapPointerByConcurrent(const QString&file,qreal w,qreal h)
{
    auto func = [=] ()->QPixmap*{
        auto pix = QPixmap(file);
        auto p = pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        return new QPixmap(p);
    };

    QEventLoop loop; // 用于同步子线程
    QFutureWatcher<QPixmap*> watcher ; // 用于监控异步计算的类
    QObject::connect(&watcher,&QFutureWatcher<QPixmap*>::started,[&]{loadPixTimer.start();});
    //QObject::connect(&watcher,&QFutureWatcher<QPixmap>::finished,[&]{PrintLoadPixTime;});
    QObject::connect(&watcher,&QFutureWatcher<QPixmap*>::finished,&loop,&QEventLoop::quit);

    watcher.setFuture(QtConcurrent::run(func));
    loop.exec();
    PrintLoadPixTime;
    auto pix = watcher.future().result(); // 同步后拿到结果,不然子线程直接退出了
   // while (!watcher->isFinished()) qApp->processEvents(QEventLoop::AllEvents, 5);
//    if (watcher->isFinished()) {
//        PrintLoadPixTime;
//    }
    return pix;
}

static QPixmap* loadPixmapPointerByConcurrent(const QString&file,const QSize&s)
{
    return loadPixmapPointerByConcurrent(file,s.width(),s.height());
}

static QList<QPixmap> loadPixmapsByConcurrent(const QStringList&files,qreal w,qreal h)
{
    auto func = [=] (const QString&file)->QPixmap{
        auto pix = QPixmap(file);
        auto p = pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        return p;
    };

    QEventLoop loop; // 用于同步子线程
    QFutureWatcher<QPixmap> watcher ; // 用于监控异步计算的类
    QObject::connect(&watcher,&QFutureWatcher<QPixmap>::started,[&]{loadPixTimer.start();});
    QObject::connect(&watcher,&QFutureWatcher<QPixmap>::finished,&loop,&QEventLoop::quit);

    QList<QPixmap> pixs;
    foreach(auto file,files) {
        watcher.setFuture(QtConcurrent::run(func,file));
        loop.exec();
        //PrintLoadPixTime;
        auto pix = watcher.future().result();
        pixs.append(pix);
    }
    PrintLoadPixTime;
    return pixs;
}

static QList<QPixmap> loadPixmapsByConcurrent(const QStringList&files,const QSize&s)
{
    return loadPixmapsByConcurrent(files,s.width(),s.height());
}

static QPixmap loadPixmapByConcurrentMapped(const QString& file,int w,int h)
{ //  必须用std::function转换,否则future是QFuture<void>类型
    std::function<QPixmap(const QString &)> func =  [=] (const QString &file) -> QPixmap{
        auto pix = QPixmap(file);
        auto p = pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        return p;
   };
    QStringList files = {file};
    loadPixTimer.start();
    auto future  = QtConcurrent::mapped(files.begin(),files.end(),func);
    PrintLoadPixTime;
    return future.result();
}

static QPixmap loadPixmapByConcurrentBlockingMapped(const QString& file,int w,int h)
{ //  必须用std::function转换,否则future是QFuture<void>类型
    std::function<QPixmap(const QString &)> func =  [=] (const QString &file) -> QPixmap{
        auto pix = QPixmap(file);
        auto p = pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        return p;
   };
    loadPixTimer.start();
    QStringList files= {file};
    auto future  = QtConcurrent::blockingMapped(files,func); // 阻塞型可以直接得到结果
    PrintLoadPixTime;
    return future[0]; // 只有1个图
}

static QPixmap loadPixmapByConcurrentMapped(const QString& file,const QSize&s)
{
    return loadPixmapByConcurrentMapped(file,s.width(),s.height());
}

static QPixmap loadPixmapByConcurrentBlockingMapped(const QString& file,const QSize&s)
{
    return loadPixmapByConcurrentBlockingMapped(file,s.width(),s.height());
}

static QList<QPixmap> loadPixmapsByConcurrentMapped(const QStringList files,int w,int h)
{
    std::function<QPixmap(const QString &)> func =  [=] (const QString &file) -> QPixmap{
        auto pix = QPixmap(file);
        auto p = pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        return p;
   };

    QList<QPixmap> pixs; // mapped只能获取单个结果,只能借助多次来计算多个图片
    loadPixTimer.start();
    foreach (auto file,files) {
        auto future = QtConcurrent::mapped(QStringList(file),func);
        pixs.append(future.result());
    }
    PrintLoadPixTime;
    return pixs;
}

static QList<QPixmap> loadPixmapsByConcurrentBlockingMapped(const QStringList& files,int w,int h)
{
    std::function<QPixmap(const QString &)> func =  [=] (const QString &file) -> QPixmap{
        auto pix = QPixmap(file);
        auto p = pix.scaled(w,h,Qt::KeepAspectRatio,Qt::SmoothTransformation);
        return p;
   };
    loadPixTimer.start();
    auto future = QtConcurrent::blockingMapped(files,func);
    PrintLoadPixTime;
    return future;
}

static QList<QPixmap> loadPixmapsByConcurrentMapped(const QStringList files,const QSize&s)
{
    return loadPixmapsByConcurrentMapped(files,s.width(),s.height());
}

static QList<QPixmap> loadPixmapsByConcurrentBlockingMapped(const QStringList& files,const QSize&s)
{
    return loadPixmapsByConcurrentBlockingMapped(files,s.width(),s.height());
}

#endif // LOADPIX_H
