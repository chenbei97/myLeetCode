#ifndef TCPPROTOCOL_H
#define TCPPROTOCOL_H

#include "../utilities/jsonreadwrite.h"

#define TcpLoaderPointer (&TcpLoader::instance())
#define SocketPort 3000 // 端口号
#define SocketLocalIP ("127.0.0.1")
#define SocketLocalHost ("localhost")
#define SocketWaitTime 10000 // 套接字连接阻塞的时间,有些裕量
#define SocketCheckFrequency 100 // 定时器查询套接字的连接状态的频率 100ms

static const char* FrameField = "frame";
static const char* RepeatField = "repeat";

enum TcpErrorCode {
    EmptyDataErrorCode, // 没有传送数据错误,回复方问题,例如传递路径path但是空字符串
    FrameFieldMissedErrorCode, // 返回消息缺失字段错误 回复方问题,没有带frame字段
    RepeatFieldMissedErrorCode,// 返回消息缺失字段错误 回复方问题,没有带repeat字段
    ResponsetJsonFormatErrorCode, // 回复的json格式有问题导致不能解析
    RequestFrameErrorCode, // 发送的帧有问题,为空或不存在这样的帧命令,发送方问题
    ResponseFrameErrorCode, // 返回的帧和发送的帧不匹配,回复方问题
    ReceiveResponseErrorCode, // 下位机需要重发,设定repeat=1
    MultipleRetransmissionErrorCode, // 多次重发错误
    SocketRequestErrorCode, // 套接字的请求超时错误 非人为
    SocketResponseErrorCode,// 套接字的回复超时错误 非人为
    UnConnectedErrorCode, // 未连接错误
    MultipleUnConnectedErrorCode, // 多次重连错误
    QuitReconnectErrorCode, // 主动退出重连
    NoErrorCode,
};

static const char* EmptyDataError = "EmptyDataError";
static const char* FrameFieldMissedError = "FrameFieldMissedError";
static const char* RepeatFieldMissedError = "RepeatFieldMissedError";
static const char* ResponsetJsonFormatError = "ResponsetJsonFormatError";
static const char* RequestFrameError = "RequestFrameError";
static const char* ResponseFrameError = "ResponseFrameError";
static const char* ReceiveResponseError = "ReceiveResponseError";
static const char* MultipleRetransmissionError = "MultipleRetransmissionError";
static const char* SocketRequestError = "SocketRequestError";
static const char* SocketResponseError = "SocketResponseError";
static const char* UnConnectedError = "UnConnectedError";
static const char* MultipleUnConnectedError = "MultipleUnConnectedError";
static const char* QuitReconnectError = "QuitReconnectError";
static const char* NoError = "NoError";

static const QVector<QString> TcpErrorStrings = {
    EmptyDataError,
    FrameFieldMissedError,
    RepeatFieldMissedError,
    ResponsetJsonFormatError,
    RequestFrameError,
    ResponseFrameError,
    ReceiveResponseError,
    MultipleRetransmissionError,
    SocketRequestError,
    SocketResponseError,
    UnConnectedError,
    MultipleUnConnectedError,
    QuitReconnectError,
    NoError,
};

Q_ENUMS(TcpErrorCode)
Q_DECLARE_METATYPE(TcpErrorCode)

typedef  const QVariantMap& QCVariantMap;
typedef  QVariant(*TcpParseFuncPointer)(QCVariantMap m);
typedef  QByteArray(*TcpAssembleFuncPointer)(QCVariantMap m);

typedef struct { // 注册过的帧头命令
    const QString frame0x0000 = "0x0000";
    const QString frame0x0001 = "0x0001";
    const QString frame0x0002 = "0x0002";
    const QString frame0x0003 = "0x0003";
    const QString frame0x0004 = "0x0004";
    const QString frame0x1000 = "0x1000";
} TcpFrameList;

struct Field0x0000{
    // 不需要传递给下位机(但是Tcp用过的字段)
    const QString groupNames = "groupNames";
    const QString groupNameLists = "groupNameLists";
    const QString groupPointLists = "groupPointLists";
    // 传给下位机json涉及的字段
    const QString objective = "objective";
    const QString group = "group";
    const QString wellsize = "wellsize";
    const QString channel = "channel";
    const QString view = "view";
    const QString x = "x";
    const QString y = "y";
    const QString order = "order";
    const QString is_schedule = "is_schedule";
    const QString count = "count";
    const QString total = "total";
    const QString duration = "duration";
    const QString start = "start";
    const QString end = "end";
};

struct Field0x0001{
    const QString equipment_number = "equipment_number";
};

struct Field0x0002{
    const QString pointx = "point.x";
    const QString pointy = "point.y";
    const QString path = "path";
};

typedef struct {
    Field0x0000 field0x0000;
    Field0x0001 field0x0001;
    Field0x0002 field0x0002;
} TcpFieldList;

static QJsonDocument TcpAssemblerDoc;
static const TcpFrameList TcpFramePool;
static const TcpFieldList TcpFieldPool;

#define Field0x0000 TcpFieldPool.field0x0000
#define Field0x0001 TcpFieldPool.field0x0001
#define Field0x0002 TcpFieldPool.field0x0002

 static QVariant parse0x0000(QCVariantMap m)
 { // 对于0号命令...做些事情，通用配置命令没有特殊返回值
     Q_UNUSED(m);
    QVariant d;
    return d;
 }

 static QByteArray assemble0x0000(QCVariantMap m)
 {
     QJsonObject object;

     object[FrameField] = TcpFramePool.frame0x0000;

     object[Field0x0000.objective] = m[Field0x0000.objective].toString();
     object[Field0x0000.channel] = m[Field0x0000.channel].toString();
     object[Field0x0000.view] = m[Field0x0000.view].toInt();
     object[Field0x0000.wellsize] = m[Field0x0000.wellsize].toInt();

     object[Field0x0000.total] =  m[Field0x0000.total].toLongLong();
     object[Field0x0000.duration] =  m[Field0x0000.duration].toLongLong();
     object[Field0x0000.count] =  m[Field0x0000.count].toInt();

     auto is_schedule = m[Field0x0000.is_schedule].toInt();
     object[Field0x0000.is_schedule] =  is_schedule;

     if (is_schedule){
         object[Field0x0000.start] = m[Field0x0000.start].toDateTime().toString("yyyy/MM/dd hh:mm:ss");
         object[Field0x0000.end] = m[Field0x0000.end].toDateTime().toString("yyyy/MM/dd hh:mm:ss");
     } else { // 立即执行不会传递start,end字段
         object[Field0x0000.start] = "";
         object[Field0x0000.end] = "";
     }

     auto groupNames = m[Field0x0000.groupNames].value<QGroupNameVector>();
     //auto groupNameLists = m[Field0x0000.groupNameLists].value<QGroupPointNameVector>();
     auto groupPointLists = m[Field0x0000.groupPointLists].value<QGroupPointVector>();
     QJsonArray parr; // 组列表
     for(int i = 0; i < groupNames.count(); ++i) { // 列表下边设计为多个组对象
         QJsonObject gobj; // 组对象
         auto groupName = groupNames.at(i);  // 每个组对象是一个点列表,存了多个点
         QJsonArray garr; // 组对象的值是个列表
         for (int j = 0; j < groupPointLists.at(i).count(); ++j) { // 不同组的点不一样
             QJsonObject pobj; // 点对象存到列表  {"order": 2,"pname": "111","x": 3,"y": 4}是个点对象
             auto point = groupPointLists.at(i).at(j);
             //auto pointName = groupNameLists.at(i).at(j);
             pobj["x"] = point.x();
             pobj["y"] = point.y();
             //pobj["pname"] = pointName; 不传递pname无需组装
             pobj["order"] = j;
             garr.append(pobj); // 把点对象存到点列表,下方点列表又作为组对象的值
         }
         gobj[groupName] = garr;  // "groupA" : [] 作为组对象的值
         parr.append(gobj); // 组列表添加组对象
     }
     object.insert(Field0x0000.group,parr);

     TcpAssemblerDoc.setObject(object);
     auto json = TcpAssemblerDoc.toJson(); // 返回的是utf-8,但是sscom不能正常显示,使用gb2312
     //LOG<<"json = "<<json;
     //return QString::fromUtf8(json).toLocal8Bit();
     return json;
 }

 static QVariant parse0x0001(QCVariantMap m)
 { // 下位机拿到设备号应该也返回equipment_number,取值0或者1
    if (!m.keys().contains(Field0x0001.equipment_number)) return QVariant();

    auto equip = m[Field0x0001.equipment_number]; // 0 or 1

    return equip;
 }

 static QByteArray assemble0x0001(QCVariantMap m)
 { // 发送设备号
     QJsonObject object;
     object[FrameField] = TcpFramePool.frame0x0001;
     object[Field0x0001.equipment_number] = m[Field0x0001.equipment_number].toString();

     TcpAssemblerDoc.setObject(object);
     auto json = TcpAssemblerDoc.toJson();
     return json;
 }

 static QVariant parse0x0002(QCVariantMap m)
 { // 1号命令需要返回1个路径和1个坐标
    if (!m.keys().contains(Field0x0002.path)) return QVariant();
    if (!m.keys().contains(Field0x0002.pointx)) return QVariant();
    if (!m.keys().contains(Field0x0002.pointy)) return QVariant();

    auto path = m[Field0x0002.path].toString();
    auto x = m[Field0x0002.pointx].toUInt();
    auto y = m[Field0x0002.pointy].toUInt();
    if (path.isEmpty()) return QVariant(); //path是空的话认为是空数据错误,空本身不能作为数据

    auto pair = qMakePair(QPoint(x,y),path);
    QVariant v;
    v.setValue(pair);
    return v;
 }

 static QByteArray assemble0x0002(QCVariantMap m)
 { // 预览需要发送坐标x,y
     QJsonObject object;
     object[FrameField] = TcpFramePool.frame0x0002;
     object[Field0x0002.pointx] = m[Field0x0002.pointx].toInt();
    object[Field0x0002.pointy] = m[Field0x0002.pointy].toInt();
     TcpAssemblerDoc.setObject(object);
     auto json = TcpAssemblerDoc.toJson();
     return json;
 }

 static QVariant parse0x0003(QCVariantMap m)
 {
    QVariant d;
    Q_UNUSED(m);
    return d;
 }

 static QByteArray assemble0x0003(QCVariantMap m)
 {
     Q_UNUSED(m);
     QJsonObject object;
     object[FrameField] = TcpFramePool.frame0x0003;

     TcpAssemblerDoc.setObject(object);
     auto json = TcpAssemblerDoc.toJson();
     return json;
 }

 static QVariant parse0x0004(QCVariantMap m)
 {Q_UNUSED(m);
    QVariant d;

    return d;
 }

 static QByteArray assemble0x0004(QCVariantMap m)
 {Q_UNUSED(m);
     QJsonObject object;
     object[FrameField] = TcpFramePool.frame0x0004;

     TcpAssemblerDoc.setObject(object);
     auto json = TcpAssemblerDoc.toJson();
     return json;
 }

 static QVariant parse0x1000(QCVariantMap m)
 {Q_UNUSED(m);
    QVariant d;

    return d;
 }

 static QByteArray assemble0x1000(QCVariantMap m)
 {Q_UNUSED(m);
     QJsonObject object;
     object[FrameField] = TcpFramePool.frame0x1000;

     TcpAssemblerDoc.setObject(object);
     auto json = TcpAssemblerDoc.toJson();
     return json;
 }

 // 根据帧头选择对应的解析函数
static QMap<QString,TcpParseFuncPointer>  TcpParseFunctions = {
    {TcpFramePool.frame0x0000,parse0x0000},
    {TcpFramePool.frame0x0001,parse0x0001},
    {TcpFramePool.frame0x0002,parse0x0002},
    {TcpFramePool.frame0x0003,parse0x0003},
    {TcpFramePool.frame0x0004,parse0x0004},
    {TcpFramePool.frame0x1000,parse0x1000},
};

static QMap<QString,TcpAssembleFuncPointer>  TcpAssembleFunctions = {
    {TcpFramePool.frame0x0000,assemble0x0000},
    {TcpFramePool.frame0x0001,assemble0x0001},
    {TcpFramePool.frame0x0002,assemble0x0002},
    {TcpFramePool.frame0x0003,assemble0x0003},
    {TcpFramePool.frame0x0004,assemble0x0004},
    {TcpFramePool.frame0x1000,assemble0x1000},
};


#endif // TCPPROTOCOL_H
