#include "person.h"

Person::Person()
{

}

Person::Person(QString name,quint32 age): mName(name),mAge(age)
{

}

void Person::printInfo() const noexcept
{
        qDebug()<<"Q_INVOKABLE:   name = "<<mName<<" age = "<<mAge;
}

void Person::print() const noexcept
{
        qDebug()<<"SLOT:   name = "<<mName<<" age = "<<mAge;
}

void Person::printinfo(bool r) const noexcept
{
        qDebug()<<"SLOT:   name = "<<mName<<" age = "<<mAge;
        Q_UNUSED(r);
}

QString Person::name() const
{
    return mName;
}

void Person::setName(QString name)
{
    mName = name;
}

quint32 Person::age() const
{
    return mAge;
}

void Person::setAge(quint32  age)
{
    mAge    = age;
}
