#include "qmetaobjecttest.h"
#include "ui_qmetaobjecttest.h"
#include <iostream>
#include  <string>
#include    <QMetaProperty>
#include <QDebug>

// 构造函数
QMetaObjectTest::QMetaObjectTest(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::QMetaObjectTest)
{
    ui->setupUi(this);
    this->initProperty();
    this->initConnect();
    qDebug()<<"here";
}

void QMetaObjectTest :: initProperty()// 初始化一些性质
{
       // 可以设定Q_PROPERTY已宏定义过的属性age,name和score
      this->boy = new QPerson("cb"); // 构造函数自动关联可了私有属性myname,而myname宏定义中关联了name属性是其member
      this->boy->setAge(20); // 方式1使用成员函数设置属性
      this->boy->setProperty("age",25);// 方式2使用继承的成员函数设置属性,因为age声明为READ和WRITE兼具
      this->boy->setProperty("score",100);// score同理
      this->boy->setProperty("sex","Boy"); // 设置宏定义没出现过的是动态属性
      this->boy->setProperty("isBoy",true);
      this->girl = new QPerson("baby");
      this->girl->setProperty("score",60);
      this->girl->setProperty("age",27);
      this->girl->setProperty("sex","Girl");//动态属性
      this->girl->setProperty("isBoy",false);

}
void QMetaObjectTest:: initConnect()// 初始化信号连接
{
   // 1.连接boy,girl自定义过的信号和this的自定义槽函数,也就是信号和槽函数可以不在一起定义
  // 此函数内部通过元对象的sender()函数获取了指向发射者的指针,用其信息反馈给QPlainTextEdit
   connect(this->boy,&QPerson::ageChanged,this,&QMetaObjectTest::ageChanged_boy); // 因为此函数没有重载版本,允许函数指针方式调用
   connect(this->girl,&QPerson::ageChanged,this,&QMetaObjectTest::ageChanged_girl);
//     connect(this->boy,SIGNAL(ageChanged(int)),this,SLOT(on_ageChanged(int))); // 或者用宏来声明带参数也可以
//    connect(this->girl,SIGNAL(ageChanged(int)),this,SLOT(on_ageChanged(int)));

    // 2. 连接spinbox组件的自带信号和自定义的槽函数
      //  不能使用此形式，因为QSpinBox有两种参数形式的valueChanged()信号,所以不能使用函数指针
      //  connect(ui->spinGirl,&QSpinBox::valueChanged,this,&QMetaObjectTest::on_spinBoy_valueChanged);
       connect(this->ui->spinGirl,SIGNAL(valueChanged(int)),this,SLOT(spinGirl_valueChanged(int)));
       connect(this->ui->spinBoy,SIGNAL(valueChanged(int)),this,SLOT(spinBoy_valueChanged(int)));

       // 3. 4个QPushButton组件的信号和槽函数都是原生的所以无需手动connect
}

// 自定义槽函数,接收来自QPerson类定义的信号,用于反馈影响QPlainTextEdit组件
// 内部使用sender()技术和qobejct_cast<T>类型投射,就可以获取发射信号指针对象的信息了
void QMetaObjectTest::ageChanged(int age_value)  // 响应QPerson的ageChanged()信号
{
    Q_UNUSED(age_value); // 声明此变量不被使用
    QPerson *aPerson = qobject_cast<QPerson *>(sender()); //类型投射,获取指向发射信号的指针,其实就是boy和girl
    QString hisName=aPerson->property("name").toString(); // 获取姓名
    QString hisSex=aPerson->property("sex").toString(); //动态属性获取
    // int hisAge=aPerson->getAge();//通过接口函数也可以获取年龄
    int hisAge=aPerson->property("age").toInt();//通过属性获得年龄
    int hisScore = aPerson->property("score").toInt();
    bool isBoy = aPerson->property("isBoy").toBool();
    this->ui->plainTextEdit->appendPlainText("姓名="+hisName+","+"性别="+hisSex
                               +QString::asprintf(",年龄=%d,分数=%d,isBoy=%d",hisAge,hisScore,isBoy)); // 文本打印信息
}
void QMetaObjectTest::ageChanged_girl( int age_value)// 用于girl和boy调用,减少重复代码
{
   this->ageChanged(age_value);
}
void QMetaObjectTest::ageChanged_boy( int age_value)
{
   this->ageChanged(age_value);
}


// 连接spinbox组件的自带信号和自定义的槽函数
// 减少重复代码的函数,被下边2个实际的槽函数调用
QSpinBox * QMetaObjectTest::spin_valueChanged(int arg)
{//响应界面上spinBox的valueChanged(int)信号
    Q_UNUSED(arg);
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender()); // 获取发射的对象,girl或boy
//    std::cout<<std::boolalpha<<spinBox->property("isBoy").toBool()<<std::endl;
    return spinBox;
}
void QMetaObjectTest::spinBoy_valueChanged(int arg) // 实际的槽函数调用者
{
  // spinbox的value改变后被读取,然后影响this->boy和this->girl
   QSpinBox * spinBox = spin_valueChanged(arg);
   this->boy->setAge(spinBox->value());
}
void QMetaObjectTest::spinGirl_valueChanged(int arg)
{
   QSpinBox * spinBox = spin_valueChanged(arg);
   this->girl->setAge(spinBox->value());
}

// 4个QPushButton的槽函数
void QMetaObjectTest::on_btnClear_clicked()
{//"清空文本框"按钮
    this->ui->plainTextEdit->clear();
}

void QMetaObjectTest::on_btnBoyInc_clicked()
{//"boy长大一岁"按钮
    this->boy->increaseAge(); // 调用成员函数
}

void QMetaObjectTest::on_btnGirlInc_clicked()
{//"girl长大一岁"按钮
    this->girl->increaseAge(); /// 调用成员函数
}

void QMetaObjectTest::printClassInfo(const QMetaObject * meta,const QString&  sex)
{ // "显示元对象信息"按钮槽函数去调用的,节省重复代码
  ui->plainTextEdit->appendPlainText("=="+sex+"元对象信息==");
  for (int i=meta->classInfoOffset();i<meta->classInfoCount();++i)
  {
     QMetaClassInfo classInfo=meta->classInfo(i);
      ui->plainTextEdit->appendPlainText(
         QString("classInfo=%1 <=> value=%2").arg(classInfo.name()).arg(classInfo.value()));
  }
  ui->plainTextEdit->appendPlainText(QString("className <=> %1").arg(meta->className())); // 打印元类
  ui->plainTextEdit->appendPlainText(sex+" classProperty =>");// 打印属性
    // 1.propertyOffset()返回类的第1个属性的序号,不一定是0;
  //  2.propertyCount();属性的个数,这里是age,name,score 3个
  auto which = sex=="Boy"?boy:girl;
  for (int i=meta->propertyOffset();i<meta->propertyCount();i++) //
  {
      const char* propName=meta->property(i).name(); // 获取姓名
      ui->plainTextEdit->appendPlainText(
      QString("propertyName=%1，value=%2").arg(propName).arg(which->property(propName).toString()));
  }
}
void QMetaObjectTest::on_btnClassInfo_clicked()
{//"类的元对象信息"按钮
      const QMetaObject *meta1=boy->metaObject();
      const QMetaObject *meta2=girl->metaObject();
      ui->plainTextEdit->clear();
      this->printClassInfo(meta1,"Boy");
      this->printClassInfo(meta2,"Girl");
}

QMetaObjectTest::~QMetaObjectTest()
{
  delete ui;
}

