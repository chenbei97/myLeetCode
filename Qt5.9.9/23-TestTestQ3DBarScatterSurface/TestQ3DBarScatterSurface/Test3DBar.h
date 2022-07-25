#ifndef TEST3DBAR_H
#define TEST3DBAR_H

#include <QMainWindow>
#include    <QtDataVisualization>
using namespace QtDataVisualization;
namespace Ui {
  class Test3DBar;
}

class Test3DBar : public QMainWindow
{
  Q_OBJECT
private:
    QWidget *graphContainer;//图表的容器
    Q3DBars *graph3D;   //图表
    QBar3DSeries *series;   //序列
    void iniGraph3D();   //创建图表
public:
  explicit Test3DBar(QWidget *parent = nullptr);
  ~Test3DBar();
private slots:
    void on_comboCamera_currentIndexChanged(int index);
    void on_sliderH_valueChanged(int value);
    void on_sliderV_valueChanged(int value);
    void on_sliderZoom_valueChanged(int value);
    void on_cBoxTheme_currentIndexChanged(int index);
    void on_cBoxBarStyle_currentIndexChanged(int index);
    void on_cBoxSelectionMode_currentIndexChanged(int index);
    void on_spinFontSize_valueChanged(int arg1);
    void on_btnBarColor_clicked();
    void on_chkBoxBackground_clicked(bool checked);
    void on_chkBoxGrid_clicked(bool checked);
    void on_chkBoxSmooth_clicked(bool checked);
    void on_chkBoxReflection_clicked(bool checked);
    void on_chkBoxReverse_clicked(bool checked);
    void on_chkBoxItemLabel_clicked(bool checked);
    void on_chkBoxAxisTitle_clicked(bool checked);
    void on_chkBoxAxisBackground_clicked(bool checked);
private:
  Ui::Test3DBar *ui;
};

#endif // TEST3DBAR_H
