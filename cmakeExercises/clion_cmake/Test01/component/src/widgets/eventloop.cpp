#include "../../inc/widgets/eventloop.h"

EventLoop::EventLoop(QObject *parent) : QObject(parent)
{

}

void EventLoop::quit()
{
    loop.quit();
    LOG<<"loop is quit";
}

void EventLoop::exec()
{
    LOG<<"loop is exec";
    emit started();
    loop.exec();
}
