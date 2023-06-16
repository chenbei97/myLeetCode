#include <QCoreApplication>
#include <QQmlEngine>
#include <QQuickItem>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QQmlEngine engine;
    QQmlComponent component(&engine,
                 QUrl::fromLocalFile("../myqmlcomponent/main.qml"));
    QObject *myObject = component.create();
    QQuickItem *item = qobject_cast<QQuickItem*>(myObject);
    qreal width = item->width();
    qDebug() << width;

    return a.exec();
}
