#ifndef DUALCOLUMNICON_H
#define DUALCOLUMNICON_H

#include "label.h"

class COMPONENT_IMEXPORT DualColumnIcon : public QHBoxLayout
{
    Q_OBJECT
private:
    QWidget * mLeftWidget;
    QWidget * mRightWidget;
    Label * mIcon;
public:
    explicit DualColumnIcon(QWidget*left,QWidget*right,const QString& iconname);
    explicit DualColumnIcon(QWidget*left,QWidget*right,Label*icon);
    explicit DualColumnIcon(const QVector<QWidget*>& widgets);
    void setIconSize(const QSize& size);
    void setMargin(int leftmargin, int gap1, int gap2,int rightmargin,int height);
};

#endif // DUALCOLUMNICON_H
