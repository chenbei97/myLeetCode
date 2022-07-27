这里和上个例子创建静态库的区别是没有使用MSVC，使用Mingw编译

这是为了说明2个编译器都是可以的，区别只是生成的.a文件而不是.lib文件

因为是动态库，所以除了.a文件还额外生成.dll文件

因为有debug和release模式，所以是4个文件，这里注意改名，在debug模式下改名多加个d

共享库调用有2种方式，一种是隐式链接库调用，一种是显示链接调用

1. 隐式链接库调用
编译程序时有动态库的lib文件(或.a文件)+h头文件，知道dll有哪些接口函数，编译时就可以生成必要的链接信息
使用DLL中的类或函数时根据头文件中的定义使用即可，这种方式主要用于同一种编程软件(如Qt)生成的代码之间的共享

使用动态库的项目下的include文件夹需要放入6个文件，debug和release模式的2个.a文件和2个.dll文件以及创建共享库时用到的2个头文件

但是会发现总是release版本成功，但是debug版本不成功，会提示QWidget: Must construct a QApplication before a QWidget

猜测是2个dll文件不同名字的原因，虽然.a文件进行了区分，但是.dll并没有区分

所以按照书上的解决方式，我把2个dll文件（注意名字改回来去掉d，2个dll是T同名的），然后各自放在exe的目录下，发现就能运行成功了

所以现在include只有4个文件

还要提到一点，使用共享库的文件编译时也最好和共享库的版本一致，也就是都使用mingw32，否则可能要考虑二进制兼容问题

2. 显示链接调用

第一种方式，应用程序编译时将自动加载DLL文件，本方式应用程序运行时才加载共享库文件

所以本方式编译时无需共享库的任何文件，只需要知道函数名称和原型即可

所以本方式可以调用其他语言编写的DLL文件

本方式需要借助QLibrary实现，QLibrary与平台无关，用于运行时加入共享库，一个QLibrary对象只对一个共享库进行操作

一般QLibrary的构造函数中传递一个文件名，可以带绝对路径的文件名，也可以是不带后缀的单独文件名。

QLibrary会根据运行的平台自动查找不同后缀的共享库文件，例如UNIX的.so文件，MAC的.dylib文件，Windows的.dll文件

按照书上的示例，在书的配套资源中可以找到Delphi写的DLL文件，只有1个函数，函数原型为

function triple(N:integer):integer; // 用于计算N的3倍值

这个函数生成的DLL库在DelphiDLL文件夹下。

调用此DLL库的核心代码是：
QLibrary myLib("DelphiDLL"); // 绑定当前路径下的文件夹DelphiDLL
if (myLib.isLoaded())
    QMessageBox::information(this,"信息","DelphiDLL.DLL已经被载入,第1处");
typedef int (*FunDef)(int); //函数原型定义
FunDef myTriple = (FunDef) myLib.resolve("triple"); //解析DLL中的函数
int V=myTriple(ui->spinInput->value()); //调用函数
ui->spinOutput->setValue(V);
if (myLib.isLoaded())
    QMessageBox::information(this,"信息","DelphiDLL.DLL已经被载入,第2处");

但是直接执行还是会错误，必须把DelphiDLL文件夹下的DelphiDLL.dll文件放在debug和release可执行目录下就不会再出错了