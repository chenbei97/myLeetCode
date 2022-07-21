#ifndef TESTGRAPHICSVIEWDRAW_H
#define TESTGRAPHICSVIEWDRAW_H

#include <QMainWindow>
#include    <QGraphicsScene>
#include    <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class TestGraphicsViewDraw; }
QT_END_NAMESPACE

class TestGraphicsViewDraw : public QMainWindow
{
  Q_OBJECT

public:
  TestGraphicsViewDraw(QWidget *parent = nullptr);
  ~TestGraphicsViewDraw();
private:
    void initViewScene();
    void initStatusBar();
    void initMouseEventConnection();
private:
     // 每个图形项可以设置data,data又可以设置不同角色,这里自定义了编号和描述2种数据角色
    static const int ItemId = 1;  // 图形项的编号
    static const int ItemDesciption = 2;   //图形项的描述

    int seqNum=0; // 创建的编号值,每创建1个图形项就++
    //前置后置值都是共用的,任何一个图形项使用前后置功能就会++,永远是递增的,一定会叠放在任意图形项之上
    int backZ=0; // 用于计算后置值
    int frontZ=0;// 用于计算前置值

    QGraphicsScene  *scene;
    QLabel  *labViewCord;
    QLabel  *labSceneCord;
    QLabel  *labItemCord;
    QLabel  *labItemInfo;
private slots:
    // 4个鼠标事件
    void on_mouseMovePoint(QPoint point); //鼠标移动
    void on_mouseClicked(QPoint point); //鼠标单击
    void on_mouseDoubleClick(QPoint point); //鼠标双击
    void on_keyPress(QKeyEvent *event); //按键
  // 添加形状
  void on_actItem_Rect_triggered();
  void on_actItem_Ellipse_triggered();
  void on_actItem_Line_triggered();
  void on_actItem_Polygon_triggered();
  void on_actItem_Text_triggered();
  void on_actItem_Circle_triggered();
  void on_actItem_Triangle_triggered();
  void on_actZoomIn_triggered();
  // 对形状的操作
  void on_actZoomOut_triggered();
  void on_actRestore_triggered();
  void on_actRotateLeft_triggered();
  void on_actRotateRight_triggered();
  void on_actEdit_Front_triggered();
  void on_actEdit_Back_triggered();
  void on_actGroup_triggered();
  void on_actGroupBreak_triggered();
  void on_actEdit_Delete_triggered();
private:
  Ui::TestGraphicsViewDraw *ui;
};
#endif // TESTGRAPHICSVIEWDRAW_H
