#include "../../inc/widgets/dualcolumnicon.h"

DualColumnIcon::DualColumnIcon(QWidget*left,QWidget*right,const QString& iconname)
    :mLeftWidget(left), mRightWidget(right)
{
    mIcon = new Label;
    mIcon->setPixmap(QPixmap(iconname));

    // 1行布局的3个布局都居中显示
    addWidget(left,Qt::AlignCenter);
    addWidget(right,Qt::AlignCenter);
    addWidget(mIcon,Qt::AlignCenter);
}

DualColumnIcon::DualColumnIcon(QWidget*left,QWidget*right,Label*icon)
    :mLeftWidget(left), mRightWidget(right),mIcon(icon)
{
    // 1行布局的3个布局都居中显示
    addWidget(left,Qt::AlignCenter);
    addWidget(right,Qt::AlignCenter);
    addWidget(mIcon,Qt::AlignCenter);
}

DualColumnIcon::DualColumnIcon(const QVector<QWidget*> &widgets)
{
    if (widgets.count() != 3) return;
    mLeftWidget = widgets[0];
    mRightWidget = widgets[1];
    mIcon = qobject_cast<Label*>(widgets[2]);

    // 1行布局的3个布局都居中显示
    addWidget(mLeftWidget,Qt::AlignCenter);
    addWidget(mRightWidget ,Qt::AlignCenter);
    addWidget(mIcon,Qt::AlignCenter);
}

void DualColumnIcon::setIconSize(const QSize &size)
{
        mIcon->setFixedSize(size);
}

void DualColumnIcon::setMargin(int leftmargin, int gap1,int gap2,int rightmargin, int height)
{ // (leftmargin)=>button=>(gap1)=>groupbox=>(gap2)=>icon=>(rightmargin)+layheight
    insertItem(0,new QSpacerItem(leftmargin,height)); // leftmargin
    insertItem(2,new QSpacerItem(gap1,height)); // button-groupbox
    insertItem(4,new QSpacerItem(gap2,height));// groupbox-icon
    insertItem(6,new QSpacerItem(rightmargin,height)); // height
}
