#include "../../inc/utilities/jsonreadwrite.h"

JsonReadWrite::JsonReadWrite(QObject *parent) : QObject(parent)
{

}

void JsonReadWrite::parseJson(const QByteArray &json)
{
    parseData.clear();
    constantData.clear();
    auto doc = QJsonDocument::fromJson(json);

    if (!doc.object().isEmpty()) {
        parseObject(doc.object());
        return;
    }

    if (!doc.array().isEmpty()) {
        parseArray(doc.array());
        return;
    }
}

void JsonReadWrite::parseObject(const QJsonObject& object)
{// 递归解析对象,取出对象的所有key然后最终存放到字典内
    foreach(auto key,object.keys()) // 对象下的所有键值
    {
        if (specialObjectKeys.contains(key)){ //调用parseObject函数之前要先对specialObjects赋值
             parseSpecialObject(key,object.value(key)); // 和parseSpecialObject一致
             continue;
        }

        auto var = object.value(key);
        if (var.isObject())
            parseObject(var.toObject());
        else if (var.isArray())
        {
            auto arr = var.toArray();
            if (arr.isEmpty()) parseData[key] = "[]";
            else parseArray(arr);
        }
        else {
            auto v = var.toVariant();
            parseData[key] = v;
        }
    }
}

void JsonReadWrite::parseArray(const QJsonArray& array)
{ // 递归解析数组直到遇到常量,常量对象单独放置
    foreach(auto var, array)
    {// 特殊常量的处理,针对特定的值处理没有这个必要
        if (var.isObject())
            parseObject(var.toObject());
        else if (var.isArray())
            parseArray(var.toArray());
        else constantData.append(var.toVariant());
    }
}

QByteArray JsonReadWrite::readJson(const QString&path)
{ // 直接传递json文件的路径，外部调用有义务检测path的合法性
    // 只是返回纯文本,一般不使用而是直接解析parseJson
    QByteArray json;

    QFile file(path);
    if (file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream stream(&file);
        stream.setCodec("utf-8");
        //json = stream.readAll().toUtf8();
        json = file.readAll();
        file.close();
    }
    return json;
}

void JsonReadWrite::writeJson(const QString&path,const QJsonObject&object)
{
    auto doc = QJsonDocument(object);
    auto json = doc.toJson();
    writeJson(path,json);
}

void JsonReadWrite::writeJson(const QString&path,const QJsonArray&array)
{
    auto doc = QJsonDocument(array);
    auto json = doc.toJson();
    writeJson(path,json);
}

void JsonReadWrite::writeJson(const QString&path,const QByteArray&json)
{ // 调用本函数外部有义务检测path的合法性
    QFile file(path);
    if (file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream stream(&file);
        stream.setCodec("utf-8");
        stream << json;
        //file.write(json);
        file.close();
    }
}

QVariantMap JsonReadWrite::map() const
{
    return parseData;
}

QVariantList JsonReadWrite::list() const
{
    return constantData;
}

void JsonReadWrite::setSpecialObjectKeys(const QStringList& keys)
{
    specialObjectKeys = keys;
}

void JsonReadWrite::parseSpecialObject(const QJsonValue &key,const QJsonValue &value)
{ // parseObject遍历字典的key,value值传入,当key等于某些值时的特殊处理
    Q_UNUSED(key);
    Q_UNUSED(value);
}
