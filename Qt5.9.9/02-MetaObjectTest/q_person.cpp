#include "q_person.h"

QPerson::QPerson(QString Name,QObject *parent) : QObject(parent) // 用QObject初始化parent
{ //构造函数
    myname=Name;
}

int QPerson::getAge() // 可以被QMetaObjectTest::on_ageChanged槽函数调用反馈给QPlainTextEdit组件
{ //返回age
    return  myage;
}

void QPerson::setAge(int age_value) // 被界面的SpinBox组件调用,spinBoy和spinGril
{//设置age
    myage=age_value;
    emit ageChanged(myage); //发射信号
}

void QPerson::increaseAge() // 被界面的QPushButton组件调用,btnGirlInc和btnboyInc
{
    myage++;
    emit ageChanged(myage);//发射信号
}
