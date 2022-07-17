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

至今遇见的有价值的问题、技巧等（序号从大到小倒序）：
8. 中文乱码的问题
(1) 使用QTextStream的时候设置流自动检测UniCode
QTextStream stream(&file);
stream.setAutoDetectUnicode(true); // 但是这种方法不是全局的
(2) main函数使用QTextCodec设置全局启用
int main()
{
    QTextCodec * code = QTextCodec::codecForName("UTF-8");
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
    5.2 paintEvent():窗口绘制事件,可以用来加入背景图片
    void TestMultiWindow::paintEvent(QPaintEvent *event)
    {
        Q_UNUSED(event);
        QPainter painter(this);
        // void QPainter::drawPixmap(int x, int y, int width, int height, const QPixmap &pixmap);
        // 使用给定的宽度width和高度height将像素图绘制到位置 (x, y) 的矩形中
        int x  = 0, y = ui->toolBar->height(), width = this->width(); // 位置在工具栏下方,左上角是(0,0),所以y是工具栏高度,x就是0
        int height = this->height()-ui->toolBar->height()-ui->statusbar->height(); // 图片的高度就是主窗口高度减去状态栏和工具栏的高度
        painter.drawPixmap(x,y,width,height, QPixmap(":/images/back2.jpg"));
    }
    5.3 showEvent():窗口显示时触发的事件
    5.4 mouseMoveEvent():鼠标移动事件
    5.5 mouseReleaseEvent():鼠标键释放事件
    5.6 mousePressEvent:鼠标键按下事件
    5.7 keyPressEvent():键盘按键按下事件
    5.8 keyReleaseEvent():键盘按键释放事件

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
/******************************************************************************/
// 在这之前已连接信号readyRead和槽函数receive_reply
connect(myPort,SIGNAL(readyRead()),this,SLOT(receive_reply()),Qt::AutoConnection); // Qt::QueuedConnection
// 在这之前已获取要写入串口的命令command
unsigned int t = 1;
myPort.write(command);
while (myPort.waitForReadyRead(50) && t <= 5){
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
【矛盾点】：receive_reply()能够响应,说明readyRead信号肯定是发送出去了；waitForReadyRead超时说明没有readyRead信号发出

根据CSDN：https://blog.csdn.net/joyopirate/article/details/121786794?utm_medium=distribute.pc_aggpage_search_result.none-task-blog-2~aggregatepage~first_rank_ecpm_v1~rank_v31_ecpm-3-121786794-null-null.pc_agg_new_rank&utm_term=qt%E7%9A%84waitforreadyread&spm=1000.2123.3001.4430
这位博主认为的解释是：
① waitForReadyRead会导致当前进程阻塞，然后就算readyRead信号发出了也无法响应。 （√，我也这么认为，所以我觉得可能的一个解决方案是定义一个工作子线程类，在run()函数使用waitForReadyRead函数）
② 完全不连接这个ReadyRead，这个waitForReadyRead函数是可以正常工作的。（经过测试，注释掉readyRead和receive_reply的连接,发现就不会超时的确可以正常工作，但是显然不连接就意味着不使用readyRead了,收发逻辑无法分开写）
③ 无论使用 Qt::DirectConnection 还是 Qt::QueuedConnection，槽函数(博主说的应该是这里的receive_reply)都是在主线程（串口所在的线程）执行的。 （我觉得也是对的，因为receive_reply函数在主线程和readyRead连接的,不管哪种连接方式都是主线程）
④ 在绑定了readyRead()的我们自己写的槽函数中，不要进行读取数据的操作，就也不会超时。（经过测试，确实如此，如果receive_reply什么也不做，确实不会超时，但是显然这种方法不好，这样等于不使用readyRead）
⑤ 将readyRead()与我们自己写的槽函数绑定时，使用Qt::QueuedConnection不会超时。（经过测试，问题得到解决，不会超时）（更新，只解决了一半问题）
connect(myPort,SIGNAL(readyRead()),this,SLOT(receive_reply()),Qt::QueuedConnection); // 使用队列连接
⑥ 使用Qt::QueuedConnection，将槽函数放到了连接到该信号的槽函数队列比较后的位置
（调用waitForReadyRead时，其实里面也执行了类似信号槽的绑定，而且这个绑定应该是 Qt::DirectConnection）
因此在信号发出之后，先执行waitForReadyRead函数，然后再执行自己的函数receive_reply。

【新问题】：第⑤条不是不会超时，当应用程序刚启动时，第一次QLineEidt的槽函数响应后，进入waitForReadyRead循环，即使串口发送了数据依然会超时
当waitForReadyRead循环终止之后，readyRead的槽函数receive_reply才响应之前的串口已发送的数据,所以首次调用时Qt::QueuedConnection还是阻塞了线程
但是QLineEidt的槽函数再次响应，进入waitForReadyRead循环后就不超时了,好像一切恢复正常
Qt文档说的如果在receive_reply函数中调用waitForReadyRead,就不会发送readyRead信号
现在看起来即使在其他函数调用也会导致不会发送readyRead信号，但是可能因为Qt::QueuedConnection的原因后续就跟上了，开始发送readyRead信号
但是对用户来说，他永远不知道为何第一次设定命令总是会失败，后边就正常，这种情况还是要解决的

再回过头来看Qt::AutoConnection和Qt::QueuedConnection的使用区别：
Qt::QueuedConnection：超时问题解决了一半，首次进入waitForReadyRead循环一定会阻塞readyRead信号的发送然后对应的槽函数receive_reply无法执行
    waitForReadyRead循环结束后，readyRead信号发送才执行了槽函数。之后再进入waitForReadyRead循环，恢复正常不超时
Qt::AutoConnection：一定超时，阻塞readyRead信号，但是这里是阻塞收不到信号，而不是阻塞发出信号，在waitForReadyRead循环事件期间receive_reply槽函数可以执行

现在诞生了2个解决方案：
一、使用Qt::AutoConnection，既然并不阻塞receive_reply槽函数执行，那么可以在waitForReadyRead循环之间用一个变量保存输入值InputVal
    然后在receive_reply收到数据以后，把收到的数据用一个变量feedbackVal保存。然后在waitForReadyRead循环结束后，多一层判断，
    如果InputVal=feedbackVal，依然判定成功而不是失败。
    /******************************************************************************/
    this->port->write(command); 
    this->inputVal = text.toDouble(); // 保存用户想要设定的命令参数,用于在接收数据时比较,浮点数可以不精确相等
    unsigned int t = 1;
    while ((!port->waitForReadyRead(500) || !this->setVariableAccepted) && // 串口没有反馈数据重发或回馈设定失败重发
                t<=5 ) //  且重发次数不超过5次时while会执行
    {
        qDebug()<<QString::asprintf("第%d次重发",t);
        this->port->write(command);
        ++t;
    }
    if (t <= 5)
    {
        QMessageBox::information(this,"设定成功","设定输入电压成功!");
        return;
    }
    //即使t>5,如果2个值匹配了依然不认为超时
    if (qAbs(feedbackVal-inputVal)<1e-3)
    {
        QMessageBox::information(this,"设定成功","设定输入电压成功!");
        return;
    }
    this->setVariableAccepted = false;
    QMessageBox::critical(this,"设定失败!","设定输入电压失败!请重新输入或检查设备");
    ui->lineEdit->clear();
    /******************************************************************************/
    
    但是这样的话，似乎waitForReadyRead失去了其意义，仅仅起到了延时作用（不完全失去），因为这个循环一定会被判定重发,总是重发5次
    所以我尝试使用一个普通的定时循环代替waitForReadyRead，结果发现依然存在问题，依然会出现5次都判定重发的情况
    从debug结果来看，while定时卡住，结束以后才会执行receive_reply函数，就像使用Qt::QueuedConnection的情况一样
    所以我才体会到，waitForReadyRead不仅仅作为延时，它的事件循环内才可以不阻碍receive_reply函数的调用，普通事件循环依然会阻止
    /******************************************************************************/
    this->port->write(command); 
    this->inputVal = text.toDouble(); // 保存用户想要设定的命令参数,用于在接收数据时比较,浮点数可以不精确相等
    QTime timer;
    timer.start();
    unsigned int t = 1;
    while (!this->setVariableAccepted && (t<=5)) // 如果收到的数据和设置的不相等且不超过5次时可以继续重发
    {
        // 创建一个延时,给500ms让串口收到数据进行处理设置feedbackVal
         if (timer.elapsed()>500) // 如果等待了500ms还不满足条件就++t
         {
            qDebug()<<QTime::currentTime()<<" "<<QString::asprintf("第%d次重发",t);
             if (this->setVariableAccepted)
            {
                QMessageBox::information(this,"设定成功","设定输入电压成功!");
                return;
            }
            this->port->write(command);
            ++t;
            timer.restart();
         }
    }
    QMessageBox::critical(this,"设定失败!","设定输入电压失败!请重新输入或检查设备");
    ui->lineEdit->clear();
    this->inputVal = 0.0;
    /******************************************************************************/

    根据之前的debug结果，还是采用waitForReadyRead去延时，从测试结果来看，暂时没有什么问题。
    /******************************************************************************/
    mutex.lock();
    mutex.unlock();
    this->port->write(command);
    this->inputVal = text.toDouble(); // 保存用户想要设定的命令参数,用于在接收数据时比较,浮点数可以不精确相等
    unsigned int t = 1;
    while ((!port->waitForReadyRead(300) ) && // 单纯的延时功能,利用它在Qt::AutoConnection模式下可以在该循环内不阻止receive_reply函数执行
                t<=5 ) //  重发次数不超过5次时while会执行
    {
        // 单单setVariableAccepted情况还不行,因为用户更改输入值以后setVariableAccepted还没来得及变化保持上次的true
        if (this->setVariableAccepted && (qAbs(inputVal-feedbackVal)<1e-3)) // 这样receive_reply函数能够及时的更新setVariableAccepted的情况反馈给这里的while循环
        {
            QMessageBox::information(this,"设定成功","设定输入电压成功!");
            return;
        }
        mutex.lock();
        this->port->write(command);
        mutex.unlock();
        ++t;
    }
    QMessageBox::critical(this,"设定失败!","设定输入电压失败!请重新输入或检查设备");
    ui->lineEdit->clear();
    this->inputVal = 0.0;
    /******************************************************************************/
二、使用Qt::QueuedConnection，这个问题只在启动时会出现问题，但是这个问题也是不好解决的
    我的想法是定义一个类继承QThread,run()函数内运行waitForReadyRead循环,这个类显然还需要定义私有属性port
    主线程创建的myPort还必须交给这个port属性,然后通过子线程的运行可能能够不阻止readyRead信号发射了,不过这可能很麻烦,而且也不一定能成功
    根据第③条博主的看法，很有可能因为连接信号是主线程完成的，还是会收不到readyRead信号