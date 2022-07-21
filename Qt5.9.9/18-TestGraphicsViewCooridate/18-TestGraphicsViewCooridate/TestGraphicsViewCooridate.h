#ifndef TESTGRAPHICSVIEWCOORIDATE_H
#define TESTGRAPHICSVIEWCOORIDATE_H

#include <QMainWindow>
#include <QLabel>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class TestGraphicsViewCooridate; }
QT_END_NAMESPACE

class TestGraphicsViewCooridate : public QMainWindow
{
  Q_OBJECT

public:
  TestGraphicsViewCooridate(QWidget *parent = nullptr);
  ~TestGraphicsViewCooridate();
protected:
    void resizeEvent(QResizeEvent * event) override;
private:
  Ui::TestGraphicsViewCooridate *ui;
    QGraphicsScene  *scene; // 场景需要被视图的setScene关联
    QLabel  *labViewCord; // 视图坐标(物理坐标)
    QLabel  *labSceneCord; // 场景坐标(逻辑坐标)
    QLabel  *labItemCord; // 图形项坐标(局部逻辑坐标)
    void initStatusBar();
    void iniGraphicsSystem(); //创建Graphics View的各项

private slots: // 用于响应自定义视图组件的2个鼠标信号
    void    on_mouseMovePoint(QPoint point);
    void    on_mouseClicked(QPoint point);
};
#endif // TESTGRAPHICSVIEWCOORIDATE_H
