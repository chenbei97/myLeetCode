#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QDebug>

class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged )
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged )
private:
    QString mName;
    quint32 mAge;
public:
    Person();
    Person(QString name,quint32 age);
    Q_INVOKABLE void  printInfo() const noexcept; // 声明为qml可用的函数

    QString name() const;
    void setName(QString name);

    quint32 age() const;
    void setAge(quint32  age) ;
signals:
    void nameChanged(QString);
    void ageChanged(quint32);
public slots:
    void print() const noexcept;
    void printinfo(bool) const noexcept;
};

#endif // PERSON_H
