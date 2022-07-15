一、读取之前的判断
(1) 判断字节有效数,如果没有读取,这个返回的值会越来越大
qDebug()<<"before: "<<this->port->bytesAvailable();

                (1.1)关联函数1
                qint64 QSerialPort::readBufferSize() const;
                默认值是0,这样意味着缓冲区没有限制确保不会丢失数据
                但是不读取的话可能会耗尽内存

                (1.2)关联函数2
                void QSerialPort::setReadBufferSize(qint64 size);
                this->port->setReadBufferSize(1024);
                如果有上限,例如设置了缓冲区大小：

(2) 判断是否可以读取一行
qDebug()<<"canReadLine = "<<this->port->canReadLine();
这个函数可以重写,也就是可以定义一个串口类继承QSerialPort
bool CustomDevice::canReadLine() const
{
      return buffer.contains('\n') || QIODevice::canReadLine(); // 这样必须包含\n才能看成1行
}
bool QIODevice::canReadLine() const
{
    Q_D(const QIODevice);
    return d->buffer.indexOf('\n', d->buffer.size(), // \n必须在末尾才会看作1行
                             d->isSequential() ? d->transactionPos : Q_INT64_C(0)) >= 0;
}
二、读取数据
(1) readLine读取1行
qint64 QIODevice::readLine(char *data, qint64 maxSize);
data的大小可以随便定,maxSize表示最多只能读取的字节数
因为存在终止符'\0'总是会被添加进数据的末尾.所以maxSize必须比1大
认为是1行的条件有3个：
1、读取到1个\n字符认为是换行
2、读取了maxSize-1字节认为是换行
3、检测到设备数据结束
显然这些条件不能够保证读取的是自己想要的一行,例如想要的一行是这样：
canReadLine =  true lineLength =  27  buf =  9.001111;0.030000;0.026000（共26个字符+1个换行符）
很可能出现这样的情况：
canReadLine =  true lineLength =  10  buf =  ;0.020000（读取到了1个换行符在末尾）
canReadLine =  false lineLength =  24  buf =  9.002317;0.030004;0.2701（没有读取到换行符）
canReadLine =  true lineLength =  3  buf =  04（读取到1个换行符在末尾）
canReadLine =  false lineLength =  8  buf =  9.002445（没有读取到换行符）
解决这种一种方法是重定义canReadLine函数。
一个例子：
QFile file("box.txt");
if (file.open(QFile::ReadOnly)) {
        char buf[1024];
        qint64 lineLength = file.readLine(buf, sizeof(buf));
        if (lineLength != -1) {
        // the line is available in buf
        }
}
读取1行的重载版本
QByteArray QIODevice::readLine(qint64 maxSize = 0);
从设备读取一行，但不超过 maxSize 个字符，并将结果作为字节数组返回。
该功能无法报错，返回一个空的 QByteArray 可能意味着当前没有数据可供读取，或者发生了错误。
例子：
auto t = this->port->readLine(); // 可以使用默认参数0,也可以指定
// auto t = this->port->readLine(1024); 别无二致
qDebug()<<t;

(2) readAll函数读取全部
QByteArray QIODevice::readAll();
从设备中读取所有剩余数据，并将其作为字节数组返回。
该功能无法报错，返回一个空的 QByteArray 可能意味着当前没有数据可供读取，或者发生了错误。
所以一般要和bytesAvailable()配合使用
例子：
while (this->port->bytesAvailable())
{
      QByteArray data = this->port->readAll();
      qDebug ()<<data;
}

(3) read函数
此函数和readLine很相似。
qint64 QIODevice::read(char *data, qint64 maxSize);
最多从设备读取 maxSize 个字节到数据中，并返回读取的字节数。
如果发生错误，例如尝试从以 WriteOnly 模式打开的设备进行读取时，此函数将返回 -1。
当没有更多数据可供读取时，返回 0。但是，超过流末尾的读取被认为是错误的，因此在这些情况下（即在关闭的套接字上读取或在进程终止后读取）此函数返回 -1。
例子：
char buf[1024;
qint64 len = this->port->read(buf,sizeof(buf));
qDebug()<<"lineLength = "<<len<<" buf = "<<buf;

重载版本：QByteArray QIODevice::read(qint64 maxSize);
从设备读取最多 maxSize 个字节，并将读取的数据作为 QByteArray 返回。
该功能无法报错，返回一个空的 QByteArray 可能意味着当前没有数据可供读取，或者发生了错误。
例子：
auto bytes = this->port->read(1024); // 区别于readLine必须指定参数maxSize
qDebug()<<bytes;

三、串口信号
(1) readyRead()信号
void QIODevice::readyRead();
每次有新数据可用于从设备的当前读取通道读取时，都会发出一次此信号。
它只会在新数据可用时再次发出，例如当新的网络数据有效负载到达您的网络套接字时，或者当新的数据块已附加到您的设备时。
readyRead() 不会递归发出；如果您重新进入事件循环或在连接到 readyRead() 信号的插槽内调用 waitForReadyRead()，则不会重新发送该信号（尽管 waitForReadyRead() 仍可能返回 true）。
实现从 QIODevice 派生的类的开发人员注意：当新数据到达时，您应该始终发出 readyRead() （不要仅仅因为缓冲区中还有数据要读取而发出它）。不要在其他条件下发出 readyRead()。

需要实现绑定1个接收串口数据的槽函数
connect(this->port,SIGNAL(readyRead()),this,SLOT(receive_reply()));
                (1.1) 关联的函数1：waitForReadyRead
                                函数原型为：virtual bool waitForReadyRead(int msecs);
                                此函数使用时会阻塞,它解除阻塞需要2个条件之一：
                                1. 有新的数据可以读取,并发出了readyRead信号
                                2. 指定的时间msecs超时,如果msecs=-1说明没有超时限制,就必须等待readRead,否则一直等待读取
                                如果有新数据可供读取，则返回 true；否则返回 false（如果操作超时或发生错误）
                                如果在槽函数receive_reply()函数中调用此函数,那么串口不会再发送readyRead信号,因为在等待好读取
                                需要注意的是：从主 (GUI) 线程调用此函数可能会导致用户界面冻结
(2)bytesWritte()信号
void QIODevice::bytesWritten(qint64 bytes);
每次将数据的有效负载写入设备的当前写入通道时，都会发出此信号。 bytes 参数设置为写入此有效负载的字节数。
bytesWritten() 不是递归发出的；如果您重新进入事件循环或在连接到 bytesWritten() 信号的插槽内调用 waitForBytesWritten()，则不会重新发送该信号（尽管 waitForBytesWritten() 仍可能返回 true）。

可以实现绑定1个写入串口数据的槽函数
connect(this->port,SIGNAL(bytesWritten(qint64)),this,SLOT(write_query(qint64)));
write_query()函数最简单的应用是打印正在写入的字节数
如果事先写入的数据是
this->port->write("MEAS:VOLT?;:MEAS:CURR?;:MEAS:POW?\n"); // 34个字符
qDebug()<<"正在写入的字节数为"<<bytes; // 34个字符
                                (2.1) 关联函数1：waitForBytesWritten
                                函数原型bool QIODevice::waitForBytesWritten(int msecs)
                                此函数使用时会阻塞,它解除阻塞需要2个条件之一：
                                1. 有新的数据已经写入,并发出了bytesWritten信号
                                2. 指定的时间msecs超时,如果msecs=-1说明没有超时限制,就必须等待bytesWritten,否则一直等待写入
                                如果数据的有效负载已写入设备，则返回 true；否则返回 false（即如果操作超时，或者如果发生错误）
                                如果在槽函数write_query()函数中调用此函数,那么串口不会再发送bytesWritten信号,因为在等待好写入
                                需要注意的是：从主 (GUI) 线程调用此函数可能会导致用户界面冻结
                                (2.2) 关联函数2：flush
                                该函数尽可能多地从内部写缓冲区写入底层串口而不阻塞
                                如果写入了任何数据，则此函数返回 true；否则返回假。
                                调用此函数将缓冲的数据立即发送到串口，成功写入的字节数取决于操作系统
                                在大多数情况下，不需要调用此函数，因为一旦控制权返回到事件循环，QSerialPort 类将自动开始发送数据。
                                在没有事件循环的情况下，请改为调用 waitForBytesWritten()。
                                所谓事件循环，就是定时器绑定的send_query()函数,每个周期写入串口命令,这样一般不需要flush和waitForBytesWritten
可能的例子（参见https://forum.qt.io/topic/76151/qt-serialport-canreadline/2）：
output = "@00RD0100003054*""\r\n";
m_Port->write(output);
m_Port->flush();
m_Port->waitForBytesWritten(500);
QByteArray readData = m_Port->readAll();
while (m_Port->waitForReadyRead(500))
readData.append(m_Port->readAll());
qDebug()<< readData;


