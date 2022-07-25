#ifndef TEST3DMAP_H
#define TEST3DMAP_H

#include <QMainWindow>
#include    <QtDataVisualization>
using namespace QtDataVisualization;
namespace Ui {
  class Test3DMap;
}

class Test3DMap : public QMainWindow
{
  Q_OBJECT
private:
    QWidget     *graphContainer = nullptr;// 图表容器
    Q3DSurface          *graph3D = nullptr;       //三维图表
    QSurface3DSeries    *series = nullptr;        //序列
    QHeightMapSurfaceDataProxy   *proxy = nullptr; //数据代理
    QString imageName;
    void initBtnGrad();
    void iniGraph3D();
public:
  explicit Test3DMap(QWidget *parent = nullptr);
  ~Test3DMap();
private slots:
  void on_mapImageName(QString name);
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_sliderH_valueChanged(int value);
    void on_sliderV_valueChanged(int value);
    void on_sliderZoom_valueChanged(int value);
    void on_cBoxTheme_currentIndexChanged(int index);
    void on_cBoxBarStyle_currentIndexChanged(int index);
    void on_cBoxSelectionMode_currentIndexChanged(int index);
    void on_spinFontSize_valueChanged(int arg1);
    void on_comboDrawMode_currentIndexChanged(int index);
    void on_chkBoxBackground_clicked(bool checked);
    void on_chkBoxGrid_clicked(bool checked);
    void on_chkBoxShadow_clicked(bool checked);
    void on_chkBoxReflection_clicked(bool checked);
    void on_chkBoxSmooth_clicked(bool checked);
    void on_chkBoxReverse_clicked(bool checked);
    void on_chkBoxItemLabel_clicked(bool checked);
    void on_chkBoxAxisTitle_clicked(bool checked);
    void on_chkBoxAxisBackground_clicked(bool checked);
    void on_btnGrad1_clicked();
    void on_btnGrad2_clicked();
    void on_btnBarColor_clicked();
private:
  Ui::Test3DMap *ui;
};

#endif // TEST3DMAP_H
