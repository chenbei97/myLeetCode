#include "dialog.h"
#include <QRect>

Dialog::Dialog(QWidget *parent)
  : QDialog(parent)
  , xLabel(new QLabel("x()：")), yLabel(new QLabel("y()：")), posLabel(new QLabel("pos()："))
  , frameGeometryLabel(new QLabel("frameGeometry()：")), frameSizeLabel(new QLabel("frameSize()："))
  , geometryLabel(new QLabel("geometry()：")), sideBarWidthLabel(new QLabel("sideBarWidth = ")), titleBarHeightLabel(new QLabel("titleBarHeight = "))
  , rectLabel(new QLabel("rect()：")), sizeLabel(new QLabel("size()：")), widthLabel(new QLabel("width()：")), heightLabel(new QLabel("height()："))
  , baseSizeLabel(new QLabel("baseSize()：")), sizeHintLabel(new QLabel("sizeHint()：")), sizeIncrementLabel(new QLabel("sizeIncrement()："))
  , xVLabel(new QLabel), yVLabel(new QLabel), posVLabel(new QLabel)
  , frameGeometryVLabel(new QLabel), frameSizeVLabel(new QLabel),geometryVLabel(new QLabel)
  , sideBarWidthVLabel(new QLabel), titleBarHeightVLabel(new QLabel)
  , rectVLabel(new QLabel), sizeVLabel(new QLabel), widthVLabel(new QLabel), heightVLabel(new QLabel)
  , baseSizeVLabel(new QLabel), sizeHintVLabel(new QLabel), sizeIncrementVLabel(new QLabel)
{
      mainLayout = new QGridLayout(this);
      mainLayout->addWidget(xLabel,0,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(xVLabel,0,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(yLabel,1,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(yVLabel,1,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(posLabel,2,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(posVLabel,2,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(frameGeometryLabel,3,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(frameGeometryVLabel,3,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(frameSizeLabel,4,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(frameSizeVLabel,4,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(geometryLabel,5,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(geometryVLabel,5,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(sideBarWidthLabel,6,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(sideBarWidthVLabel,6,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(titleBarHeightLabel,7,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(titleBarHeightVLabel,7,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(rectLabel,8,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(rectVLabel,8,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(sizeLabel,9,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(sizeVLabel,9,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(widthLabel,10,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(widthVLabel,10,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(heightLabel,11,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(heightVLabel,11,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(baseSizeLabel,12,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(baseSizeVLabel,12,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(sizeHintLabel,13,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(sizeHintVLabel,13,1,1,1,Qt::AlignCenter);
      mainLayout->addWidget(sizeIncrementLabel,14,0,1,1,Qt::AlignCenter);
      mainLayout->addWidget(sizeIncrementVLabel,14,1,1,1,Qt::AlignCenter);
      this->resize(600,400);
      this->setFont(QFont("Times New Roman",12));
      this->updateLabel();
}

// 窗体被移动和调整大小时能够更新
void Dialog::resizeEvent(QResizeEvent *e)
{
    this->updateLabel();
    Q_UNUSED(e);
}

void Dialog::moveEvent(QMoveEvent *e)
{
      this->updateLabel();
      Q_UNUSED(e);
}

void Dialog::updateLabel()
{
      xVLabel->setText(QString::number(this->x()));
      yVLabel->setText(QString::number(this->y()));
      posVLabel->setText(QString("[ %1, %2]").arg(this->pos().x()).arg(this->pos().y()));

      QRect fg = this->frameGeometry();
      frameGeometryVLabel->setText(QString("[ (%1,%2), (%3,%4)]")
                            .arg(fg.x()).arg(fg.y()).arg(fg.width()).arg(fg.height()));
      frameSizeVLabel->setText(QString("[ %1, %2]")
                            .arg(this->frameSize().width()).arg(this->frameSize().height()));

      QRect g = this->geometry();
      geometryVLabel->setText(QString("[ (%1,%2), (%3,%4)]")
                            .arg(g.x()).arg(g.y()).arg(g.width()).arg(g.height()));
      QSize sz = fg.size() - g.size(); // 使用size计算
      QPoint pt = g.topLeft() - fg.topLeft();// 或者使用point计算
      // 使用size计算,注意得到的宽度是2个侧边栏的,要减半,使用point计算直接得到
      sideBarWidthVLabel->setText(QString("[ %1, %2]").arg(sz.width()/2).arg(pt.x()));
      // 使用size计算,注意得到的高度是1个侧边栏宽度+1个标题栏的高度,需要减去1个侧边栏宽度,或者直接使用point计算
      titleBarHeightVLabel->setText(QString("[ %1, %2]").arg(sz.height()-sz.width()/2).arg(pt.y()));

      QRect r = this->rect();
      rectVLabel->setText(QString("[ (%1,%2), (%3,%4)]")
                            .arg(r.x()).arg(r.y()).arg(r.width()).arg(r.height()));
      sizeVLabel->setText(QString("[ %1, %2]").arg(this->size().width()).arg(this->size().height()));
      widthVLabel->setText(QString::number(this->width()));
      heightVLabel->setText(QString::number(this->height()));

      baseSizeVLabel->setText(QString("[ %1, %2]")
                            .arg(this->baseSize().width()).arg(this->baseSize().height()));

      sizeHintVLabel->setText(QString("[ %1, %2]")
                            .arg(this->sizeHint().width()).arg(this->sizeHint().height()));
      sizeIncrementVLabel->setText(QString("[ %1, %2]")
                            .arg(this->sizeIncrement().width()).arg(this->sizeIncrement().height()));
}

