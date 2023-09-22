#include "../../inc/widgets/multilinelayout.h"

MultilineLayout::MultilineLayout(const QList<QVector<QWidget*>>& items ,const QMap<MarginType,int> margins)
{
    if (items.count() == 0) return;

    if (items.at(0).count() != 3) return; // 每层固定3个部件

    DualColumnIcon * lay;
    // 按照顺序添加每个层布局: 连接,数据库,用户,密码
    foreach(const QVector<QWidget*> rowItems, items)
    {
        lay = new DualColumnIcon(rowItems);
        // (leftmargin)=>button=>(gap1)=>groupbox=>(gap2)=>icon=>(rightmargin)+layheight
        lay->setMargin(margins[LeftMargin],margins[Gap1],margins[Gap2],
                margins[RightMarigin],margins[Height]);
        addLayout(lay);
    }
}
