#include "TestGraphicsViewDraw.h"
#include "ui_TestGraphicsViewDraw.h"
#include <QInputDialog>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QGraphicsPolygonItem>

// 1. 矩形
void TestGraphicsViewDraw::on_actItem_Rect_triggered()
{
    // 新建矩形的长度100,宽度50,位置是场景坐标(0,0)
    QGraphicsRectItem   *item=new QGraphicsRectItem(0,0,200,100);
    item->setFlags(QGraphicsItem::ItemIsMovable // 可移动,可选择,可聚焦,初始填充颜色黄色
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);
    item->setBrush(QBrush(Qt::yellow));
    item->setZValue(++frontZ);
    item->setPos(qrand() % 200,qrand() % 200); // 设置位置为随机值,中心(0,0)位置±200的正方形区域分布

    item->setData(ItemId,++this->seqNum);
    item->setData(ItemDesciption,"矩形");

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

// 2. 椭圆
void TestGraphicsViewDraw::on_actItem_Ellipse_triggered()
{
      QGraphicsEllipseItem   *item=new QGraphicsEllipseItem(0,0,200,120);
      item->setFlags(QGraphicsItem::ItemIsMovable
                     | QGraphicsItem::ItemIsSelectable
                     | QGraphicsItem::ItemIsFocusable);
      item->setBrush(QBrush(Qt::blue)); //填充颜色
      item->setZValue(++frontZ); //用于叠放顺序,如果发生了叠放,创建的椭圆会在矩形上方
      item->setPos(qrand() % 200,qrand() % 200); //初始位置
      item->setData(ItemId,++seqNum);  //自定义数据，ItemId键
      item->setData(ItemDesciption,"椭圆"); //自定义数据，ItemDesciption键

      scene->addItem(item);
      scene->clearSelection();
      item->setSelected(true);
}

// 3. 直线
void TestGraphicsViewDraw::on_actItem_Line_triggered()
{
    QGraphicsLineItem   *item=new QGraphicsLineItem(0,0,100,0);
    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);

    QPen    pen(Qt::red);
    pen.setWidth(3);
    item->setPen(pen);

    item->setZValue(++frontZ);
    item->setPos(qrand() % 200,qrand() % 200);

    item->setData(ItemId,++seqNum);
    item->setData(ItemDesciption,"直线");

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

// 4. 梯形
void TestGraphicsViewDraw::on_actItem_Polygon_triggered()
{
    QGraphicsPolygonItem   *item=new QGraphicsPolygonItem;

    /*
         创建53°的梯形,中间的矩形区域长度是100,2个三角的底边长度60,直角边80,斜边100
                                           100
                                *  *  *  *  *  *  *  *  *  *
                              *                                       *
                            *                                           *
                          *                                               *
                        *                                                    *    100
                      *                                                        *
                    *                                                            *
                  *                                                                *
                *                                                                     *
              *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * *
                    60                        100                        60
      中心坐标为(0,0),那么左下顶点坐标是(-110,40),左上顶点坐标是(-50,-40)
      右上角顶点坐标(50,-40),右下角顶点坐标是(110,40)
    */

    QPolygonF   points;
    points.append(QPointF(-110,40));
    points.append(QPointF(-50,-40));
    points.append(QPointF(50,-40));
    points.append(QPointF(110,40));
    item->setPolygon(points);
    item->setPos(qrand() % 200,qrand() % 200);

    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);
    item->setBrush(QBrush(Qt::green));
    item->setZValue(++frontZ);

    item->setData(ItemId,++seqNum);
    item->setData(ItemDesciption,"梯形");

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

// 5. 文字
void TestGraphicsViewDraw::on_actItem_Text_triggered()
{
    QString str=QInputDialog::getText(this,"输入文字","请输入文字");
    if (str.isEmpty())
        return;

    QGraphicsTextItem   *item=new QGraphicsTextItem(str);

    QFont   font=this->font();
    font.setPointSize(20);
    font.setBold(true);
    item->setFont(font);

    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);
    item->setPos(qrand() % 200,qrand() % 200);
    item->setZValue(++frontZ);

    item->setData(ItemId,++seqNum);
    item->setData(ItemDesciption,"文字");

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

// 6. 圆形
void TestGraphicsViewDraw::on_actItem_Circle_triggered()
{
    QGraphicsEllipseItem   *item=new QGraphicsEllipseItem(0,0,150,150);
    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);
    item->setBrush(QBrush(Qt::cyan));
    item->setZValue(++frontZ);
    item->setPos(qrand() % 200,qrand() % 200);

    item->setData(ItemId,++seqNum);
    item->setData(ItemDesciption,"圆形");

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

// 7. 三角形
void TestGraphicsViewDraw::on_actItem_Triangle_triggered()
{
    QGraphicsPolygonItem   *item=new QGraphicsPolygonItem;
    QPolygonF   points;
    points.append(QPointF(-50,50/1.732));
    points.append(QPointF(50,50/1.732));
    points.append(QPointF(0,-100/1.732));
    item->setPolygon(points);
    item->setPos(qrand() % 200,qrand() % 200);

    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);
    item->setBrush(QBrush(Qt::magenta));
    item->setZValue(++frontZ);

    item->setData(ItemId,++seqNum);
    item->setData(ItemDesciption,"三角形");

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}
