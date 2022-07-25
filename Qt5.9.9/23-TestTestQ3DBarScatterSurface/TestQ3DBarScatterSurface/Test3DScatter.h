#ifndef TEST3DSCATTER_H
#define TEST3DSCATTER_H

#include <QMainWindow>
#include <QtDataVisualization>
using namespace  QtDataVisualization;
namespace Ui {
  class Test3DScatter;
}

class Test3DScatter : public QMainWindow
{
  Q_OBJECT
  private:
    QWidget     *graphContainer;// 容器
    Q3DScatter  *graph3D;       //散点图
    QScatter3DSeries *series;  //散点序列
    void    iniGraph3D(); //初始化绘图
    QVector3D randVector(); // 散点坐标向量
public:
  explicit Test3DScatter(QWidget *parent = nullptr);
  ~Test3DScatter();

private slots:
  void on_comboBox_currentIndexChanged(int index);
  void on_sliderH_valueChanged(int value);
  void on_sliderV_valueChanged(int value);
  void on_sliderZoom_valueChanged(int value);
  void on_cBoxTheme_currentIndexChanged(int index);
  void on_cBoxBarStyle_currentIndexChanged(int index);
  void on_cBoxSelectionMode_currentIndexChanged(int index);
  void on_spinFontSize_valueChanged(int arg1);
  void on_spinItemSize_valueChanged(double arg1);
  void on_btnBarColor_clicked();
  void on_chkBoxBackground_clicked(bool checked);
  void on_chkBoxGrid_clicked(bool checked);
  void on_chkBoxShadow_clicked(bool checked);
  void on_chkBoxReflection_clicked(bool checked);
  void on_chkBoxSmooth_clicked(bool checked);
  void on_chkBoxReverse_clicked(bool checked);
  void on_chkBoxItemLabel_clicked(bool checked);
  void on_chkBoxAxisTitle_clicked(bool checked);
  void on_chkBoxAxisBackground_clicked(bool checked);
private:
  Ui::Test3DScatter *ui;
};

#endif // TEST3DSCATTER_H
