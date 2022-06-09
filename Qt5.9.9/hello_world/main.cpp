#include "helloworld.h"

#include <QApplication>
/*
一些笔记:
1. 槽函数命名规则是on开头,然后跟上的字符串要与控件名称一致,然后是槽信号的简称
例如valueChanged,clicked,currentIndexChanged等等
2. UI的GUI框架类代码只能通过私有属性Ui来访问,实现GUI和业务的分离
3.Q_OBJECT是一个宏，如果使用槽信号机制是必须要加入的
4.connect是QObject的一个静态函数，用于连接信号与槽或者信号与信号
常见的形式是: QObject::connect(发送对象,SIGNAL(signal()),接收对象,SLOT(slot()));

QObject::可以忽略，因为是QObject是全局基类可以直接使用
SIGNAL和SLOT是Qt的宏，可以将信号和槽函数的参数转为字符串
信号可以是Qt已经定义过的信号，例如clicked等，也可以是自己定义的函数
不过自己定义的信号函数需要事先声明是信号函数，自定义的槽函数同理也可以声明
但是要注意自定义的槽函数也要符合命名规则，例如
例子: connect(ui->btnclose,SIGNAL(clicked()),hello_world,SLOT(close()));

一个信号也可以连接多个槽函数,也就是说可以同时做2件事以上
connect(ui->combox,SIGBAL(valueChanged(int)),this,SLOT(func1(int)));
connect(ui->combox,SIGBAL(valueChanged(int)),this,SLOT(func2(int)));
按照先func1,再func2的定义顺序执行

多个信号链接到1个槽函数,也就是多个事件导致的结果相同
例如这里无论点击哪个互斥按钮,都调用的是同1个函数
（互斥通过将控件放入1个groupBox实现，可见（https://zhidao.baidu.com/question/173031163.html）
这个函数里边可以进行判断,然后设置颜色
connect(this->ui->rbt_red,&QRadioButton::clicked,this,&helloWorld::setTextColor);
connect(this->ui->rbt_green,&QRadioButton::clicked,this,&helloWorld::setTextColor);
connect(this->ui->rbt_blue,&QRadioButton::clicked,this,&helloWorld::setTextColor);

1个信号连接到另1个信号也是可以的,也就是发射1个信号也会发送另1个信号
connect(发送者,SIGNAL(valueChanged(int)),this,SIGNAL(refreshInfo(int)));

5. 信号和槽函数的参数类型和个数必须一致，信号的参数不能少于槽函数，且不能有返回值
6.clicked(bool)带bool值可以反馈一个控件的选择状态
7.QColor可以设置颜色,可以作为画刷QBrush的构造函数参数
8.QBrush是画刷，可以用于填充封闭图形；QPen是画笔，一般是描绘轮廓线；两个都可以被QPainter画家使用，用于填充画布QPaintDevice
9.可以充当画布类QPaintDevice的有QWiget,QImage,QPixmap,QPicture,QPaintDeviceWindow,QPagedPaintDevice,QOpenGLPaintDevice
最常用的是前4个
10.有时候不能直接借助可视化ui来设计,所以必须借助写代码的方式动态添加,
但是纯写代码实现界面工作量较大,可以在创建项目时不勾选[generate forum]
两者结合快速快发是最好的,可以提高工作效率
11.状态栏和工具栏不能直接拖动控件,需要借助写代码,例如工具栏可以添加SpinBox来调整字体大小
状态栏可以添加Label显示文字或者添加进度条显示进度,这些控件都是不能直接拖动的
12.菜单栏是可以直接添加选项和菜单的,需要设计动作,动作可以ui设计也可以写代码设计
actionclose和actionreboot都是QAction类,分隔符也是QAction类
QAction类在ui的Action Editor进行编辑,或者转到槽写代码实现
13.工具栏事先需要使用QToolBar来构建,构建需要制定名称,然后通过addWidget来添加进各种动作或者控件
14.file->新建文件->Qt->资源文件,主要用于存储图标和图片,可以在程序中使用
需要新建一个前缀prefix,例如icons或者images,相当于资源分组
注意如果没有任何前缀,把icons文件夹添加进来,在qrc显示的是/
如果qrc还加了前缀,那就是:/icons/icons/*.ico,必须加冒号
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    helloWorld w;
    w.show();
    return a.exec();
}
