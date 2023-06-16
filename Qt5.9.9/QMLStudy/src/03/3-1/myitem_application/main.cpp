#include <QGuiApplication>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView *view = new QQuickView;


    // 方式一：直接使用本地的main.qml文件
    view->setSource(QUrl::fromLocalFile("../myitem_application/main.qml"));


    // 方式二：因为在.pro文件中将main.qml指定为了resources.files，所以也可以作为资源文件使用
    //view->setSource(QUrl("qrc:/myitem_application/main.qml"));


    view->show();

    return app.exec();
}
