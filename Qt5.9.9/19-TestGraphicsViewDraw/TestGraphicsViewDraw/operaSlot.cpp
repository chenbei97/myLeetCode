#include "TestGraphicsViewDraw.h"
#include "ui_TestGraphicsViewDraw.h"
#include <QGraphicsItem>
#include <QDebug>

// 1. 放大
void TestGraphicsViewDraw::on_actZoomIn_triggered()
{
    int cnt=scene->selectedItems().count();
    if (cnt==1) // 如果选中的只有1个图形,那就只对它放大
    {
        QGraphicsItem   *item;
        item=scene->selectedItems().at(0);
        item->setScale(0.1+item->scale());
    }
    else // 否则全部放大,按照1.1的比率放大
        ui->graphicsView->scale(1.1,1.1);
}

// 2. 缩小
void TestGraphicsViewDraw::on_actZoomOut_triggered()
{
    int cnt=scene->selectedItems().count();
    if (cnt==1) // 同理
    {
        QGraphicsItem   *item;
        item=scene->selectedItems().at(0);
        item->setScale(item->scale()-0.1);
    }
    else
        ui->graphicsView->scale(0.9,0.9);
}

// 3. 恢复
void TestGraphicsViewDraw::on_actRestore_triggered()
{
    int cnt=scene->selectedItems().count();
    if (cnt==1)
    {
        QGraphicsItem* item=scene->selectedItems().at(0);
        // item->resetTransform(); //只对1个图形项用这个不起作用
        item->setRotation(0);
        item->setScale(1.0);
    }
    else
        ui->graphicsView->resetTransform(); // 整体恢复可以使用
}

// 4. 左旋转
void TestGraphicsViewDraw::on_actRotateLeft_triggered()
{
    int cnt=scene->selectedItems().count();
    if (cnt==1)
    {
        QGraphicsItem* item=scene->selectedItems().at(0);
        item->setRotation(-30+item->rotation()); // 旋转30°
    }
    else
        ui->graphicsView->rotate(-30);
}

// 5. 右旋转
void TestGraphicsViewDraw::on_actRotateRight_triggered()
{
    int cnt=scene->selectedItems().count();
    if (cnt==1)
    {
        QGraphicsItem* item=scene->selectedItems().at(0);
        item->setRotation(+30+item->rotation());
    }
    else
        ui->graphicsView->rotate(+30);
}

// 6. 图形前置(就是让Z的级别提高)
void TestGraphicsViewDraw::on_actEdit_Front_triggered()
{
    int cnt=scene->selectedItems().count();
    if (cnt>0)
    { //只处理选中的第1个绘图项
        QGraphicsItem* item=scene->selectedItems().at(0);
        // qDebug()<<"before frontZ = "<<frontZ;
        item->setZValue(++this->frontZ);
        // qDebug()<<"after frontZ = "<<frontZ;
    }
}

// 7. 图形后置
void TestGraphicsViewDraw::on_actEdit_Back_triggered()
{
    int cnt=scene->selectedItems().count();
    if (cnt>0)
    {//只处理选中的第1个绘图项
        QGraphicsItem* item=scene->selectedItems().at(0);
        // qDebug()<<"before backZ = "<<backZ;
        item->setZValue(--this->backZ);
        // qDebug()<<"after backZ = "<<backZ;
    }
}

// 8. 组合图形
void TestGraphicsViewDraw::on_actGroup_triggered()
{
    // 所谓组合就是叠放次序是一样的
    int cnt=scene->selectedItems().count();
    if (cnt>1)
    {
       QGraphicsItemGroup* group =new QGraphicsItemGroup; //创建组合
       scene->addItem(group); //组合添加到场景中

        for (int i=0;i<cnt;i++)
        {
            QGraphicsItem* item=scene->selectedItems().at(0);
            item->setSelected(false); //清除选择虚线框,这样就遍历下1个,不需要使用变量i来访问
            item->clearFocus();
            group->addToGroup(item); //添加到组合
        }
        group->setFlags(QGraphicsItem::ItemIsMovable
                       | QGraphicsItem::ItemIsSelectable
                       | QGraphicsItem::ItemIsFocusable);

        group->setZValue(++frontZ); // 整体是相同的叠放次序
        group->clearFocus();
        scene->clearSelection();
        group->setSelected(true);
     }
}

// 9. 取消组合图形
void TestGraphicsViewDraw::on_actGroupBreak_triggered()
{
    int cnt=scene->selectedItems().count();
    if (cnt==1)
    {
        QGraphicsItemGroup  *group;
        group=(QGraphicsItemGroup*)scene->selectedItems().at(0);
        scene->destroyItemGroup(group);
     }
}

// 10. 删除图形
void TestGraphicsViewDraw::on_actEdit_Delete_triggered()
{
     int cnt=scene->selectedItems().count(); // 所有选中的删除
    if (cnt>0)
    for (int i=0;i<cnt;i++)
    {
        QGraphicsItem*  item=scene->selectedItems().at(0);
        scene->removeItem(item); //删除绘图项
    }
}
