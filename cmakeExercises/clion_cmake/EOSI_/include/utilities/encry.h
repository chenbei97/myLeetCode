#ifndef ENCRY_H
#define ENCRY_H

#include "qstring.h"
#include "qcryptographichash.h"
#include "qvector.h"
#include "qcolor.h"
#include <random>

static QByteArray encry_hash(const QString&text,QCryptographicHash::Algorithm algo )
{
    QByteArray byte = text.toLatin1(); // 因为密码都是数字字母字符,转为latin即可,向下兼容ASCII
    QByteArray bytehash = QCryptographicHash::hash(byte, algo); // 哈希值
    return bytehash.toHex(); // 转为16进制
}

static QByteArray encry_base64(const QString& string)
{
    return string.toLatin1().toBase64();
}

static QByteArray decry_base64(const QString& string)
{
   return QByteArray::fromBase64(string.toLatin1());
}

static QString getAsciiChars() {
    QString s;
    for(int i = 0 ;i < 255; ++i)
        s += static_cast<QChar>(i);
    return s;
}

static QVector<int> getStringIndexs (const QString& string)
{
    QVector<int> indexs;
    auto chars = getAsciiChars();
    foreach(auto s,string) {
        indexs.append(chars.indexOf(s));
    }
    return indexs;
}

static QString encry_color(const QString& string)
{
    QString ret;
    auto idxs = getStringIndexs(string);
    //qDebug()<<"idxs = "<<idxs;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    QColor color;
    foreach(auto idx, idxs) {
        color.setRgb(dis(gen),dis(gen),idx);
        ret.append(color.name().remove("#"));
    }
    //qDebug()<<ret;
    return ret;
}

static QString decry_color(const QString& string)
{
    QString ret;
    auto chars = getAsciiChars();
    for(int i = 0; i < string.count(); i+=6)
    {
        auto s = string.mid(i,6);
        auto color = s.prepend("#");
        auto blue = QColor(color).blue();
        //qDebug()<<blue;
        ret.append(chars.at(blue));
    }
    return ret;
}

#endif // ENCRY_H
