#include "myCustomStruct.h"
#include <QVariant>
#include <string.h>

MyCustomStruct::MyCustomStruct(){
     this->id = 0;
    this->data = 0;
    this->name = "";
}

MyCustomStruct::MyCustomStruct(const int id,float data,QString name):
    id(id),data(data)
{
    this->name = name;
}

MyCustomStruct::MyCustomStruct(const MyCustomStruct &rhs)
{
    this->data = rhs.data;
    this->id = rhs.id;
    this->name = rhs.name;
}
MyCustomStruct:: ~MyCustomStruct()
{

}
//Q_DECLARE_METATYPE(MyCustomStruct<char*>)
//Q_DECLARE_METATYPE(MyCustomStruct<const char*>)
// QVaiant 不能识别自定义类型和其他非 QMetaType 内置类型
// 需要使用 Q_DECLARE_METATYPE 宏对 MyCustomStruct进行声明
// qRegisterMetaType 将某类型注册中 MetaType 系统中,并返回这个类型的新id
//    int id = qRegisterMetaType<MyCustomStruct<int>>();
//    qDebug()<<"id = "<<id;
