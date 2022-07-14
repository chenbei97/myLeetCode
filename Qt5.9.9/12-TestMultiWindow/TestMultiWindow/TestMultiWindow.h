#ifndef TESTMULTIWINDOW_H
#define TESTMULTIWINDOW_H

#include <QMainWindow>
#include "QFormDoc.h" // widget作为基类
#include "QFormTable.h" // window作为基类

QT_BEGIN_NAMESPACE
namespace Ui { class TestMultiWindow; }
QT_END_NAMESPACE

class TestMultiWindow : public QMainWindow
{
  Q_OBJECT

public:
  TestMultiWindow(QWidget *parent = nullptr);
  ~TestMultiWindow();
private:
    void    paintEvent(QPaintEvent *event);
private slots:
    void setActWidgetEnable(bool able);
private slots:
  void on_actWidgetInsite_triggered();
  void on_actWidget_triggered();
  void on_actWindowInsite_triggered();
  void on_actWindow_triggered();
  void on_tabWidget_tabCloseRequested(int index);
  void on_tabWidget_currentChanged(int index);
private:
  Ui::TestMultiWindow *ui;
};
#endif // TESTMULTIWINDOW_H
