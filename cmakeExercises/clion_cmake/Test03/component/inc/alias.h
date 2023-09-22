//
// Created by chenbei on 2023/9/20.
//

#ifndef TEST3_ALIAS_H
#define TEST3_ALIAS_H

#include <QString>
#include <QVector>
#include <QColor>
#include <QVariant>
#include <QPoint>
#include <QPointF>
#include <QList>
#include <QStringList>
#include <QMap>
#include <QPair>
#include <QDateTime>
#include <QQueue>

typedef  const QVariant& QCVariant;
typedef  const QString& QCString;
typedef  const QPoint& QCPoint;
typedef  const QPointF& QCPointF;
typedef  const QColor& QCColor;

typedef  QVector<QColor> QColorVector;
typedef  const QVector<QColor>& QCColorVector;

typedef QVector<QPoint> QPointVector;
typedef const QVector<QPoint>& QCPointVector;
typedef QVector<QPointF> QPointFVector;
typedef const QVector<QPointF>& QCPointFVector;

typedef QVector<QString>  QStringVector;
typedef  const QVector<QString>& QCStringVector ;

typedef QVector<QString> QValueVector;
typedef  const QVector<QString>& QCValueVector;

typedef QVector<bool> QBoolVector;

// 用于pattern
typedef QVector<QVector<QPointF>> QPointmap;
typedef QVector<QVector<bool>> QMaskmap;
typedef QVector<QVector<int>> QGroupmap;
typedef QVector<QRectF> QRectVector;
typedef QVector<QVector<QRectF>> QRectmap;

// 用于sqlreadwrite
typedef  QStringList QFieldsList;
typedef  const QFieldsList& QCFieldsList;

typedef  QStringList QValuesList;
typedef  const QStringList& QCValuesList;

typedef QVector<QVector<QString>> QValuemap;
typedef  const QVector<QVector<QString>>& QCValuemap;

// 用于scanconfigdata
typedef QVector<QString> QGroupNameVector; // 组名列表
typedef QVector<QString> QPointNameVector; // 单个组点名称列表
typedef QVector<QVector<QPoint>> QGroupPointVector; // 所有组的点位置列表
typedef QVector<QVector<QString>> QGroupPointNameVector; // 所有组的点名称列表

// 用于scangroupdata
typedef  QMap<int, QString> QGroupName;
typedef  QPair<QVector<QPoint>,QVector<QString>> QGroupPairData ;
typedef  QMap<int, QPair< QVector<QPoint>,QVector<QString>>> QGroupData;
typedef  const QMap<int, QPair< QVector<QPoint>,QVector<QString>>>&  QCGroupData;

// 用于ScanJsonReadWrite
typedef  QPair<QGroupPointVector,QGroupPointNameVector> PointVectorPair;
typedef  QPair<QGroupNameVector,PointVectorPair>  GroupVectorPair;

// 用于预览解析返回的坐标和路径
typedef QPair<QPoint,QString> QPointPathPair;
typedef const QPair<QPoint,QString>& QCPointPathPair;

// initconfig.h使用
typedef QPair<QString,QString> QStringPair;
typedef const QPair<QString,QString>& QCStringPair;
#endif //TEST3_ALIAS_H
