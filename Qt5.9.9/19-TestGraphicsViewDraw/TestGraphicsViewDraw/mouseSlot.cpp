#include "TestGraphicsViewDraw.h"
#include "ui_TestGraphicsViewDraw.h"
#include "setBrushColor.h"
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QColorDialog>
#include <QFontDialog>

// 鼠标传递的point一律是视图(物理)坐标

// 1. 鼠标移动事件
void TestGraphicsViewDraw::on_mouseMovePoint(QPoint point)
{
    this->labViewCord->setText(QString::asprintf("视图(物理)坐标：%d,%d",point.x(),point.y()));
    QPointF pointScene=ui->graphicsView->mapToScene(point); //转换到Scene坐标
    this->labSceneCord->setText(QString::asprintf("场景(逻辑)坐标：(%.0f,%.0f)",pointScene.x(),pointScene.y()));
}

//2. 鼠标单击事件
void TestGraphicsViewDraw::on_mouseClicked(QPoint point)
{
    QPointF pointScene=ui->graphicsView->mapToScene(point); //转换到Scene坐标
    QGraphicsItem  *item=nullptr;
    item=scene->itemAt(pointScene,ui->graphicsView->transform()); //获取该位置的图形项
    if (item != nullptr) //有绘图项
    {
        QPointF pointItem=item->mapFromScene(pointScene); //转换为绘图项的局部坐标
        this->labItemCord->setText(QString::asprintf("图形项(局部逻辑)坐标：(%.0f,%.0f)",pointItem.x(),pointItem.y()));
        this->labItemInfo->setText("图形项信息："+item->data(ItemDesciption).toString()+", 创建编号："+
                   item->data(ItemId).toString()); // 把图形项信息打印出来
    }
}

// 3. 鼠标双击事件
void TestGraphicsViewDraw::on_mouseDoubleClick(QPoint point)
{
    // 调用相应的对话框，设置填充颜色、线条颜色或字体
    QPointF pointScene=ui->graphicsView->mapToScene(point); //转换到Scene坐标
    QGraphicsItem  *item=nullptr;
    item=scene->itemAt(pointScene,ui->graphicsView->transform()); //获取指定位置的图形项
    if (item == nullptr) //没有绘图项
        return;

    switch (item->type())  // 根据绘图项的类型对item强制类型转换成对应类型
    {
      case    QGraphicsRectItem::Type: //矩形框填充颜色
      {
          QGraphicsRectItem *theItem=qgraphicsitem_cast<QGraphicsRectItem*>(item);
          setBrushColor(theItem);
          break;
      }
      case    QGraphicsEllipseItem::Type: //椭圆和圆都是 QGraphicsEllipseItem,填充颜色
      {
          QGraphicsEllipseItem *theItem;
          theItem=qgraphicsitem_cast<QGraphicsEllipseItem*>(item);
          setBrushColor(theItem);
          break;
      }

      case    QGraphicsPolygonItem::Type: //梯形和三角形,可以填充颜色
      {
          QGraphicsPolygonItem *theItem=qgraphicsitem_cast<QGraphicsPolygonItem*>(item);
          setBrushColor(theItem);
          break;
      }
      case    QGraphicsLineItem::Type: //直线，设置线条颜色
      {
          QGraphicsLineItem *theItem=qgraphicsitem_cast<QGraphicsLineItem*>(item);
          QPen    pen=theItem->pen();
          QColor  color=theItem->pen().color();
          color=QColorDialog::getColor(color,this,"选择线条颜色");
          if (color.isValid())
          {
              pen.setColor(color);
              theItem->setPen(pen);
          }
          break;
      }
      case    QGraphicsTextItem::Type: //文字，设置字体
      {
          QGraphicsTextItem *theItem=qgraphicsitem_cast<QGraphicsTextItem*>(item);
          QFont font=theItem->font();
          bool ok=false;
          font=QFontDialog::getFont(&ok,font,this,"设置字体");
          if (ok)
              theItem->setFont(font);
          break;
        }
    }
}

// 4. 键盘按键事件(也就是键盘使用上下左右删除空格等键可以控制图形项)
void TestGraphicsViewDraw::on_keyPress(QKeyEvent *event)
{
    if (scene->selectedItems().count()!=1)
        return; //没有选中图形项，或选中的多于1个
    QGraphicsItem   *item=scene->selectedItems().at(0);
    // 下方的枚举类型定义在enum Qt::Key中
    if (event->key()==Qt::Key_Delete)//删除
       scene->removeItem(item);
    else if (event->key()==Qt::Key_Space) //顺时针旋转90度
       item->setRotation(90+item->rotation());
    else if (event->key()==Qt::Key_PageUp)//放大 ,键盘可能需要Fn+↑才能放大
        item->setScale(0.1+item->scale());
    else if (event->key()==Qt::Key_PageDown) //缩小 Fn+↓
        item->setScale(-0.1+item->scale());
    else if (event->key()==Qt::Key_Left)  //左移
        item->setX(-10+item->x());
    else if (event->key()==Qt::Key_Right) //右移
        item->setX(10+item->x());
    else if (event->key()==Qt::Key_Up) //上移
        item->setY(-10+item->y());
    else if (event->key()==Qt::Key_Down) //下移
        item->setY(10+item->y());
}
