#ifndef TESTQPAINTER_H
#define TESTQPAINTER_H

#include <QMainWindow>
#include <QPainter>
#include <QPainterPath>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui { class TestQPainter; }
QT_END_NAMESPACE

class TestQPainter : public QMainWindow
{
  Q_OBJECT

public:
    TestQPainter(QWidget *parent = nullptr);
    ~TestQPainter();
private:
      void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
      void design_pentagram();// 返回设计好的五角星绘制路径
      void paint();
      void viewPort_window();
private:
      Ui::TestQPainter *ui;
      QPainterPath* starPath;
};
#endif // TESTQPAINTER_H
