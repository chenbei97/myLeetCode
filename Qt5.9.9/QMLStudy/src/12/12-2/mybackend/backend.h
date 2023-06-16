#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>

#include <QtQml/qqmlregistration.h> // 添加头文件


class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName
               NOTIFY userNameChanged)

    QML_ELEMENT // 添加宏

public:
    explicit BackEnd(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
};

#endif // BACKEND_H
