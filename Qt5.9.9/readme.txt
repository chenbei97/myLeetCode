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
    // Qt额外对此种连接提出了警告,参数必须是Qt元对象系统已知的类型,因为Qt需要复制参数以将它们存储在幕后的事件中
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
