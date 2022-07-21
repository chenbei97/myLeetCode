#ifndef SETBRUSHCOLOR_H
#define SETBRUSHCOLOR_H
#include <QColor>
#include <QColorDialog>
//函数模板
template<class T> void setBrushColor(T *item)
{
    QColor color=item->brush().color(); // item认为是QGraphicsItem类型
    color=QColorDialog::getColor(color,nullptr,"选择填充颜色");
    if (color.isValid())
        item->setBrush(QBrush(color)); // 填充
}
#endif // SETBRUSHCOLOR_H
