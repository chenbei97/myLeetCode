这是一个简单复习Qt的文件夹，版本是5.9.9

结合书《C++Qt5.9开发》一书复习和继续学习

整理的笔记可见Qt概述.md

目前更新的子项目：

0. MyPlatform是重新配好环境后，再次运行成功的研究生时期写的软件

1. hello_world 一个开始版本

2. MetaObjectTest 元对象的测试实例

3. TestListTreeTabWidget 前四章的各类组件集中总结

4. TestFileSystemModel 在QTreeView上的应用,视图组件<=>数据模型的关系

5. TestSerialPortCommunication 上位机的串口通信程序

6. TestQStringListModel 在QListView上的应用,视图组件<=>数据模型的关系

7. TestQStandardItemModel 在QTableView上的应用,视图组件<=>数据模型的关系

8. TestQThread 线程的简单使用

9. TestDelegate 如何改变单元格默认编辑框的代理类,只需要继承和重写4个函数即可,然后使用view模型的setDelegate函数设置

10. TestStandardDialog 标准对话框的使用，包括文件对话框、颜色对话框、字体对话框、输入对话框和消息对话框

11. TestMultiDialog 展示了如何自定义对话框，使用信号与槽或者指针传递来实现对话框与主窗口或者主窗口和对话框之间的交互操作

12. TestMultiWindow 展示了如何定义多窗口，和11的例子一样的，只不过继承自QWidget和QMainWindow而不是QDialog，另外这2类窗口可以被tabWidget添加作为嵌入式显示

13. TestMDI 展示如何创建多文档窗口，区别只是使用QMdiArea代替了QTabWidget

14. TestQSplash 展示如何创建无边框可拖动的登录窗口(用户名+加密密码)

15. TestQDataStream 展示如何读取和保存为stm、dat和txt文件格式

16. TestFileDirOpera QCoreApplication\QDir\QFile\QFileInfo\QTemporaryFile\QTemporaryDir\QFileSystemWatcher的使用

17. TestQPainter 使用绘图系统配合QPainterPath绘制五角星和散射圆的案例,比较视图和窗口坐标系统的差异

18. TestGraphicsViewCooridate 演示视图、场景和图形项的坐标关系

19. TestGraphicsViewDraw 演示如何绘制椭圆、多边形、矩形、直线和文字图形项，并组合它们，辅助鼠标和键盘事件

20. TestQChartLineSeries 演示如何绘制折线图,设置图表、曲线、坐标轴、图例、主次刻度、主次网格线，各类标题、可见性等

21. TestQChartDrawAllCharts 演示如何绘制柱状图(普通、堆叠和百分比)、饼图、散点图、光滑曲线图

22. TestQchartViewZoom 演示如何定义有鼠标事件的视图，实现通过鼠标拖放一个矩形来控制图表的缩放

23. TestTestQ3DBarScatterSurface 一次性演示书上提到的三维柱状图、三维散点图、三维曲面图和三维地形图的使用

24. TestTestCustomBatteryWidget 演示如何使用提升法来自定义新的组件,关键在于重载paintEvent事件

25. TestTestCustomBatteryPlugin 演示如何自定义插件
    坑1：创建插件项目后，编译此项目和的和编译QtCreator的编译器必须一致(可以查看帮助-关于QtCreator)
    坑2: 笔者是Qt5.9.9版本,编译QtCreator的编译器是MSVC-2017-32bit版本,实际上安装Qt5.9.9的时候没有MSVC-2017-32bit！只有MSVC-2017-64bit
    坑3：然而无论如何必须满足是MSVC-2017-32bit，所以只能降低Qt版本为Qt5.14.2,此时发现安装过程是有MSVC-2017-32bit版本的，现在版本一致了但是会发现这个版本不能用
    坑4：坑3的问题笔者尝试用VisualStudio Installer安装单个组件"MSVCv140=VS2015C++生成工具(v14.00)",
        "MSVCv141=VS2017C++ x86/x64生成工具(v14.16)","MSVCv142=VS2019C++ x86/x64生成工具(v14.29-16.11)"的编译器来设定MSVC-2017-32bit
        但是都失败了，因为这些不具备MSVC-2017-32bit编译器
    坑5：笔者最后尝试可能是必须安装VS2017的原因，所以我安装了社区版，发现确实如此，MSVC-2017-32bit都不要设置自动被Qt扫描出来
    坑6：有了正确的Qt版本，正确的编译器版本，正确的编译器设置，按照书上的过程编译好了插件，把插件在debug和release2个模式下生成的dll文件都放在指定目录下
        这里的2个目录是E:\Qt5.1.4\Tools\QtCreator\bin\plugins\designer； E:\Qt5.1.4\5.14.2\msvc2017\plugins\designer；
        会发现还是不行，重启QtCreator后UI设计器没有生成自定义的组件，根据https://www.cnblogs.com/feiyangqingyun/p/6182320.html的说明，我可能是掉入了坑7
    坑7：在插件项目的内置项目头文件中，Qt5.7以下版本为#include <QtDesigner/QDesignerExportWidget>，以上版本为#include <QtUiPlugin/QDesignerExportWidget>
        所以这里是#include <QtDesigner/QDesignerExportWidget>，而不是书上的#include <QtUiPlugin/QDesignerExportWidget>，因为书上用的5.9版本
        但是为啥它5.9的版本却用MSVC2015-32bit的编译器我是不知道怎么做到的，这里不深究了
    坑8：现在坑7解决，重新编译，把dll文件放入2个目录后，UI设计器能出现自定义组件了，之后就是怎么使用这个组件，按照书上说明，要在项目新建include文件把lib+自定义组件头文件都放进去
        然后引入外部库，设定为include，再把dll文件放在可执行目录下就能运行
    坑9：按照书上一样的做法但是不行，笔者发现dll文件不应该放在可执行目录下，直接放在include就行，也就是include会有5个文件
        2个lib文件：qbatteryplugind.lib，qbatteryplugin.lib
        2个dll文件：qbatteryplugind.dll，qbatteryplugin.dll
        1个头文件：qbattery.h(注意是插件内置项目的头文件而不是插件项目本身头文件)
    坑10：即使如此也可能还是会出现链接错误问题，你可以试试把include文件作为外部目录整体加入到项目中，笔者就是这样解决了问题
    坑11：最后要强调，MSVC是本地windows下的字符集GB2312而不是UTF8，但是书上提供的中文乱码解决方案不成功，笔者也不想找了，就用英文就行了

26. TestCreateStaticLib 演示如何创建静态库，这里不需和QtCreator的编译器保持一致，只需库和使用库的编译器保持一致(MSVC的debug-release)

27. TestCreateShareLib 演示如何创建动态库，和创建静态库的方式一样，但是不需要头文件放入include，需要QLibrary进行解析

28. TestThread 简单的QThread2种方式应用,Qt文档例子的具体化,也是对8-TestQThread的补充

29. TestThreadSynchronization 提及了线程同步的几种方法(基于互斥量、读写锁、条件变量以及信号量)

30. TestHostInformationQuery 演示如何使用QHostInfo和QNetworkInterface获取本机或指定域名IP地址

31. TestTcpServerClient 演示如何进行TCP通信(本机作为服务器也作为客户端)

32. TestUdpUnitMultiBroadCast 演示如何进行UDP通信(单播、广播和组播模式)

33. TestNetWorkHttp 演示如何定义基于HTTP协议的网络应用程序,例如一个下载文件的程序

34. TestQMediaPlayer 演示如何使用音频播放器和音效播放器

35. TestQAudioRecorder 演示如何录制音频并保存,可以设置和显示录制的参数(采样率通道数、帧数、字节序等等)

36. TestQAudioInput 和QAudioRecorder主要区别是可以直接作用音频输入设备按照指定格式采样，同时还可以指定输出流对象进行处理而不是只能保存

37. TestVideoPlayBack 一次性演示关于视频播放的所有问题(基于3种组件的播放器、视频录制、摄像头控制等等)

38. TestTRTranslation 演示如何使用tr函数,生成ts文件以及使用QtLinguist工具翻译并重新发布成qm文件调用的过程，注意必须qm作为资源文件调用(否则好像无法切换语言)

39. TestQStyle 演示如何使用QStyle创建不同风格样式(此项目用cmake而非qmake构建)

40. ApplicationRelease 演示了如何使用windeployqt发布程序,windeployqt必须和编译项目的版本一致(这里都是mingw32),如何使用免费工具setUpFactory制作安装文件

41. SerialPortExamples Qt文档中串口通信的几个例子
    1) 一对客户端和服务端,演示阻塞型同步API在工作线程用法和非GUI线程中的用法
        BlockingSynchronousSerialCommunication/Client
        BlockingSynchronousSerialCommunication/Server
    2) 串口后台固定查询小功能的实现,参照1)的写法,以后项目中可以拿去用
        serialPortFixedQuery/TestfixedQueryThread(2022-08-11)

    3) 这个案例展示了如何使用异步方式也就是readyRead信号来读取串口数据,不过这个案例在readyRead的使用上意义不大，比较简单
        只是简单的使用readAll来读取数据，如果读的速度比发的速度慢就会读出来以前的数据需要做一定处理
        不过这个案例在UI界面的设计上很有参考意义，portConfig.h和portConfig.cpp以及portConfig.ui以后可以拿来使用做一个参考
        关于串口参数配置的核心代码可以参考portConfig.h，尤其使用结构体的这个思路是很好的
        ./AsynchronousSerialCommunication


至今遇见的有价值的问题、技巧等（序号从大到小倒序）：

11. 串口通信的使用方法
(1) 同步阻塞型-工作线程用法
    1) 继承QThread定义自己的线程类,定义一个带参数的外部方法提供给主线程使用用于启动线程,不过启动线程要先判断是否处于running状态,不是使用start,是就使用条件变量的wakeOne
    2) 参数可以是串口名,波特率,要发送的消息等等,方法被主线程调用的时候就能够初始化对应的新线程私有属性
    3) 新的线程类作为UI界面类的私有属性,主线程可以定义同名的外部方法来启动子线程
    4) 重载新线程类的run()函数,UI传递来的信息可能会改变,所以需要使用互斥量进行保护
    5) 自行构建事件循环,因为是客户端,在while内部首先向串口写入请求,调用write后要立即调用waitForBytesWritten确定写入成功
    6) 确定写入成功后才可能有回复的数据,此时准备读取串口数据(但是不一定有),故调用read/readLine/readAll之前要先调用waitForReadyRead判断是否可以读取
    7) 如果有超时错误可以通过信号把信息带出去,UI界面可以建立对应的槽函数作一个状态显示
    8) 无论写入,读取是否成功与失败,结束之后将互斥量上锁,然后条件变量等待下一个事件(外部方法再次被调用)将这个互斥量解锁才能继续执行下方的代码
    9) 因为下次事件的到来可能UI的一些信息发生了变化传给了this,所以在while的末尾段代码需要更新信息传给局部变量,这是因为while循环从未退出,是为了下次进入while调用不出现错误
(2) 同步阻塞型-非GUI线程用法
    1) 同理定义自己线程类,但是不需要使用条件变量进行阻塞,也就是说服务端是一直监听的,客户端接入后会立刻做出反应
    2) 同理
    3) 同理
    4) 同理
    5) 因为是服务端,所以首先使用read/readLine/readAll来读取客户端发送的请求,读取之前先调用waitForReadyRead判定能否读取
    6) 能够读取之后再回复信息,同理写入回复后要立刻调用waitForBytesWritten确定写入是否成功,成功后接下来就是客户端的事情了
    7) 同理
    8) 无论读取是否成功,回复客户端是否成功都只是作出对应的反应,不会阻碍while循环,执行完剩余的代码后又会回到while初始代码处
    9) 同理

10. 带有重载版本的信号使用函数指针传递时的使用方法
一般函数指针传递的都是没有重载版本的信号,直接使用&和::即可
但是带有重载版本的时候,信号函数需要进行一个静态转换指明是哪个版本
例如信号&QComboBox::currentIndexChanged参数有const QString&和int的2个版本
将其静态转换为void (QComboBox::*)(const QString &),表示输入参数为const QString&输出参数void的函数指针,且该函数是从属于QComboBox的
QSpinBox的同理valueChanged也有2个版本,但是QLineEdit的textChanged只有1个版本不需要静态转换
void(Teacher::*teacherSignal)(QString) = &Teacher::hungry;
void(Student::*studentSignal)(QString) = &Student::treat;
connect(serialPortComboBox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
        this, &Dialog::activateRunButton);
connect(waitRequestSpinBox, static_cast<void (QSpinBox::*)(const QString &)>(&QSpinBox::valueChanged),
        this, &Dialog::activateRunButton);
connect(responseLineEdit, &QLineEdit::textChanged, this, &Dialog::activateRunButton);
信号的参数个数必须大于等于槽函数的参数个数,且参数类型要一一对应,所以槽函数的参数可以没有
void Dialog::activateRunButton(){runButton->setEnabled(true);}

9. QWidget及其被继承的子类想要绘图，都需要依赖绘图事件paintEvent，这里可以定义自己的绘图，例如设置背景图片
void TestQSplash::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    int x = 0, y = ui->toolBar->height();
    int width = this->width(), height = this->height()-ui->toolBar->height()-ui->statusbar->height();
    // 坐标系统从左上角作为(0,0)开始,向下Y轴,向右X轴
    // 故图片的位置x是从0开始的,而y因为图片是在工具栏下方绘制的所以y就是工具栏的高度
    // 图片的宽度width就是窗口的宽度,高度的话因为图片绘制在工具栏和状态栏之间,所以主窗口高度减去工具栏和状态栏宽度是实际高度
    painter.drawPixmap(x,y,width,height,QPixmap(":/images/back.jpg"));
}

8. 中文乱码的问题
(1) 使用QTextStream的时候设置流自动检测UniCode
QTextStream stream(&file);
stream.setAutoDetectUnicode(true); // 但是这种方法不是全局的
(2) main函数使用QTextCodec设置全局启用
int main()
{
    QTextCodec * code = QTextCodec::codecForName("UTF-8"); // GBK,GB2312等
    QTextCodec::setCodecForLocale(code);

    QApplication a(argc,argv);
    MainWindow w;
    w.show();
    return a.exec();
}

8. 文本对话框的使用方式
QString aFileName=QFileDialog::getOpenFileName(this,tr("打开一个文件"),curPath,
                "C++文件(*.h *cpp);;文本文件(*.txt);;所有文件(*.*)");
if (aFileName.isEmpty()) return; //如果未选择文件，退出
// dosomething

7. 标准的文本文件保存内容的代码
7.1 流的方式：（QFile+QTextStream）
QFile aFile(aFileName);
if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text))
    return false;
QTextStream aStream(&aFile); //用文本流读取文件
aStream.setAutoDetectUnicode(true); //自动检测Unicode,才能正常显示文档内的汉字
QString str=ui->textEditStream->toPlainText(); //QPlainText的内容可以直接转换为字符串
aStream<<str; //写入文本流
aFile.close();//关闭文件

QTextDocument   *doc;       //文本对象
QTextBlock      textLine;   //文本中的一段
doc=ui->textEditStream->document(); //QPlainTextEdit的内容也可以保存在一个 QTextDocument 里
int cnt=doc->blockCount();//QTextDocument分块保存内容，文本文件就是硬回车符是一个block,
QString str;
for (int i=0; i<cnt; i++) //扫描所有 block
{
    textLine=doc->findBlockByNumber(i);//用block编号获取block，就是获取一行
    str=textLine.text(); //转换为文本,末尾无\n
    aStream<<str<<"\n";
}

6. 标准的文本文件读取内容的代码
6.1 流的方式：（QFile+QTextStream+QFileInfo）
/******************************************************************************/
QFile aFile("file.txt");  //以文件方式读出
if (aFile.open(QIODevice::ReadOnly | QIODevice::Text)) //以只读文本方式打开文件
{
    QTextStream aStream(&aFile); //用文本流读取文件
    auto text = aStream.readAll(); // 使用readAll读取文本文件,这里还可以使用readLine等
    aFile.close();//关闭文件

    QFileInfo   fileInfo(aFileName); //文件信息
    QString str=fileInfo.fileName(); //去除路径后的文件名
    // ...dosomething
}
QTextStream in(&aFile);
QString line = in.readLine(); // 也可以先读取1行
while (!line.isNull()) { // 不为空就继续处理
    process_line(line);
    line = in.readLine();// 使用readLine函数
}
/******************************************************************************/

6.2 IO的方式：（QFile+QIODevice）
/******************************************************************************/
QFile file("in.txt");
if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;
while (!file.atEnd()) { // 使用继承的atEnd函数
    QByteArray line = file.readLine(); // 使用继承的readLine函数
    process_line(line);
}
QFile file("box.txt");
if (file.open(QFile::ReadOnly)) {
    char buf[1024];
    qint64 lineLength = file.readLine(buf, sizeof(buf));
    if (lineLength != -1) {
        // the line is available in buf
    }
}
/******************************************************************************/

5. 窗口可以利用的事件类型
    5.1 closeEvent():窗口关闭触发的事件,例如弹出窗口确认是否关闭
    void customDialog::closeEvent(QCloseEvent *event)
    {
        QMessageBox::StandardButton result=QMessageBox::question(this, "Question", "确定要退出本窗口吗?",
                            QMessageBox::Yes|QMessageBox::No |QMessageBox::Cancel,
                            QMessageBox::No);

        if (result==QMessageBox::Yes)
            event->accept();
        else
            event->ignore();
    }
    还可以用来停止可能还在运行的子线程
    void TestOneQWaitConditionBase::closeEvent(QCloseEvent *event)
    {
        if (threadProducer.isRunning())
        {
            threadProducer.stopDice(); // 生产者模型直接停止生产即可
            threadProducer.wait();
        }

        if (threadConsumer.isRunning())
        {
            threadConsumer.terminate(); //消费者模型可能处于等待生产的状态,所以用terminate强制结束
            threadConsumer.wait();//
        }
        event->accept();
    }
    5.2 hideEvent():窗口隐藏事件
    5.3 paintEvent():窗口绘制事件,可以用来加入背景图片
    5.4 showEvent():窗口显示时触发的事件
    5.5 mouseMoveEvent():鼠标移动事件
    5.6 mouseReleaseEvent():鼠标键释放事件
    5.7 mousePressEvent():鼠标键单击事件(左键或者右键)
    5.8 mouseDoubleClickEvent():鼠标双击事件
    5.9 keyPressEvent():键盘按键按下事件
    5.10 keyReleaseEvent():键盘按键释放事件
    5.11 actionEvent():添加工具栏动作事件
    5.12 resizeEvent():调整窗口大小事件
    5.13 hoverEvent():悬停事件
    5.14 timerEvent():定时器事件
    5.15 contextMenuEvent():上下文菜单事件

4. 获取子窗口的父类指针（前提是子窗口在创建时传入了this指针否则它是独立窗口没有父窗口）
一般是在子窗口的关闭事件函数中，需要传递给主窗口一些信息，就必须要获得主窗口的指针
/******************************************************************************/
void QFormDoc::closeEvent(QCloseEvent *event)
{
    TestMultiWindow * parentWindow = (TestMultiWindow *)parentWidget(); // 获取主窗口
    parentWindow->setActWidgetEnable(true); // setActWidgetEnable是主窗口提供的公共函数可以被子窗口使用

}
/******************************************************************************/

如果不能获取主窗口,子窗口是个独立的窗口,只能使用信号与槽机制来传递信息而不必获取指针
/******************************************************************************/
void void QFormDoc::closeEvent(QCloseEvent *event)
{
    emit isAboutClosed(true); // 主窗口要把setActWidgetEnable从公共函数变成公共槽函数使用
    Q_UNUSED(event); // 并且主窗口联系好子窗口自定义的isAboutClosed信号和槽函数setActWidgetEnable
    // 这样当子窗口关闭时发射该信号就会自动执行setActWidgetEnable函数
}
/******************************************************************************/

3. 槽函数中获取信号的发送者
需要利用静态函数sender(),以及类型转换qobject_cast
void on_lineEdit_textChanged(const QString &text)
{
    //....
    QLineEdit * lineEdit = qobject_cast<QLineEdit*>(sender()) ;
}

2. 延时功能的实现(使用QTime)
QTime t;
t.start();
while (condition)
{
    if (t.elapsed > 300) // 300ms以后才做一些事
    {
        qDebug()<<QTime::currentTime(); // 验证是否过去了300ms
        dosomething();
        t.restart();
    }
}

1. 使用waitForReadyRead总是超时（问题已解决）
问题场景：
例如一个QLineEdit输入一串文字,QLineEdit的槽函数内部会往串口写入带有输入文字的某种命令
输入命令后使用waitForReadyRead等待响应，如果超时就进行重发，且重发次数不能超过5次，代码如下：
（0）Qt::AutoConnection + waitForReadyRead（不能解决超时重发问题）
    /******************************************************************************/

    // 在这之前已连接信号readyRead和槽函数receive_reply
    connect(myPort,SIGNAL(readyRead()),this,SLOT(receive_reply()),Qt::AutoConnection); // Qt::QueuedConnection
    // 在这之前已获取要写入串口的命令command
    unsigned int t = 1;
    myPort.write(command);
    while (myPort.waitForReadyRead(500) && t <= 5){ // only waitForReadyRead
        qDebug()<<QString::asprintf("第%d次重发",t);
        myPort.write(command);
        ++ t;
    }
    if (t > 5){ //超时
        QMessageBox::critical(this,"设定失败!","设定输入电压失败!请重新输入或检查设备");
    }
    else {
        qDebug()<<"没超时,发送成功!";
    }
    /******************************************************************************/
    假设串口数据回复方一直正常，总会及时的回复数据。
    一方面：receive_reply()函数中使用read/readAll/readLine读取了串口数据,发现串口数据的确能收到数据也是正确的
    另一方面：QLineEdit输入文字后(往串口写入命令)一致在等待串口是否有响应(waitForReadyRead在等readyRead信号),但是总是超时
    【矛盾点】：receive_reply()能够响应,说明readyRead信号肯定是发送出去了；waitForReadyRead超时说明没有收到readyRead信号
    【也就是说waitForReadyRead会阻塞readyRead信号但是不阻塞receive_reply函数的执行】

    根据CSDN：https://blog.csdn.net/joyopirate/article/details/121786794?utm_medium=distribute.pc_aggpage_search_result.none-task-blog-2~aggregatepage~first_rank_ecpm_v1~rank_v31_ecpm-3-121786794-null-null.pc_agg_new_rank&utm_term=qt%E7%9A%84waitforreadyread&spm=1000.2123.3001.4430
    这位博主认为的解释是：
    ① waitForReadyRead会导致当前进程阻塞，然后就算readyRead信号发出了也无法响应。 （实际测试确实如此）
    ② 完全不连接这个ReadyRead，这个waitForReadyRead函数是可以正常工作的。（经过测试，注释掉readyRead和receive_reply的连接,发现就不会超时的确可以正常工作，但是这种做法是消极的因为receive_reply函数是必须要使用的）
    ③ 无论使用 Qt::DirectConnection 还是 Qt::QueuedConnection，槽函数(博主说的应该是这里的receive_reply)都是在主线程（串口所在的线程）执行的。 （我觉得也是对的，因为receive_reply函数在主线程和readyRead连接的,不管哪种连接方式都是主线程）
    ④ 在绑定了readyRead()的我们自己写的槽函数中，不要进行读取数据的操作，就也不会超时。（经过测试，确实如此，如果receive_reply什么也不做，确实不会超时，但是显然这种方法不好，这样等于不使用readyRead）
    ⑤ 将readyRead()与receive_reply槽函数绑定时，使用Qt::QueuedConnection不会超时。（从结果来看，确实都能解决问题）
    connect(myPort,SIGNAL(readyRead()),this,SLOT(receive_reply()),Qt::QueuedConnection); // 使用队列连接

然后我尝试了5个解决方案（其中有3个解决了问题）：
（1）Qt::AutoConnection+waitForReadyRead+feedbackval（解决超时重发问题）
    既然并不阻塞receive_reply槽函数执行，那么可以在waitForReadyRead循环之前用一个变量保存输入值InputVal
    然后在receive_reply收到数据以后，把收到的数据用一个变量feedbackVal保存。然后把输入和反馈值是否相等作为waitForReadyRead事件的条件
    这样只是单纯的利用了waitForReadyRead的延时功能（因为它总是超时，等于此功能没用必须引入新条件辅助结束while循环）
    /******************************************************************************/
    unsigned int t = 1;
    while ((!port->waitForReadyRead(300) ) && // 单纯的延时功能,在该循环内阻塞readyRead但不阻止receive_reply函数执行
                t<=5 &&(qAbs(inputVal-feedbackVal)>=1e-3)) //  还要多判断feedbackval和inputval辅助作为while事件的条件
    {
        // receive_reply函数能够及时的更新feedbackval的情况反馈给这里的while循环
        mutex.lock();
        this->port->write(command);
        mutex.unlock();
        qDebug()<<"超时"<<t<<"次";
        ++t;
    }
    if (t<5)
    {
        QMessageBox::information(this,"设定成功","设定输入电压成功!");
        return;
    }
      QMessageBox::critical(this,"设定失败!","设定输入电压失败!请重新输入或检查设备");
    /******************************************************************************/
（2）Qt::AutoConnection+timer+feedbackval（不能解决超时重发问题）
    但是这样的话，似乎waitForReadyRead失去了其意义，仅仅起到了延时作用，所以我尝试使用一个普通的定时循环代替waitForReadyRead，看看能不能用
    从debug结果来看情况更糟糕，while事件不仅会阻塞readyRead信号还让receive_reply函数无法执行(之前仅仅是晚些收到readyRead而不会影响receive_reply函数执行,只是有些不同步)
    所以我才体会到，waitForReadyRead不仅仅作为延时，它的至少起到了不阻碍receive_reply函数的调用，普通事件循环依然会阻止
    /******************************************************************************/
    unsigned int t = 1;
    // 这里会发现总是超时,因为while循环卡住了receive_reply函数的执行无法给feedbackVal反馈
    // 所以还不能用普通的延时循环,必须使用waitForReadyRead的延时
    while (!(qAbs(inputVal-feedbackVal)<1e-3) && (t<=5)) // 不仅阻塞readyRead还阻塞receive_reply函数
    {
        // 创建一个延时,给300ms让串口收到数据进行处理设置feedbackVal
         if (timer.elapsed()>300) // 如果等待了300ms还不满足条件就++t
         {
            qDebug()<<QTime::currentTime()<<" "<<QString::asprintf("第%d次重发",t);
            this->port->write(command);
            ++t;
            timer.restart();
         }
    }
    if (t<5)
    {
        QMessageBox::information(this,"设定成功","设定输入电压成功!");
        return;
    }
    QMessageBox::critical(this,"设定失败!","设定输入电压失败!请重新输入或检查设备");
    /******************************************************************************/
（3）Qt::QueueConnection + waitForReadyRead（解决超时重发问题）
    （0）中的代码没有任何变化，仅仅将连接信号的方式从Qt::AutoConnection改为了Qt::QueueConnection，发现没有阻塞信号也不阻塞槽函数执行
（4）Qt::QueueConnection + waitForReadyRead + feedbackval（解决超时重发问题）
    （1）中的代码没有任何变化，仅仅将连接信号的方式从Qt::AutoConnection改为了Qt::QueueConnection，发现没有阻塞信号也不阻塞槽函数执行
    但是显然（4）比（3）更好，因为（0）中的代码只能判定确实收到了数据，但是数据不一定是对的，所以应当考虑双保险，也就是（4）的做法
（5）Qt::QueueConnection + Timer + feedbackval（不能解决超时重发问题）
    （2）中的代码没有任何变化，仅仅将连接信号的方式从Qt::AutoConnection改为了Qt::QueueConnection，发现依然阻塞信号和槽函数的执行
    所以结论可以知道，超时重发还就只能使用waitForReadyRead不能使用自己的定时循环，而且失效问题使用Qt::QueueConnection解决。

总结：
① 后台定时300ms固定查询,所以定时器的timeout信号绑定了一个发送查询命令的函数send_query()
② 发送查询()内部往串口写数据,因为每300ms都会固定重发,即使硬件没有收到也不用作什么超时处理,因为超时也是重发
③ 而串口一旦open,只要串口有数据,就会有readyRead信号,readyRead绑定了receive_reply函数,是唯一的一个
④ receive_reply函数只有1个,所以必须处理不同类型的数据,除了固定查询还有界面组件的槽函数,例如未来会增加的电压、电流、功率的输入设定
⑤ 所以receive_reply函数必须同时处理不同类型的数据。大方向固定查询单作一类,因为返回的数据有好几条带有分号;而其它的设定查询只会返回1条数据
⑥ 设定查询命令返回的数据必须要知道是谁发的命令,才能作对应的处理;如果知道是谁发的命令,但是没有数据返回还要做超时反馈处理
⑦ 超时反馈处理能想到的函数就是waitForReadyRead
    设想的是等待500ms没有readyRead信号,也就不能执行receive_reply函数,那么waitForReadyRead就会一直等待
    然后如果有readyRead信号就会执行receive_reply函数,waitForReadyRead就不会等待
    但是这是1个设想的情况,实际不能用这套机制来得到超时重发的反馈结果。

    如果是AutoConnection,结果总是超时,因为串口数据实际是正常的进来了,readyRead信号也有,但是它被waitForReadyRead事件卡住了,receive_reply执行事件排到后边
    也就是说永远会超时,事件结束以后执行receive_reply,而不是超时判断过程中执行receive_reply得到结果给waitForReadyRead事件一个反馈是继续重发还是终止
    既然waitForReadyRead超时不起作用,那就换成别的条件,receive_reply因为可以正常执行,所以接收到数据以后反馈给this->feedbackVal
    waitForReadyRead事件通过检测qAbs(this->feedbackVal,this->InputVal)<1e-3来判定是否设定和查询的结果一致,一致的话提前终止否则提示失败
    这是一个【曲线救国】的做法可以解决问题！
    
    这时候我继续想，既然waitForReadyRead的超时功能都没用了,它似乎仅仅起到了一个延时的作用,干嘛不拿掉换一个直接延时的定时器不就好了?
    经过实际测试，反而更加糟糕，不仅收不到readyRead信号也阻塞了receive_reply函数的执行，这就说明waitForReadyRead绝不仅仅起到了延时的作用
⑧ 根据csdn提供的方案，仅仅将连接信号的方式从Qt::AutoConnection改为了Qt::QueueConnection，发现是可以解决问题的
  但是只能使用waitForReadyRead，不能使用自定义的timer延时。
⑨ 既然改为Qt::QueueConnection就能成功，就很有必要查看这个枚举值的含义是什么。

enum Qt::ConnectionType {

    // 默认连接方式,如果接收者位于发出信号的线程中,则使用Qt::DirectConnection否则使用Qt::QueuedConnection,连接类型在信号发出时确定
    // 从qt文档的说明来看,因为接收者receive_reply和发出者lineEdit的槽函数确实都同一线程,所以默认使用这种方式
    Qt::AutoConnection = 0, 

    // 发出信号时立即调用槽函数,该槽函数会在信号发出的线程中执行
    Qt::DirectConnection = 1,

    // 当控制返回到接收者线程的事件循环时调用该槽函数,槽函数在接收者的线程中执行
    // 也就是说可以不在信号readyRead发出的线程中执行,这也是为何waitForReadyRead阻塞了readyRead但是不会阻塞receive_reply
    // Qt额外对此种连接提出了警告,参数必须是Qt元对象系统已知的类j型,因为Qt需要复制参数以将它们存储在幕后的事件中
    // 换句话说就是信号函数和槽函数的参数必须是Qt自带的也就是Q打头的数据类型,不能是自定义的数据类型否则也会连接失败
    // 使用自定义类型必须在建立连接之前调用qRegisterMetaType()来注册数据类型
    Qt::QueuedConnection = 2,

    // 与Qt::QueuedConnection相同,只是信号线程会阻塞直到槽函数返回
    // 如果接收者位于信号线程中,则不得使用此连接,否则应用程序将死锁
    // 也就说readyRead信号会卡住等待recive_reply,但是同一线程中recive_reply又会等待readyRead就会死锁
    Qt::BlockingQueuedConnection = 3,

    // 这是一个可以使用按位OR与上述任何一种连接类型组合的标志
    // 当设置了Qt::UniqueConnection时，如果连接已经存在(即如果相同的信号已经连接到同一对象的同一槽函数)
    // 则QObject::connect()将失败,这个标志是在Qt 4.6中引入的,也就声明连接必须是唯一的,否则失败
    Qt::UniqueConnection = 0x80
}
