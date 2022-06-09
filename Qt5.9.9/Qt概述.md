## chapter1-2

1-2章关于Qt的安装和简单复习可见[hello_world](hello_world)的内容，其运行结果图片可见[](hello_world/app.png)。

主要的笔记如下。

```
1. 槽函数命名规则是on开头,然后跟上的字符串要与控件名称一致,然后是槽信号的简称
例如 on_btnclose_clicked,或者其他信号valueChanged,currentIndexChanged等等
这个控件可以是UI设计界面添加的也可以是动态添加的,如果是动态添加的,自定义变量名就是这个控件名称
例如自定义的SpinBox控件,在private定义的,QSpinBox * fontSizeBox;
那么槽函数一定要一致,命名为void on_fontSizeBox_valueChanged(int fontsize);

2. 整个工程结构其实就是1个.ui文件,它背后其实是"ui_helloworld.h"
不过在QtCreator默认找不到这个文件,可以点击工程上方的工具栏点击过滤器树形视图,取消隐藏文件就可以看到了
VS如果配置过Qt,就可以直接找到的,内部其实就定义了一个Ui_helloWorld类，设了一些Gui的控件参数
Ui_helloWorld类有2个函数setupUi和retranslateUi函数,这个类被命名空间下Ui的helloworld所继承
namespace Ui {
    class helloWorld: public Ui_helloWorld {};
} // namespace Ui
同时1个同名的helloworld类的声明在helloworld.h中,但不属于Ui空间,它将Ui::helloworld作为私有属性组合
之所以这样做就是为了将Gui和业务分离开,符合严格封装的思想

3. Q_OBEJECT需要在helloworld中声明,这是引入信号与槽机制需要声明的宏
SIGNAL和SLOT也是Qt的宏,可以将信号和槽函数的参数转为字符串,主要用在connect函数
例如QObject::connect(this->ui->rbt_red,&QRadioButton::clicked,this,&helloWorld::setTextColor);
如果是带参数的:connect(this->fontSizeBox,SIGNAL(valueChanged(int)),this,SLOT(on_fontSizeBox_valueChanged(int)));
注意:带参数的因为可能出现函数重载的情况,第1种函数指针的写法不符合语法;但是不带参数的呢,用宏好像又不起作用
例如:QObject::connect(this->ui->rbt_blue,SIGNAL(clicked()),this,SLOT(setTextColor()));写法不起作用

4. 关于connect其他的说明
connect是QObject的一个静态函数,常见的形式是: QObject::connect(发送对象,SIGNAL(signal()),接收对象,SLOT(slot()));
信号和槽函数的参数类型和个数必须一致，信号的参数不能少于槽函数，且不能有返回值

一个信号也可以连接多个槽函数,也就是说可以同时做2件事以上;
connect(ui->combox,SIGBAL(valueChanged(int)),this,SLOT(func1(int)));
connect(ui->combox,SIGBAL(valueChanged(int)),this,SLOT(func2(int)));
按照先func1,再func2的定义顺序执行

多个信号可以链接到同1个槽函数,也就是多个事件导致的结果相同
connect(this->ui->rbt_red,&QRadioButton::clicked,this,&helloWorld::setTextColor);
connect(this->ui->rbt_green,&QRadioButton::clicked,this,&helloWorld::setTextColor);
connect(this->ui->rbt_blue,&QRadioButton::clicked,this,&helloWorld::setTextColor);

1个信号连接到另1个信号也是可以的,也就是发射1个信号也会发送另1个信号
connect(发送者,SIGNAL(valueChanged(int)),this,SIGNAL(refreshInfo(int)));

5. 关于QColor,QBrush,QPen等
QColor可以设置颜色,可以作为画刷QBrush的构造函数参数
QBrush是画刷，可以用于填充封闭图形；QPen是画笔，一般是描绘轮廓线；
两个都可以被QPainter画家使用，用于填充画布QPaintDevice
可以充当画布类QPaintDevice的有QWiget,QImage,QPixmap,QPicture
QPaintDeviceWindow,QPagedPaintDevice,QOpenGLPaintDevice等
最常用的是前4个

6. 有时候不能直接借助可视化ui来设计,所以必须借助写代码的方式动态添加
例如状态栏和工具栏不能直接拖动控件,需要借助写代码,如工具栏可以添加SpinBox来调整字体大小
状态栏可以添加Label显示文字或者添加进度条显示进度,这些控件都是不能直接拖动的
菜单栏是可以直接添加选项和菜单的,需要设计动作,动作可以ui设计也可以写代码设计
但是纯写代码实现界面工作量较大,可以在创建项目时不勾选[generate forum],两者结合快速快发是最好的,可以提高工作效率

7. 关于QAction
QAction类在ui的Action Editor进行编辑,或者转到槽写代码实现分隔符也是QAction类

8. 关于QPalette
QPalette存在一些枚举值,ColorRole和ColorGroup
enum ColorGroup { Active, Disabled, Inactive, NColorGroups, Current, All, Normal = Active };
enum ColorRole { WindowText, Button, Light, Midlight, Dark, Mid,
                Text, BrightText, ButtonText, Base, Window, Shadow,
                Highlight, HighlightedText,
                Link, LinkVisited,
                AlternateBase,
                NoRole,
                ToolTipBase, ToolTipText,
                NColorRoles = ToolTipText + 1,
                Foreground = WindowText, Background = Window
            };

9. 关于工具栏
工具栏事先需要使用QToolBar来构建,构建需要制定名称,然后通过addWidget来添加进各种动作或者控件
工具栏需要指定在什么位置构建，利用枚举值说明ToolBarArea
enum ToolBarArea {
    LeftToolBarArea = 0x1,
    RightToolBarArea = 0x2,
    TopToolBarArea = 0x4,
    BottomToolBarArea = 0x8,

    ToolBarArea_Mask = 0xf,
    AllToolBarAreas = ToolBarArea_Mask,
    NoToolBarArea = 0
};

10. 状态栏
this->statusBar()->addWidget(progressbar); // 添加进状态栏
this->ui->statusbar->showMessage("你终于承认我最帅了!"); // 打印消息

11. 菜单栏
addAction和addMenu是这样用的,他们会返回指向新建的项地址

privare: QAction * startProgressbar; // helloWorld.h的一个私有属性声明
QMenu * qm = this->menuBar()->addMenu("执行");
QAction * qac = qm->addAction("进度条");
this->startProgressbar = qac; // 让这个私有属性等于qac
connect(this->startProgressbar,&QAction::triggered,this,&helloWorld::on_startProgressbar_triggered); // 再连接这个同名槽函数

12. 其他
线程阻塞问题可以:QCoreApplication::processEvents(QEventLoop::AllEvents, 100);来解决问题
```

## chapter3

### 元对象系统和编译器

Qt本身其实是用C++开发的库，但是它具备Qt自己的属性，也就是信号与槽机制、对象属性等，这些并不属于C++的范畴，所以需要一个预处理过程。**Qt元对象编译器也就是MOC是一个预处理器，在源程序编译前先转换为标准C++兼容的形式**，即对信号和槽的代码进行宏替换，这也是为何必须添加Q_OBJECT宏的原因。

QtCore是Qt的核心，Qt为c++语言增加的特性就是在此模块实现，扩展特性主要有信号与槽机制、属性系统、动态类型转换等，它们共同作为Qt的**元对象系统**。

元对象系统的主要构成如下：

1、QObject类，是所有使用元对象系统的类的基类

2、类的private部分声明Q_OBJECT宏，使类可以使用元对象的特性，如动态属性、信号与槽

3、MOC元对象编译器，为每个QObject的子类提供必要代码实现元对象系统的特性

MOC工具读取C++源文件时发现类的定义有Q_OBJECT时就会为这个类生成另外1个包含元对象支持代码的C++源文件(其实就是那个UI_XXX.h文件)

4、OObject的一些成员函数功能

metaObject可以返回其控件的类型

```c++
QObject * obj = new QPushButton;
obg->metaObject()->className(); // 返回"QPushButton"
```

inherits(const char*className)可以判断一个对象实例是否是名称为ClassName的类或者QObject的子类的实例。

```c++
std::cout<<std::boolalpha<<this->toolbar->inherits("QToolBar")<<std::endl; //true
std::cout<<std::boolalpha<<this->toolbar->inherits("QObject ")<<std::endl; // false
std::cout<<std::boolalpha<<this->toolbar->inherits("QRadioButton")<<std::endl; // false
```

QObejct指针可以指向任何子类对象，但是本质上还是QObject指针，可以通过qobejct_cast进行转换，就像static_cast和dynamic_cast那样做一样。

```c++
QObject * obj  = new QMyWidget; // 不区分Qt内建和自定义类型,QMyWidget继承于QWidget
QWidget * widget = qobject_cast<QMyWidget *>(obj); // ok
QLabel * label = qobject_cast<QLabel *>(obj); // error，因为QLabel不是QMyWidget子类
```

setProperty()函数可以设置属性的名称和数据，property()函数可以获取属性值。

这个函数主要是为了定义为类定义动态属性。

```c++
bool setProperty(const char *name, const QVariant &value);
QVariant property(const char *name) const;
```

关于属性，在下一小节说明，即[属性系统](#属性系统)。

### 属性系统

什么是属性？Qt提供了Q_PROPERTY()宏定义属性，基于元对象系统实现与C++编译器无关。

定义了一个返回值type，名称name的属性，它由于有一些关键字分别定义不同的机制。

```c++
Q_PROPERTY
(
	type // 返回类型
	name // 属性名称
	READ // 指定1个读取属性值的函数,没有MEMBER关键字时必须设置READ
	WRITE // 指定1个设定属性值的函数,,只读属性没有WRITE设置
	MEMBER // 指定1个成员变量与属性关联,成为可读可写的属性,无需再设置READ和WRITE
	RESET // 可选,指定1个设置属性缺省值的函数
	Notify // 可选,设置1个信号,属性值变化时发射此信号
	DESIGNABLE // 属性是否在Qt Designed可见,缺省为True
	CONSTANT  // 表示属性值是常数,但只是针对具体的1个实例而言,不同实例可以有不同的常数
	FINAL // 表示定义的属性不能被子类重载
)
```

这个属性和名称其实就是ui文件里右下角的那些可视化展示，例如QWidget有属性focus、enabled和cursor，分别表示焦点策略、启用或禁用widget、鼠标悬浮时的样式等等。

关于焦点策略有

```c++
NoFocus 无法通过点击和键盘获得焦点
TabFocus 鼠标无法获得焦点，Tab可以获得
ClickFocus 鼠标点击可以获得焦点，Tab不可
StrongFocus 鼠标和Tab都可以获得
WheelFocus 滚轮获得
Q_PROPERTY(bool focus READ hasFocus);// 定义了名称为focus的只读属性返回值bool,读取联系的函数是hasFocus
```

enabled设置只有2种，开启或者未开启状态，读写联系2个函数。

```c++
Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled);
```

鼠标设置的样式有很多，这里不列举，也有2个函数去读取和设置样式，还可以RESET设置默认参数

```c++
Q_PROPERTY(QCursor cursor READ cursor WRITE setCursor RESET unsetCursor)
```

只要知道属性的名称，无论是否使用READ和WRITE定义了接口函数，就可以通过QObject::property获取属性值，例如

```c++
QObject * obj  = new QPushButton;
obj->setProperty("flat",QVariant(false)); // 设置属性名称为flat,值为true
obj->setProperty("age",QVariant(18.5));
QVariant isFlat = obj->property("flat");
float age = obj->property("age").value<double>();
std::cout<<std::boolalpha<<isFlat.value<bool>()<<"\n"; // false
std::cout<<age<<"\n"; // 18.5
```

总之，属性是动态的被添加进类，更多的用法在以后会讲解。

属性信息还包括类的信息，级通过宏Q_CLASSINFO()来为类的元对象定义"名称--值"信息，例如

```c++
class QMyClass : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author","wang")
    Q_CLASSINFO("comapny","huawei")
    Q_CLASSINFO("Version","3.0.1")
    public:
    ...
};
```

### 信号与槽

