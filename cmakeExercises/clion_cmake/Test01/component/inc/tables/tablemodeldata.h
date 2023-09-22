#ifndef TABLEMODELDATA_H
#define TABLEMODELDATA_H

#include "qvariant.h"
#include "qdatastream.h"
#include "../public.h"

/*
重载抽象表格模型项目内部使用的数据结构对象，指定角色和数据
每个项存储了不同角色的值
*/
/*自定义的数据角色*/
enum TableModelDataRole {
    /*以下角色用于2x2代理*/
    MousePosition = Qt::UserRole + 1, // 项中鼠标点击的位置
    HighlightColor = Qt::UserRole + 2,// 鼠标点击的项的高亮颜色
    SelectedColor = Qt::UserRole + 3, // 已经被选中项的高亮颜色
    CurrentColor = Qt::UserRole+4, // 当前焦点项的高亮颜色
    SelectedItems = Qt::UserRole + 5, // enum<TableViewCellSelected>的所有枚举值
    CurrentItem = Qt::UserRole + 6, // 当前项,唯一值或者没有,None,Top,Left,Right,Bottom有效,其他忽略
    /*以下角色用于label代理*/
    isSelected = Qt::UserRole + 7, // 简化为只需传递bool值
    isCurrent = Qt::UserRole + 8, // 简化为只需传递bool值
};

/*子单元格的选中信息 2x2x2x2=16种情况*/
enum TableViewCellSelected
{
    None = 0b0000,

    OnlyTopLeft = 0b0001,
    OnlyTopRight = 0b0010,
    OnlyBottomLeft = 0b0100,
    OnlyBottomRight = 0b1000,

    Top = 0b0011,
    Bottom = 0b1100,
    Left = 0b0101,
    Right = 0b1010,
    DiagLeft = 0b1001,
    DiagRight = 0b0110,

    ExceptTopLeft = 0b1110,
    ExceptTopRight = 0b1101,
    ExceptBottomLeft = 0b1011,
    ExceptBottomRight = 0b0111,

    All = 0b1111
};


Q_ENUMS(TableModelDataRole)
Q_DECLARE_METATYPE(TableModelDataRole)

Q_ENUMS(TableViewCellSelected)
Q_DECLARE_METATYPE(TableViewCellSelected)

class COMPONENT_IMEXPORT TableModelData
{
public:
    TableModelData();
    TableModelData(int r,const QVariant&v);
    int role;
    QVariant value;

    bool operator==(const TableModelData &other) const;
};
Q_DECLARE_TYPEINFO(TableModelData, Q_MOVABLE_TYPE);
Q_DECLARE_METATYPE(TableModelData)

#endif // TABLEMODELDATA_H
