#ifndef TESTQ3DBARSCATTERSURFACE_H
#define TESTQ3DBARSCATTERSURFACE_H

#include <QMainWindow>
#include "Test3DMap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestQ3DBarScatterSurface; }
QT_END_NAMESPACE

class TestQ3DBarScatterSurface : public QMainWindow
{
  Q_OBJECT

public:
  TestQ3DBarScatterSurface(QWidget *parent = nullptr);
  ~TestQ3DBarScatterSurface();

private slots:
  void on_act3DBar_triggered();
  void on_act3DScatter_triggered();
  void on_act3DSurface_triggered();
  void on_act3DMap_triggered();
  void on_actExit_triggered();
  void on_pushButton_clicked();
signals:
  void mapImageName(QString name);
private:
  Ui::TestQ3DBarScatterSurface *ui;
  Test3DMap * map;
};
#endif // TESTQ3DBARSCATTERSURFACE_H
