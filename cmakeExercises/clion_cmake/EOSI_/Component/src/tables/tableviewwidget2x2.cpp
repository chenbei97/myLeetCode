#include "../../inc/tables/tableviewwidget2x2.h"

TableViewWidget2x2::TableViewWidget2x2(QWidget *parent) : QWidget(parent)
{
    for(int i = 0; i < 4; ++i)
    {
        auto label = new Label;
        label->setFrameShape(QLabel::Panel);
        mLabels.append(label);
        mPixs.append(nullptr);
    }

    QHBoxLayout * toplay = new QHBoxLayout;
    QHBoxLayout * bottomlay = new QHBoxLayout;
    toplay->addWidget(mLabels[0]);
    toplay->addWidget(mLabels[1]);
    toplay->setMargin(0);
    toplay->setSpacing(0);
    bottomlay->addWidget(mLabels[2]);
    bottomlay->addWidget(mLabels[3]);
    bottomlay->setMargin(0);
    bottomlay->setSpacing(0);

    QVBoxLayout * lay = new QVBoxLayout(this);
    lay->addLayout(toplay);
    lay->addLayout(bottomlay);
    lay->setMargin(0);
    lay->setSpacing(0);

    INIT_FONT;
}

void TableViewWidget2x2::setPixmap(int index,QPixmap*pix)
{
    if (index < 0 || index > 3) return;
    mLabels[index]->setPixmap(*pix);
    mPixs[index] = pix;
}

void TableViewWidget2x2::setPixmap(int index,const QPixmap&pix)
{
    if (index < 0 || index > 3) return;
    mLabels[index]->setPixmap(pix);
    mPixs[index] = new QPixmap(pix);
}

void TableViewWidget2x2::setPixmaps(const QVector<QPixmap*> &pixs)
{
    if (pixs.count() != 4) return;
    mPixs = pixs;
    for(int i = 0; i < 4; i++)
        if (pixs[i]) // 可能是nullptr
         mLabels[i]->setPixmap(*pixs[i]);
}

QPixmap*TableViewWidget2x2::pixmap(int index) const
{
    if (index < 0 || index > 3) return nullptr;
    return mPixs[index];
}

QVector<QPixmap*> TableViewWidget2x2::pixmaps() const
{
    return mPixs;
}
