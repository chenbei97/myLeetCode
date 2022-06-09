研究生阶段用的PyQt5做的界面,那时候是因为论文时间紧,所以python开发速度快些
另外那时候对c++不熟悉,也对什么编译器,cmake等不熟悉,所以看不懂,今天开始用C++编写了第1个程序
我发现写起来还是挺顺手的,配好了VS环境,很多东西都想起来了

今天(2022/6/5)考虑到未来职业发展的问题,我可能真的不适合做硬件
再加上公司的管理问题很大,留不住老员工,离职率高,应届生成长速度慢
我觉得在这不能久留,我在想我现在会些什么,能做什么,想做什么？

当初来大华确实也是为了户口,没有直接互联网,但是想来近年互联网的情况
大华这个选择也不算错误,但是如果大华有合适的发挥的机会就更好了
我没准就会呆很长时间,只是目前公司的现状似乎分崩离析,每个人都没有什么斗志
就连我的领导,做了8年,近来突然说要离职,有传闻是因为上层的意思,毕竟这么突然怎么说找好下家再走吧

我目前没有再找工作,是因为我面试了一些公司,大概率我的问题是嫌弃我不稳定,一年不到就离职
其次户口违约金的问题,16万也不是小数目,再就是户口因为疫情的缘故可能不容易快速办下来
而且我还要办公积金贷款,听力损伤要买个新的助听器(用10年了该换了),然后申请个4级残疾证领点补助
这些事都要花时间,再就考虑到下半年经济不好,也许换一家公司也不是我想象的如此

所以我想着就是再干半年看看情况,这些想法是在我领导走之前大概想好的
这两天一听他说要走,我就不知道以后对谁负责,也没人管了,我和他的关系一直不错
但是他一走,也就没有什么老员工了,我还能跟着谁呢？

现在想想，我会些opencv搞一些简单的图像处理，也会一些深度学习/机器学习的东西
诸如tensorflow和pytorch,但是这些要求高,同时前景也不容乐观
再就是我还学了cmake,看过很多的书,数据结构和算法,Effective系列书籍,C++Primer
还看过代码整洁之道,现代C++特性,研究生还会Qt(PyQt5),但是我不会硬件,也不会dsp/mcu之类的嵌入式
我顶多对liunx了解,装了虚拟机,不过目前也不知道用这个做点啥

目前还挺迷茫的,我的处境很尴尬,我想着如果写代码,可能就上位机在硬件公司可能用得到了
所以我打算把C++Qt5.9看完,之前的python Qt只看了5章,很多东西没继续学
目前这半年就先这样吧,等学妹啥的新人来了(快七月了)看能不能凑一组做个项目

不然简历上也挺尴尬的,大华一年半什么也没做成,无法想象！

//------------------------------进入正文

捋一下简单复习的知识,涉及《Qt5.9C++开发》的前2章
1. 槽函数命名规则是on开头,然后跟上的字符串要与控件名称一致,然后是槽信号的简称
例如 on_btnclose_clicked,或者其他信号valueChanged,currentIndexChanged等等
这个控件可以是UI设计界面添加的也可以是动态添加的,如果是动态添加的,自定义变量名就是这个控件名称
例如自定义的SpinBox控件,在private定义的,QSpinBox * fontSizeBox;
那么槽函数一定要一致,命名为void on_fontSizeBox_valueChanged(int fontsize);

2. 整个工程结构其实就是1个.ui文件,它背后其实是"ui_helloworld.h"
不过在QtCreator找不到这个文件,VS是可以找到的,内部其实就定义了一个Ui_helloWorld类
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


