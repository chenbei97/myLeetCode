自定义插件，一定一定要首先使用和QtCreator对应的编译器
因为QtCreator用的是MSVC2017 32bit，而Qt5.9.9版本没有这个版本的，只有MSVC2017 64bit那么就会出问题

但是Qt5.14.2版本有MSVC2017 32bit，且这个编译器能够使用的前提是必须安装的是VS2017(社区版也可以)，无论是VS2019还是VS2022均不行
有了VS2017+MSVC2017_32bit编译好插件后，把插件生成的2个dll文件(debug+release)都放在Qt的指定路径下(下文提到)
这样UI面板就能够直接看到自己设计的组件了，否则是看不到的

后边的问题就是使用这个插件，需要添加外部库，外部库就是include目录，这个目录把dll、lib和自定义组件的头文件都放进去，之后就可以正常编译运行了


qBatteryPlugin.h 实现了自定义插件所需要的接口,这些接口函数无需改动

qBatteryPlugin.cpp 函数的实现都是根据创建插件向导里设置的内容自动生成的,如果需要手动调整,可以进行更改

// .pro文件的含义
CONFIG      += plugin debug_and_release// 表示qmake编译可以使用debug和release2个模式,项目要作为插件,编译后只会产生lib和dll(或so)文件
TARGET      = $$qtLibraryTarget(qbatteryplugin)// 编译生成的目标路径
TEMPLATE    = lib// 定义项目类型,表示项目是1个库,一般的应用程序模板类型是app

HEADERS     = qbatteryplugin.h// qBattery.pri是内置于插件的项目,配置代码就是说明了内置项目的头/源文件
SOURCES     = qbatteryplugin.cpp
RESOURCES   = icons.qrc // 插件的图标
LIBS        += -L.

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(qbattery.pri)

DISTFILES += \
    readme.txt

// 内置.pri文件的含义
HEADERS += qBattery.h
SOURCES += qBattery.cpp


内置项目的实现只有3个区别
#include <QtUiPlugin/QDesignerExportWidget> // 1. 第1个区别,要包含该头文件
// Qt5.7以下版本为#include <QtDesigner/QDesignerExportWidget>
// 以上版本为#include <QtUiPlugin/QDesignerExportWidget>
// 定义自定义小部件时使用此宏，以确保它们从插件中正确导出以与 Qt Designer 一起使用
class QDESIGNER_WIDGET_EXPORT QBattery : public QWidget // 2. 第2个区别,声明此类的宏
{
    Q_OBJECT
    Q_PROPERTY(int  powerLevel READ powerLevel WRITE setPowerLevel NOTIFY powerLevelChanged DESIGNABLE true) // 3. 第3个区别,DESIGNABLE=true,设置UI设计器是否可见默认true
    //....
}
除了以上3个区别其它的完全一样,源文件的实现也是一样

以release方式编译生成dll文件名称为qbatteryplugin.dll（也可以以debug模式，生成的是qbatteryplugind.dll）
将其复制到2个路径下（1个是编译器下的插件目录，一个是工具下的插件目录）
E:\Qt5.1.4\Tools\QtCreator\bin\plugins\designer
E:\Qt5.1.4\5.14.2\msvc2017\plugins\designer

此时重启QtCreator再打开任何一个项目，UI设计器面板就可以存在这个组件了
现在想要使用这个插件的话，新建一个项目之后要做三件事：
1、项目下新建include文件夹，把dll、lib（debug和release版本都放进去2个文件
2、把插件内置项目也就是电池五头文件qbattery.h也放在include文件夹下
3.   对应的dll文件也放在include文件夹下
书上说把dll文件放在可执行目录下，就是exe所在的目录下，但是我试过不行
之后我把dll文件只有放在include文件夹下，也就是和lib放在一起
且项目文件必须把这dll文件加进来才能编译运行成功
4.项目文件右击添加外部库，按照向导执行

这里使用MSVC会有中文问题，不过书上讲的使用下方代码规避貌似没啥用，依然乱码
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

使用QTextCodec也不行，所以就用英文吧，别用中文了！！！

参考链接：https://www.cnblogs.com/feiyangqingyun/p/6182320.html
