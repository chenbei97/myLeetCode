#include "../../inc/tcp/testtcp.h"

TestTcp::TestTcp(QWidget *parent) : QWidget(parent)
{
        QString frame = "0x0002";
        auto lay = new QVBoxLayout(this);
        edit = new QTextEdit;
        connectBtn = new QPushButton(tr("连接"));
        disconnectBtn = new QPushButton(tr("断开"));
        sendBtn = new QPushButton(tr("发送"));
        sendEdit = new QLineEdit(frame);

        auto hlay1 = new QHBoxLayout;
        hlay1->addWidget(connectBtn);
        hlay1->addWidget(disconnectBtn);
        auto hlay2 = new QHBoxLayout;
        hlay2->addWidget(sendBtn);
        hlay2->addWidget(sendEdit);

        lay->addWidget(edit);
        lay->addLayout(hlay1);
        lay->addLayout(hlay2);

        resize(800,600);

        connect(connectBtn,&QPushButton::clicked,this,&TestTcp::onConnect);
        connect(disconnectBtn,&QPushButton::clicked,this,&TestTcp::onDisconnect);
        connect(sendBtn,&QPushButton::clicked,this,&TestTcp::onSend);

        QFile file(getAppDataStandardPath("eosj.json"));
        if (file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            QTextStream stream(&file);
            stream.setCodec("utf-8");
            json = file.readAll();
            file.close();
        }

        //connect(&query,&TcpQuery::parseResult,this,[=](auto d){LOG<<"d = "<<d;});
        //connect(&query,QOverload<const QString&>::of(&TcpQuery::parseError),this,[=](auto d){LOG<<"e = "<<d;});
        connect(&query,QOverload<TcpErrorCode>::of(&TcpQuery::parseError),this,[=](TcpErrorCode error){
            switch (error) {
                    // 请求错误基本不会发生;
                    // 超时回复很有可能,但是概率很小,只要已连接,下位机发了消息不就会出现
                    // 帧错误 就是发送帧为空或者不在命令列表,出现的话检查代码是否有笔误
                    // 空数据错误  高频发生,解析失败的不会放数据,例如需要图片路径但是没有
                    // 这个时候不能正确显示图片,append那个相当于读取了个空的pixmap不是暴力错误没事
                   // 未连接错误,可能发生
                    case TcpErrorCode::UnConnectedErrorCode:break; // 重连需要重发,所以逻辑不写在这
                    default:break;
            }
        });

        onConnect();
}

void TestTcp::onSend()
{
    //test0();
  // test1();
   test2();

//    QJsonObject obj;
//    obj["国家"] = "a";
//    QJsonDocument doc;
//    doc.setObject(obj);
//    qDebug()<<doc.toJson(QJsonDocument::Indented); // 可以看出默认是utf-8 "{\n    \"\xE5\x9B\xBD\xE5\xAE\xB6\": \"a\"\n}\n"
//    qDebug()<<QString("国家").toLocal8Bit();// "\xB9\xFA\xBC\xD2"
//    qDebug()<<QString("国家").toUtf8();//"\xE5\x9B\xBD\xE5\xAE\xB6"
    //qDebug()<<QString("国家").toLatin1();
}

void TestTcp::onConnect()
{
    TcpLoaderPointer->connectToHost(SocketLocalHost,SocketPort);
    TcpLoaderPointer->waitForConnected();
    if (TcpLoaderPointer->isConnected())
    edit->append(tr("<strong><font color = #75FA8D>[%1] 状态:</font></strong> %2")
                 .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss"))
                 .arg("连接成功!"));
    else
        edit->append(tr("<strong><font color = #75FA8D>[%1] 状态:</font></strong> %2")
                     .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss"))
                     .arg("连接失败!"));
}

void TestTcp::onDisconnect()
{
    TcpLoaderPointer->disconnectFromHost();
    edit->append(tr("<strong><font color = #75FA8D>[%1] 状态:</font></strong> %2")
                 .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss"))
                 .arg("断开连接!"));
}

QVariantMap TestTcp::fakeDatafor0x0000() const
{
    QGroupNameVector groupNames;
    QGroupPointVector groupPointLists;
    //QGroupPointNameVector groupNameLists; // 点名称不需要传了

    groupNames <<"组A"<<"组B"<<"组C"; // "\xD7\xE9"
    for(int i = 0; i < 3; i++) {
//        QStringVector vec;
//        vec << QString("%1-%2").arg(groupNames.at(i)).arg(i+1);
//        groupNameLists.append(vec);

        QPointVector pts;
        pts << QPoint(rand()%8,rand()%12)<<QPoint(rand()%8,rand()%12)<<QPoint(rand()%8,rand()%12);
        groupPointLists.append(pts);
    }
    //qDebug()<<groupNames;
    //qDebug()<<groupNameLists;
    //qDebug()<<groupPointLists;
    QVariant v1;
    //QVariant v2;
    QVariant v3;
    v1.setValue(groupNames);
    //v2.setValue(groupNameLists);
    v3.setValue(groupPointLists);

    QVariantMap m;
    m[Field0x0000.objective] = "40x";
    m[Field0x0000.channel] = "phase";
    m[Field0x0000.view] = 289;
    m[Field0x0000.wellsize] = 96;

    m[Field0x0000.groupNames] = v1;
    //m[Field0x0000.groupNameLists] = v2;
    m[Field0x0000.groupPointLists] = v3;

    m[Field0x0000.is_schedule] = 1;
    m[Field0x0000.total] = 36000;
    m[Field0x0000.duration] = 2100;
    m[Field0x0000.count] = 17;
    auto datetime = QDateTime::currentDateTime();
    m[Field0x0000.start] = datetime;
    m[Field0x0000.end] = datetime.addSecs(36000);
    return m;
}

QVariantMap TestTcp::fakeDatafor0x0002() const
{// {"frame": "0x0002","repeat": 0,"point.x":3,"point.y":3,"path":"C:/Users/22987/Desktop/EOSI/images/cell.png"}
    QVariantMap m;
//    int x = -1,y = -2;
//    while (x == y) {
//        x = rand()%96+1;
//        y = rand()%96+1;
//    }
    m[Field0x0002.pointx] = 3;
    m[Field0x0002.pointy] = 3;

    return m;
}

#define sendText (tr("<strong><font color = #75FA8D>[%1] 发送:</font></strong> %2") \
            .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss")))
#define resendText (tr("<strong><font color = #75FA8D>[%1] 正在重新发送:</font></strong> %2") \
            .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss")))
#define recvText (tr("<strong><font color = #75FA8D>[%1] 回复:</font></strong> %2") \
            .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss")))
#define errorText (tr("<strong><font color = #75FA8D>[%1] 错误:</font></strong> %2") \
            .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss")))

void TestTcp::test2()
{ // 模拟预览
    static TcpAssemblerController assembler;
    QPointVector points;
    for(int i = 0; i <10; i++) points<<QPoint(i,i);
    //qDebug()<<points;

    static QVariantMap m;
    static QByteArray msg;

    foreach(auto point, points)
    {
        m[Field0x0002.pointx] = point.x();
        m[Field0x0002.pointy] = point.y();
        assembler.assemble(TcpFramePool.frame0x0002,m);
        msg = assembler.message();
        edit->append(sendText.arg(QString::fromLocal8Bit(msg)));
        query.exec(TcpFramePool.frame0x0002,msg);
//        int i = 0;
//        while (query.haveError() && i < 3) {
//            edit->append(errorText.arg(query.errorString()));
//            edit->append(resendText.arg(QString::fromLocal8Bit(msg)));
//            query.exec(TcpFramePool.frame0x0002,msg); // 有错误会重发
//            ++i;
//        }
        // 重发没到3次,exec执行完毕,mErrorCode更新了,所以可以拿到重发后的结果,没问题

        if (query.haveError()){
            edit->append(errorText.arg(query.errorString()));
        }
        else {
            auto pair = query.result().value<QPointPathPair>();
            if (pair.first == point) {
                edit->append(recvText.arg(pair.second));
            } else edit->append(recvText.arg("坐标不匹配!"));
        }

        if (query.errorCode() == MultipleUnConnectedErrorCode ||
                query.errorCode() == QuitReconnectErrorCode)
            break;
    }
}

void TestTcp::test0()
{
    TcpAssemblerController assembler;
    assembler.assemble(TcpFramePool.frame0x0000,fakeDatafor0x0000());
    auto command = assembler.message(); // 组的对应// "\xD7\xE9" local/   utf8 "\xE7\xBB\x84"
    edit->append(tr("<strong><font color = #75FA8D>[%1] 发送:</font></strong> %2")
                 .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss"))
                 .arg(QString::fromUtf8(command)));
    query.exec(TcpFramePool.frame0x0000,command);
    auto result = query.result();
    QString ret;
    ret = result.toString();
    if (!query.haveError()) {
        edit->append(tr("<strong><font color = #75FA8D>[%1] 回复:</font></strong> %2")
                     .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss"))
                     .arg(ret));
        return;
    }
    // 有错误
    edit->append(tr("<strong><font color = #75FA8D>[%1] 错误:</font></strong> %2")
                 .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss"))
                 .arg(query.errorString()));
}

void TestTcp::test1()
{
    // 组装好数据,根据场景选择帧命令,借助函数指针组装数据,然后发送
    // 如果有收到数据内部解析也根据帧头选择了对应的解析函数解析

    TcpAssemblerController assembler;

    assembler.assemble(TcpFramePool.frame0x0002,fakeDatafor0x0002());// 组装数据
    //assembler.assemble(TcpFramePool.frame0x0000,fakeDatafor0x0000());

    auto command = assembler.message();
    //LOG<<"command = "<<command;

    edit->append(tr("<strong><font color = #75FA8D>[%1] 发送:</font></strong> %2")
                 .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss"))
                 .arg(QString::fromLocal8Bit(command)));

    query.exec(TcpFramePool.frame0x0002,command);
    //query.exec(TcpFramePool.frame0x0000,command);

    auto result = query.result(); // 假设回复{"frame":"0x0001","result":0,"path":"C:/Users/22987/AppData/Local/EOSI"}
    QString ret;
    ret = result.toString();


    auto pair = result.value<QPointPathPair>();
    if (pair.first == QPoint(3,3)) {
        ret = pair.second;
    }

    if (!query.haveError()) {
        edit->append(tr("<strong><font color = #75FA8D>[%1] 回复:</font></strong> %2")
                     .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss"))
                     .arg(ret));
        return;
    }
    // 有错误
    edit->append(tr("<strong><font color = #75FA8D>[%1] 错误:</font></strong> %2")
                 .arg(QDateTime::currentDateTime().toString("yyyy/MMdd hh:mm:ss"))
                 .arg(query.errorString()));
}
