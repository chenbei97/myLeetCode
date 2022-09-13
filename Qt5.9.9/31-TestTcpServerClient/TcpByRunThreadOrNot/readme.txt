使用线程有2种方式：

① 第一种是创建工作类基于QObject派生
然后在主线程中创建QThread和工作对象，并使用moveToThread方法将工作对象移动到QThread中执行     
QThread * t = new QThread; // 创建线程对象
SendFile * worker = new SendFile; // 创建工作任务对象(发送文件)
worker->moveToThread(t); // 让任务在子线程执行

② 第二种是派生自QThread，然后重载run函数，定义自己的工作任务

一般来说由于类可维护的缘故，第一种方法是更好的方式，否则修改代码只能在run函数完成，不容易维护

------------------------------------------------------------------------------------------------

ClientSendFile这里演示了第一种方式：
① 主线程的信号 => 工作线程的函数
工作线程定义了2个公共函数，connectHost(QString ip, ushort port)和sendFile(QString filepath)
和主线程的2个信号对应，readyConnect(QString ip, ushort port)和sendFile(QString path)
这两个信号在创建工作对象和QThread对象后就进行绑定
connect(this,&Dialog::readyConnect,worker,&SendFile::connectHost); // 主线程=>工作线程(开始连接)
connect(this,&Dialog::sendFile,worker,&SendFile::sendFile); // 主线程=>工作线程(开始发送文件)
至于这2个信号的发射就可以由按钮组件来进行控制，这样比较灵活
QPushButton::clicked => emit Main::readyConnect => worker::connectHost
QPushButton::clicked => emit Main::sendFile => worker::sendFile
② 工作线程的信号 => 主线程的函数
工作线程定义了3个信号，connected()、disconnected()、sendPercentProgress(int percent)
主线程也定义了对应的槽函数(匿名函数)，这样可以在
连接成功发送消息对话框和开启发送文件按钮使能、断开连接后清除QThread和worker对象、同时显示发送文件的百分比进度

------------------------------------------------------------------------------------------------

ServerSendFile演示了第二种方式：

第二种方式又分为两类：信号槽传递和构造函数传参

构造函数传参又可以分为两类：
可以传递整个指针也可以传递部分参数，例如串口通信可以只传递串口的名称和波特率等必要的信息，也可以整个指针进行传递
这里TCP通信同样如此，可以传递套接字描述符也可以传递整个套接字指针
注：只要是传递指针，指即串口和套接字指针的open和close均不能在主线程使用，只能在子线程使用
因为是重载Thread的第2种方式，所以主线程可以控制的是子线程的start，然后子线程负责执行指针的open和close操作
并在任务结束后可以发送结束的信息，让主线程清理子线程的资源，也就是调用quit,wait和deleteLater函数

1) 构造函数传递指针：
dialog.cpp mTcpServer响应newConnection信号,然后获取套接字指针传递给工作线程
QTcpSocket * mTcpSocket = mTcpServer->nextPendingConnection();
ReceiveFile * worker = new ReceiveFile(mTcpSocket);
worker.start()
...
之后在工作线程中
receivefile.cpp 用传递来的指针初始化内部私有套接字指针，然后对readyRead信号响应

2) 构造函数传递套接字描述符：
传递指针的方式可能在Qt的低版本会提示无法在子线程中使用该指针，就必须使用传参的方式
首先必须重载QTcpServer
newtcpserver.cpp派生自QTcpServer,重载了incommingConnection函数，会在新连接到来时发射newDescriptor信号
newreceivefile.cpp的区别只是构造函数的参数从指针变为套接字描述符,内部的套接字是直接new的而不是传递进来的
mTcpSocket = new QTcpSocket(this);
mTcpSocket->setSocketDescriptor(descriptor);
...
newdialog.cpp mTcpServer不再响应newConnection信号,而是响应newDescriptor信号,mTcpServer是派生版本的服务器对象
NewReceiveFile * worker = new NewReceiveFile(descriptor);
worker->start();
... 

------------------------------------------------------------------------------------------------

如果不使用线程，Server和Client演示了简单的TCP通信。