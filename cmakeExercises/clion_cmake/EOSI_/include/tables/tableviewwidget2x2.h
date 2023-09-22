#ifndef TABLEVIEWWIDGET2X2_H
#define TABLEVIEWWIDGET2X2_H

#include "../widgets/label.h"

class COMPONENT_IMEXPORT TableViewWidget2x2: public QWidget
{
    Q_OBJECT
private:
    QVector<Label*> mLabels;
    QVector<QPixmap*> mPixs;
public:
    explicit TableViewWidget2x2(QWidget *parent = nullptr);

    void setPixmap(int index,QPixmap*pix);
    void setPixmap(int index,const QPixmap&pix);
    void setPixmaps(const QVector<QPixmap*> &pixs);
    QPixmap* pixmap(int index) const;
    QVector<QPixmap*> pixmaps() const;
signals:

};
Q_DECLARE_METATYPE(QVector<QPixmap*>)
//Q_DECLARE_METATYPE(QPixmap*)
#endif // TABLEVIEWWIDGET2X2_H
