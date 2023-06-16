#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QPushButton>

#include "person.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Person p("chenbei",26); // 实例化

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QQmlContext* context = engine.rootContext();
    context->setContextProperty("ChenBei",&p); //注册一个名字,现在main.qml就可以使用"ChenBei"了

    QList<QObject*> root = engine.rootObjects();
    qDebug()<<"root's size = "<<root.size();
    auto btn3 =root.first()->findChild<QObject*>("btn3");
    if (btn3 == nullptr) qDebug()<<" dont find btn3";
    else {
        qDebug()<<btn3->metaObject()->className(); // Button_QMLTYPE_0
        //auto btn = (QPushButton*)(btn3);

        QObject::connect(btn3,SIGNAL(clicked()),&p,SLOT(print())); // 用宏可以
        //QObject::connect(btn3,static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked),&p,&Person::printinfo); //这样不行
    }

    return app.exec();
}
