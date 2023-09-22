#include "../../inc/widgets/splitter.h"

Splitter::Splitter(Qt::Orientation orientation, QWidget *parent) :QSplitter(parent)
{
    setOrientation(orientation);
    setHandleWidth(SplitterHandleWidth);
    setOpaqueResize(false);
    setChildrenCollapsible(true);
    setStyleSheet(SplitterStyle);
}


Splitter::Splitter(QWidget *parent) :QSplitter(parent)
{
    setHandleWidth(SplitterHandleWidth);
    setOpaqueResize(false);
    setChildrenCollapsible(true);
    setStyleSheet(SplitterStyle);
}
