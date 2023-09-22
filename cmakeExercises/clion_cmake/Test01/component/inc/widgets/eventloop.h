#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include "../public.h"

class COMPONENT_IMEXPORT EventLoop : public QObject
{
    Q_OBJECT
private:
    QEventLoop loop;
public:
    explicit EventLoop(QObject *parent = nullptr);
public slots:
    void quit();
    void exec();
signals:
    void started();
};
#endif // EVENTLOOP_H
