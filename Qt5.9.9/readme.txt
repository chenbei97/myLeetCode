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
    TCPClient和TCPServer是Qt书上的一对例子
    TCPServerClientOther是Qt文档的例子
    TcpByRunThreadOrNot比较重要，是B站视频的例子，非常清晰演示了如何用2种方式使用线程
    https://www.bilibili.com/video/BV1LB4y1F7P7?p=16

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

42. TestLayOut 介绍关于布局的使用,涉及到的布局类型有QDockWidget,QSplitter,QGridLayout,
    TestSplitter QSplitter的简单使用,关键点在于多个拆分器之间要注意谁是谁的父类,顶级拆分器的父类是主窗口
    TestDockWidget QDockWidget的简单使用,主要关注2个枚举类型DockWidgetFeature和DockWidgetArea
    TestStackedWidget QStackedWidget的简单使用,常与QComboBox/QListWidget配合使用实现翻页效果
    TestGridBoxLayout 综合演示QGridLayout,QBoxLayout的用法,核心函数是addWidget和addLayout
    ComprehensiveExample 综合演示所有布局类型的用法

43. TestLCDNumber 一个简易电子时钟的设计

44. 30kWSourceLoad 30kW源载一体上位机项目

45. TestLocationFunction 测试位置相关的函数size(),geometry(),x(),y(),pos(),frameGeometry(),rect()等

46. AutoTestFramework 使用Qt的自动化测试框架，包括单元测试、数据驱动测试和性能测试的一个示例

47. MyWord 关于文本处理的综合示例,创建一个仿Word的应用

48. MyWeChat 关于UDP的综合示例，创建一个仿微信的应用

【至今遇见的有价值的问题、技巧等（序号从大到小倒序）：】
26. QPlainTextEdit/QTextEdit的单行文字颜色改变
    1) 方法1: 使用QTextCharFormat和QTextCursor实现
    void QueryPanel::setTextLineColor(const QColor &color)
    {// 参考https://blog.csdn.net/iamtoful/article/details/6182445
        QTextCharFormat fmt;
        fmt.setForeground(color);//文字是前景色
        QTextCursor cursor = mDisplayPanel->textCursor();
        cursor.mergeCharFormat(fmt);//光标处合并格式
        mDisplayPanel->mergeCurrentCharFormat(fmt);// 然后文本编辑框合并格式
    }
    2) 方法2: 使用CSS3语法实现,只限于QTextEdit使用
    参考https://blog.csdn.net/chenyijun/article/details/51226133
    textEdit->append(QString("<font color = blue>%1</font> <br>").arg(q));

25. 常见正则表达式
    1) QRegExp("\\s+")
    \f   匹配一个换页符  \n  匹配一个换行符  \r  匹配一个回车符  \t  匹配一个制表符 \v 匹配一个垂直制表符
    以上都属于空白字符,\s表示匹配任何空白字符,\S则是匹配任何非空白字符
    \s+表示匹配上述任何一种空白字符,另外正则表达式前需要转义字符\,所以合并就是\\s+
    2) 其它见 https://blog.csdn.net/ZYC88888/article/details/98479629

24. xml文档的写法
    1) 使用QXmlStreamWriter写入
        QFile file("config.xml");
        QXmlStreamWriter wstream(&file);
        wstream.setAutoFormatting(true);
        wstream.setCodec("UTF-8");
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        wstream.writeStartDocument("1.0"); // 文档的开始
        wstream.writeStartElement("user"); // 根元素的开始

        wstream.writeStartElement("username"); // 用户名元素
        wstream.writeAttribute("id", "1");//元素属性
        wstream.writeCharacters(username);
        wstream.writeEndElement();

        wstream.writeStartElement("password"); // 密码元素
        wstream.writeAttribute("id", "1");//元素属性
        wstream.writeCharacters(pwd);
        wstream.writeEndElement();

        wstream.writeEndElement(); // 根元素的结束
        wstream.writeEndDocument(); // 文档的结束
        file.close();
    2) 使用QDomDocument写入
        QDomDocument doc("config");
        doc.setContent(&file); // 获取了文件的内容
        QDomElement root = doc.documentElement(); // root.tagName()==user 根元素

        QDomElement usernElemnode = doc.createElement("username"); // 新的用户名节点
        usernElemnode.setAttribute("id",n/2+1); // 用户数+1
        QDomText usernTextnode = doc.createTextNode(username); //新用户名的文本
        usernElemnode.appendChild(usernTextnode);

        QDomElement pwdElemnode = doc.createElement("password");// 新的密码节点
        pwdElemnode.setAttribute("id",n/2+1);
        QDomText pwdTextnode = doc.createTextNode(pwd); // 新密码的文本
        pwdElemnode.appendChild(pwdTextnode);

        root.appendChild(usernElemnode); // user根依次添加username和password节点
        root.appendChild(pwdElemnode);

        QString xml = doc.toString(4); // 缩进4字符, qDebug()<<"xml = "<<xml;
        QTextStream stream(&file);
        file.close(); // setContent已经打开了所以要先关闭
        while (!file.isOpen())
        file.open(QIODevice::Truncate|QIODevice::WriteOnly|QIODevice::Text);// 覆盖
        stream<<xml;
        file.close();
    3) 使用QXmlStreamReader访问
        QFile file(currentDir.path()+"/config.xml");
        QXmlStreamReader stream(&file);
        file.open(QIODevice::ReadOnly);
        while (!stream.atEnd())
        {
            if (!file.isOpen()) file.open(QIODevice::ReadOnly);
            if (stream.qualifiedName() == "username")
            {
                if (stream.readElementText() == username)
                {
                    file.close();
                    return true;
                }
            }
            stream.readNext();
        }
        file.close();
    4) 使用QDomDocument访问并修改节点值
        QFile file("config.xml");
        QDomDocument doc;
        doc.setContent(&file);
        QDomElement root = doc.documentElement();
        QDomNode node = root.firstChild();

        while (!node.isNull())
        {
                QDomElement UserNameNode = node.toElement();
                if (UserNameNode.text() == mUserName) //找到这个用户名
                {
                    node = node.nextSibling(); // 下一个节点是旧密码
                    QDomNode oldPwdNode = node.firstChild(); // 拿到旧密码的文本节点
                    node.firstChild().setNodeValue(NewPwdEdit->text());//文本节点更新文字
                    QDomNode newPwdNode = node.firstChild();// 取出新密码节点
                    //qDebug()<<newPwdNode.toText().data(); // 可以打印出新密码的文本节点的文本
                    node.replaceChild(newPwdNode,oldPwdNode); // 替换2个元素节点,因为是替换孩子,所以父节点必须是node(元素节点)
                    // 只更改文本节点,属性id的值没有改变
                }
                node = node.nextSibling();
        }
        QString xml = doc.toString(4);
        QTextStream stream(&file);
        file.close(); // setContent已经打开了所以要先关闭
        file.open(QIODevice::Truncate|QIODevice::WriteOnly|QIODevice::Text);// 覆盖
        stream<<xml;
        file.close();

23. 进度条对话框的使用方法
mTcpSocket->connectToHost(ip,port);
QProgressDialog * dlg = new QProgressDialog(tr("正在尝试连接"),tr("取消连接"),0,400000);
dlg->setWindowTitle(tr("TCP连接"));
dlg->setFont(QFont("Times New Roman",12));
dlg->setFixedSize(400,150);
dlg->setModal(true);
dlg->setAutoClose(true);
dlg->show();
int i = 1;
while (mTcpSocket->state() != QAbstractSocket::ConnectedState &&(i<=400000))
{
        dlg->setValue(i); // 35-45万之间的循环模拟一个进度条,数字太小看不到进度条,太大等待时间有点久
        ++i;
        if (dlg->wasCanceled())
        break;
}

if (mTcpSocket->state() != QAbstractSocket::ConnectedState) // 如果还没连上就报错
{
        QMessageBox::critical(Q_NULLPTR,tr("错误"),mTcpSocket->errorString());
        emit disconnected();
        emit errorCode(TCPERRORSTATE::UnconnectedState);
        return;
}
emit errorCode(TCPERRORSTATE::ConnectedState);
dlg->deleteLater();

22. 信号映射器的使用方法
    注意映射器接收一组无参数信号,有参数不支持
    而且是一类组件的同一个信号映射到同1个函数执行时才有意义,这样依据不同的参数可以执行不同的内容
    不过这些内容都是同一个函数完成的,如果不采用映射就需要每个按钮/动作各自映射到不同的函数执行对象的内容
    现在依据按钮的文字标识可以确定是哪个按钮发生了点击，然后执行对应的功能
    
    void setMapping(QObject *sender, QObject *object);
    void setMapping(QObject *sender, QWidget *widget);
    void setMapping(QObject *sender, const QString &text);

    1) 创建1个映射器
    2) 首先把按钮或者动作在创建的时候绑定clicked或triggered信号到映射器的map()信号
    3) 然后使用setMapping函数,设置按钮或动作和某个对象的关联,这个对象是一种映射关系,将来依靠这个对象来指向1个槽函数

    signalMapper = new QSignalMapper(this); // 创建1个映射器
    // 按钮信号 => 信号映射器槽函数
    for (int i = 0; i < 3; ++i) 
    {
        QPushButton *button = new QPushButton(texts[i]); 
        connect(button, SIGNAL(clicked()), signalMapper, SLOT(map())); // 关联到map()
        signalMapper->setMapping(button, texts[i]); // 绑定的文本映射关系
    }
	// 映射器的信号 => 信号或槽函数,这里clicked信号可以继续关联某个槽函数进行执行,或者直接使用匿名槽函数
    connect(signalMapper, SIGNAL(mapped(QString)),this, SIGNAL(clicked(QString))); 

    例子:
    QList<QAction*> actList;
    actList <<ActAppendRow <<ActAppendCol << ActInsertRow << ActInsertCol
                <<ActRemoveRow <<ActRemoveCol << ActSetAlignLeft << ActSetAlignCenter
               << ActSetAlignRight << ActSetBold << ActSetItalic << ActClearTable << ActResetTable
               << ActImportTxt<< ActExportTxt << ActImportCsv<<ActExportCsv;
    QAction * act;
    QSignalMapper * signalMapper = new QSignalMapper(this);
    foreach(act,actList) {
            connect(act, SIGNAL(hovered()), signalMapper, SLOT(map()));
            signalMapper->setMapping(act,act->text()); // 绑定的文本映射关系
    }
    connect(signalMapper, static_cast<void (QSignalMapper::*)(const QString&)>(&QSignalMapper::mapped),this, [=](const QString& text){
            QString t = tr("工具提示: %1").arg(text);
            mToolTip->setText(t);
    });

21. 菜单动作分组
// 各对齐方式功能项加入同一个菜单项组，这样程序运行的任一时刻用户能且只能选中其中一项
ui->actLeft->setCheckable(true); // 默认是false,先开启选项(必须要做)
ui->actCenter->setCheckable(true);
ui->actRight->setCheckable(true);
QActionGroup *alignGroup = new QActionGroup(this);
//alignGroup->addAction(ui->actLeft);
//alignGroup->addAction(ui->actCenter);
//alignGroup->addAction(ui->actRight);
//Menu->addAction(actLeft);
//Menu->addAction(actCenter);
//Menu->addAction(actRight);
或
Menu->addAction(alignGroup->addAction(ui->actLeft));
Menu->addAction(alignGroup->addAction(ui->actCenter));
Menu->addAction(alignGroup->addAction(ui->actRight));
ui->actLeft->setChecked(true);

20. 列出系统支持的字体家族和字体大小
    QList<int> sizes = QFontDatabase::standardSizes();
    QStringList sizeString;
    for(auto size : sizes) sizeString << QString::number(size);
    ui->sizeComboBox->addItems(sizeString);
    ui->sizeComboBox->setCurrentIndex(ui->sizeComboBox->findText(
        QString::number(this->font().pointSize())
    )); // 跟随当前窗口字体大小
    QFontDatabase base;
    ui->fontComboBox->addItems(base.families(QFontDatabase::Any));
    ui->fontComboBox->setCurrentText(this->font().family()); // 跟随窗口字体风格

19. 关于串口指针/套接字指针无法在工作线程使用的问题
    1) 在主线程创建的对象不能跨线程调用,所以如果指针调用close/start/open等函数就会出错
    2) 如果一定要用指针,有两种方法可以在工作线程使用
        2.1) 就在工作线程中创建指针,不要在主线程创建
            2.1.1) 指针需要的信息可以通过子线程的构造函数传递
                例如串口名称/波特率/套接字信息在子线程创建时就传递,然后子线程内部依据这些信息来创建串口或者套接字
            2.1.2) 指针需要的信息还可以通过信号槽机制传递
                主线程定义传递信息的信号,这个信号可以在某个动作触发例如"开始连接"按钮
                然后子线程定义对应的槽函数,把这些信息传递给子线程内部的指针
        2.2) 还是在主线程创建指针,但是需要使用moveToThread函数把串口指针使用权交给子线程，注意创建指针时候不能指定父对象,否则无法使用moveToThread函数
            2.2.1) 子线程的构造函数以指针作为参数,主线程创建好指针并设置好信息后就可以传递给它
                    切记指针的任何操作无法在主线程使用,主线程只是使用了子线程的start信号,子线程内部来打开串口或者套接字
                    或者如果指针的信息需要变化，那么可以设计一种机制，必须设置过指针的信息才能执行"开始连接"
                    而且一旦开始连接不允许再更改设置指针的信息，"停止连接"后才能设置指针的信息

                    如果不这么设计，主线程可以随时在线程更改指针携带的信息，为了保证同步就必须在子线程设计代码检测串口信息有没有发生变化
                    如果有变化，就关闭指针对象然后重新打开，但这里打开关闭的操作依然是子线程完成的不是主线程
            2.2.2) 使用信号和槽函数也可以传递信息
                    同步机制可能相对简单，例如当串口信息变化时定义信号把信号发射出去
                    然后子线程定义接收此信号的槽函数和一个全局bool值，如果检测有变化就设定bool值为False
                    然后run函数内的while循环可以判断bool值是否为false,如果是就关闭指针并重新打开
                    重新打开成功再把bool值置为true，这样一套机制也是可以的
    3) 一般来说，如果指针需要的信息很少就使用2.1)的方法，就不要传递指针给子线程，而是直接传递信息即可，然后内部检测信息是否变化
        如果指针携带的信息很多，例如串口不仅仅是传递名称和波特率，还有奇偶位、停止位和数据位等等，这样传递多个变量就很麻烦，可以使用2.2)的方法
        
        特别的，如果是定时查询这样的任务，主线程无法直接控制串口的开关，但是可以控制定时器的停止启动
        定时器的timeout信号连接上子线程的start信号，"开始连接"就启动定时器，"停止连接"就停止定时器
        然后子线程需要设计好代码，把每次的timeout看作一次事件让条件变量唤醒线程然后执行，执行完就休眠等待下次timeout

        如果不是定时查询这样的任务，就无需这么复杂的代码，子线程无需while循环，只是把要做的事情写好就行例如就是给串口发送一个查询命令
        那么子线程的run只需要判断串口信息是否发生变化，然后使用port.write()即可
    4) 只要记住：在哪里创建的就在哪里使用，如果想在子线程使用就在子线程创建或者主线程创建然后moveToThread
        需要的任何信息，借助信号槽机制传递并在子线程判断信息是否变化然后执行开关操作
        
18. 注册元对象类型
    例如注册枚举值对象，在一个头文件内声明了2个枚举类型，那么在头文件末尾使用宏声明
    Q_DECLARE_METATYPE(TIMEOUTCODE) 
    Q_DECLARE_METATYPE(SERIALERROR)
    并在main.cpp中注册该类型
    int id1 = qRegisterMetaType<TIMEOUTCODE>("TIMEOUTCODE");
    int id2 = qRegisterMetaType<SERIALERROR>("SERIALERROR");

17. 设置对话框的属性
    setWindowFlag(Qt::Window); // 设置window属性就不会总是让界面在前或者在后
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);//不能更改大小
    setFixedSize(this->geometry().size());
    setWindowModality(Qt::ApplicationModal);// 设置为模态对话框 Qt::NonModal,Qt::WindowModal
    setWindowFlag(Qt::WindowStaysOnTopHint);//保持在前
    setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint); // 添加最大最小化按钮
    Qt::WindowFlags flags = windowFlags();
    setWindowFlags(flags^Qt::WindowCloseButtonHint^Qt::WindowContextHelpButtonHint);// 不想要帮助和关闭按钮

16. 位置函数的区别
    1) this->x(),this->y(),this->pos(),获取整个窗体左上角在桌面上的坐标位置(只有窗口移动事件和左上角为中心调整窗口大小时会影响)
        this->pos().x()=this->x(),this->pos.y()=this->y()
    2) this->frameGeometry()函数获取整个窗体的左上顶点以及宽度和高度
        this->frameGeometry().x()=this->x(), this->frameGeometry().y()=this->y()
        this->frameGeometry().width()≠this->width(), this->frameGeometry().height()≠this->height()
    3) this->frameSize()函数就是this->frameGeometry()函数的width()和height()部分
    4) this->geometry()函数获取的是中央区域的左上顶点坐标x、y以及width和height
        左上顶点坐标是相对于父窗体而言的，如果没有父窗体就是相对于桌面的坐标
        但是因为窗口的标题栏和侧边栏的影响,会让此函数的x()和y()稍大,width()和height()则是稍小
        
        2个x()的差值的1/2就是2个width()的差值,这个值就是窗口侧边栏的宽度,即可以分别使用point和size计算
        siderBar.width() = this->geometry().x()-this->frameGeometry().x()
                         = [this->geometry().topLeft() - this->frameGeometry.topLeft()].x()
                         = [this->frameGeometry().width()-this->geometry().width()] / 2 
        
        至于高度也是同理,区别在于2个height差值得到的是1个标题栏高度+1个侧边栏宽度(底部的侧边栏),即
        titleBar.height() = this->geometry.y() - this->geometry.y()
                          = [this->geometry().topLeft() - this->frameGeometry.topLeft()].y()
                          = this->frameGeometry.height()-this->geometry.height() - siderBar.width()                                   
    5) this->rect()和this->geometry()函数是一样的,区别是左上角顶点永远是(0,0)而不是相对父窗体或者桌面的位置
    6) this->size()=this->geometry().size()=[this->width(),this->height()],也是中央区域
    7) this->baseSize(),保存了小部件的基本尺寸,默认情况下对于新建的小部件是[0,0]
    8) this->sizeIncrement(),保存小部件的尺寸增量,当用户调整窗口大小时
        尺寸将水平移动this->sizeIncrement().width()像素,垂直移动this->sizeIncrement.height()像素
        以 this->baseSize()为基础,首选小部件大小适用于非负整数 i 和 j：
            this->width = baseSize().width() + i * sizeIncrement().width();
            this->height = baseSize().height() + j * sizeIncrement().height();
        请注意虽然可以为所有小部件设置sizeIncrement，但它只影响Window对Dialog不起作用,默认也是[0,0]
    9) this->sizeHint(),保存小部件的推荐大小,如果此属性的值是无效大小,则不推荐大小
        如果此小部件没有布局，则this->sizeHint()的默认实现返回无效大小,否则返回布局的首选大小
    这些函数的区别示例可见45-TestLocationFunction

15. 让QComboBox居中的方法
    QStandardItemModel * model = qobject_cast<QStandardItemModel*>(workMode->model());
    for(int i = 0; i < model->rowCount(); ++i)
    {
        QStandardItem * item = model->item(i);
        item->setTextAlignment(Qt::AlignCenter); //让项居中
    }
    QLineEdit * lineEdit = new QLineEdit;
    lineEdit->setAlignment(Qt::AlignCenter); // 文本框也要居中
    workMode->setLineEdit(lineEdit);

14. QGridLayout控制组件的大小
    必须使用固定大小否则不起作用，同时配合比例关系可以调整
    spinbox->setFixedSize(300,30);
    mainLayout->setColumnStretch(0,1);
    mainLayout->setColumnStretch(1,2);

13. setStyleSheet
    QSpinBox禁用上下拉三角按钮: ->setButtonSymbols(QAbstractSpinBox::NoButtons);
    QToolButton禁止右下角下拉菜单: toolbutton->setStyleSheet("QToolButton::menu-indicator{image:none;}");
    QLabel使用setPalette不能控制颜色,setFont不能控制字体大小：label->setStyleSheet("QLabel{font:bold 64px;background-color: red;color: blue;}");
    QGroupBox去除边框, groupbox->setStyleSheet("QGroupBox{border:none;}");
    
12. 实现下拉项选择颜色
    QStringList colorList = QColor::colorNames();
    qDebug()<<colorList.size(); // 148个
    ui->comboBox->resize(100,30);
    foreach(const QString &color, colorList)
    {6
        QPixmap pix(ui->comboBox->size()); // 这个大小要设置
        pix.fill(QColor(color));// pix是个纯色图标
        ui->comboBox->addItem(QIcon(pix),nullptr); // 添加图标
        ui->comboBox->setIconSize(ui->comboBox->size()); // 这个大小也要设置,因为图标默认方形,这里设置为矩形长度
        ui->comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);//设置这个最好,其它的略短,符合内容大小的调整策略
    }

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

10. 信号与槽函数的连接问题
(1) 信号可以和信号连接
connect(Obj1,SIGNAL(signal1),Obj2,SIGNAL(signal2));//使用场景可能是一个timeout连接一个readyRead信号,然后readyRead绑定了一个槽函数
(2) 同一个信号可以连接多个槽函数
connect(Obj1,SIGNAL(signal),Obj2,SIGNAL(slot1));
connect(Obj1,SIGNAL(signal),Obj2,SIGNAL(slot2));
信号的参数个数必须大于等于槽函数的参数个数,且参数类型要一一对应,缺少的参数是信号的后几个参数
connect(responseLineEdit, &QLineEdit::textChanged, this, &Dialog::activateRunButton);//textChanged信号有参数
void Dialog::activateRunButton(){runButton->setEnabled(true);} // activateRunButton槽函数没有参数
(3) 不同的信号可以连接同一个槽函数
connect(Obj1,SIGNAL(signal1),Obj3,SIGNAL(slot));
connect(Obj2,SIGNAL(signal2),Obj3,SIGNAL(slot));
(4) 如果使用宏SIGNAL和SLOT的方式,槽函数必须有slots声明,还可以使用函数指针的方式,这样的函数不需要使用slot声明
connect(&Obj,Obj::signal,this,&MainWindow::slot);//但是需要使用取址运算符作用域,一般函数指针传递的都是没有重载版本的信号,直接使用即可
(5) 函数指针的方式,如果信号具有重载版本,必须使用static_cast<>静态转换,借助运算符号&和::指明是哪个版本的信号
例如信号&QComboBox::currentIndexChanged参数有const QString&和int的2个版本
将其静态转换为void (QComboBox::*)(const QString &),表示输入参数为const QString&输出参数void的函数指针,且该函数是从属于QComboBox的
QSpinBox的同理valueChanged也有2个版本,但是QLineEdit的textChanged只有1个版本不需要静态转换
// C风格转换
void(Teacher::*teacherSignal)(QString) = &Teacher::hungry; 
void(Student::*studentSignal)(QString) = &Student::treat;
// C++风格转换
connect(serialPortComboBox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
        this, &Dialog::activateRunButton);
connect(waitRequestSpinBox, static_cast<void (QSpinBox::*)(const QString &)>(&QSpinBox::valueChanged),
        this, &Dialog::activateRunButton);
(6) 槽函数中可以使用静态函数sender()和类型转换qobject_cast获取信号的发送者
void on_lineEdit_textChanged(const QString &text)
{
    //....
    QLineEdit * lineEdit = qobject_cast<QLineEdit*>(sender()) ;
}
(7) 如果是匿名函数作为槽函数,当信号具有参数时可以这样做
connect(worker,static_cast<void (SendFile::*)(int)>(&SendFile::sendPercentProgress),
                                    this,[=](int percent){PBar->setValue(percent);});

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
stream.setCodec("UTF-8");
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

7. 选择文件对话框的使用方式
QDir curpath = QDir::current(); // exe路径
curpath.cdUp(); // 回到上一级,也就是工作代码的路径
QString aFileName=QFileDialog::getOpenFileName(this,tr("打开一个文件"),curPath,
                "C++文件(*.h *cpp);;文本文件(*.txt);;所有文件(*.*)");
if (aFileName.isEmpty()) return; //如果未选择文件，退出
// dosomething

6. 标准的文本文件保存内容的代码(QFile+QTextStream)
// 示例1
QFile aFile(aFileName);
if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text))
    return false;
QTextStream aStream(&aFile); //用文本流读取文件
aStream.setAutoDetectUnicode(true); //自动检测Unicode,才能正常显示文档内的汉字
QString str=ui->textEditStream->toPlainText(); //QPlainText的内容可以直接转换为字符串
aStream<<str; //写入文本流
aFile.close();//关闭文件
// 示例2
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
// 示例3
void CSVExport::writeTable(const QString & text) // 私有函数,给文本流写入数据
{
    QString fileName = QFileDialog::getSaveFileName(Q_NULLPTR, tr("CSV文件"), mWorkDir,tr("(*.csv)"));
    if (fileName.isEmpty()) return;
    QFile outFile(fileName);
    outFile.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    QTextStream ts(&outFile);
    ts.setAutoDetectUnicode(true);
    ts.setCodec("UTF-8");
    ts << text;
    outFile.close();
}

5. 标准的文本文件读取内容的代码
5.1 流的方式：（QFile+QTextStream+QFileInfo）
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

5.2 IO的方式：（QFile+QIODevice）
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

4. 窗口可以利用的事件类型
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
    还可以获取父类窗口的指针
    5.2 hideEvent():窗口隐藏事件
    5.3 paintEvent():窗口绘制事件,可以用来加入背景图片
    void Window::paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);
        QPainter painter(this);
        // 使用给定的宽度width和高度height将像素图绘制到位置 (x, y) 的矩形中
        int x  = 0, y = ui->toolBar->height(), width = this->width(); // 位置在工具栏下方,左上角是(0,0),所以y是工具栏高度,x就是0
        int height = this->height()-ui->toolBar->height()-ui->statusbar->height(); // 图片的高度就是主窗口高度减去状态栏和工具栏的高度
        painter.drawPixmap(x,y,width,height, QPixmap(":/images/back2.jpg"));

        // 还有一种使用begin和end的写法
        int x = 0;
        int y = MenuBar->height();
        int height = this->height()- y; //要绘制的高度
        int width = this->width(); // 要绘制的宽度
        QRect rect(x,y,width,height);
        QPixmap pix;
        pix.load(":/images/DH.png");
        QPainter painter; // 不要使用指针的方式,new出来的无法销毁
        painter.begin(this);
        painter.setOpacity(0.2);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.drawPixmap(rect,pix);
        painter.end();

        // or简化
        QPainter p;
        p.begin(this);
        p.setOpacity(0.5);
        p.setRenderHint(QPainter::SmoothPixmapTransform);
        QPixmap pix(":/images/login_back.jpg");
        p.drawPixmap(QPoint(0,0),pix);
        p.end();
        Q_UNUSED(e);
    }
    另外2种方法设置背景图片
        1) setStylSheet{"QDialog{background-image:url()"}}

        2) QPalette pal = dlg->palette();
            pal.setBrush(QPalette::Background,QBrush(QPixmap("")));
            dlg->setPalette(pal);

    5.4 showEvent():窗口显示时触发的事件
    5.5 mouseMoveEvent():鼠标移动事件
    void Window::mouseMoveEvent(QMouseEvent * e)
    {
        if (e->buttons() & Qt::LeftButton) // 鼠标左键按下
        {
            // 鼠标移动到新位置时窗口移动到新位置
            // 注意: 鼠标的新位置就是e->globalPos(),但是move函数要求提供的窗口左上角顶点要移动到的新位置
            // 鼠标新位置减去鼠标相对于窗口左上角顶点的距离relativePos就是窗口左上角顶点的新位置
            // relativePos可以在mousePressEvent()就先计算好,之后拖动窗口不会影响这个相对位置
            this->move(e->globalPos()-relativePos);
            e->accept();
        }
        return QDialog::mousePressEvent(e);
    }
    void Login::mouseMoveEvent(QMouseEvent *e)
    {
        bool isLeftButton = e->buttons() & Qt::LeftButton; // 是左键按下
        bool isDrag = (e->globalPos() - mMouseLastPos).manhattanLength()  > QApplication::startDragDistance();

        if (mMouseMove && isLeftButton && isDrag)
        {
            move(e->globalPos()-mMouseLastPos);//窗口移动到新的位置
            mMouseLastPos = e->globalPos()-pos();//新的相对位置
        }
        return QDialog::mouseMoveEvent(e);
    }
    5.6 mouseReleaseEvent():鼠标键释放事件
    5.7 mousePressEvent():鼠标键单击事件(左键或者右键)
    void Window::mousePressEvent(QMouseEvent * e)
    {
        if (e->button() == Qt::LeftButton)
        {
            relativePos = e->globalPos() - frameGeometry().topLeft();//提供的是整个窗口大小的左上角
            e->accept();
        }
        if (e->button() == Qt::RightButton)
        {
            //...
        }
    }
    oldPos是原来窗口左上角的位置，也就是frameGeometry().topLeft()
    要移动的新位置是newPos，也就是要传递给move函数的新坐标，很显然需要用新的鼠标全局位置减去相对位置就可以
                                    鼠标移动的相对位置、全局位置以及窗口左上角位置(move)之间的关系
            ← - - - - - - - - - - - - - - - gloablX - - - - - - - - - - - →
            ← - - - - - - - - - - - newPosX - - - - - - - - - - → 【newPosX = gloablX - relativeX】
    oldPos→ * * * * * * * * * * * * * * * * * * ↑ ← - - - - - - - - - - - →
            *         * ↑                     * |                         ↑
            *         * | relativeY           * | gloablY                 | 【newPosY = gloablY - relativeY】
            *         * |                     * |                         ↓
            * * * * * * ↓                     * |        newPos→* * * * * * * * * * * * * * * * * *
            * ← - - - - →                     * |               *         * ↑                     *
            *  relativeX                      * |               *         * | relativeY           *
            *                                 * |               *         * |                     *
            *                                 * |               * * * * * * ↓                     *
            * * * * * * * * * * * * * * * * * * ↓ - - - - - - - * ← - - - - →                     *
                                                                * relativeX                       *
                                                                *                                 *
                                                                *                                 *
                                                                * * * * * * * * * * * * * * * * * *
    5.8 mouseDoubleClickEvent():鼠标双击事件                     
    5.9 keyPressEvent():键盘按键按下事件                         
    void MainWindow::keyReleaseEvent(QKeyEvent * e)             
    {
        if (e->modifiers() == Qt::ControlModifiers) // 如果修饰符ctrl被按下
        {
            if (e->key() == Qt::Key_Left) 
                // dosomething
        }
    }
    5.10 keyReleaseEvent():键盘按键释放事件
    5.11 actionEvent():添加工具栏动作事件
    5.12 resizeEvent():调整窗口大小事件
    void MainWindow::resizeEvent(QResizeEvent *e)
    {
      MenuBar->setGeometry(QRect(0,0,e->size().width(),30));
    }
    5.13 hoverEvent():悬停事件
    5.14 timerEvent():定时器事件
    5.15 contextMenuEvent():上下文菜单事件

3. 获取子窗口的父类指针（前提是子窗口在创建时传入了this指针否则它是独立窗口没有父窗口）
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
