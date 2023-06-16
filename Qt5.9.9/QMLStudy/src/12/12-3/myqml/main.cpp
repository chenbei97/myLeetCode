#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QQuickItem>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // 使用QQmlComponent进行加载
    QQmlEngine engine;
    QQmlComponent component(&engine, QUrl::fromLocalFile("../myqml/main.qml"));
    QObject *object = component.create();
    // ... 进行其他操作

    object->setProperty("width", 500);
    qDebug() << object->property("width");
    QQmlProperty(object, "width").write(600);
    qDebug() << object->property("width");

    QQuickItem *item = qobject_cast<QQuickItem*>(object);
    item->setWidth(800);
    qDebug() << object->property("width");

    delete object;

    return app.exec();
}


//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include <QQuickView>
//#include <QQuickItem>

//int main(int argc, char *argv[])
//{
//    QGuiApplication app(argc, argv);

//    QQuickView view;
//    view.setSource(QUrl::fromLocalFile("../myqml/main.qml"));
//    view.show();
//    QQuickItem *object = view.rootObject();
//    object->setWidth(500);
//    qDebug() << object->width();

//    return app.exec();
//}


