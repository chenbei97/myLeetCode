#ifndef TESTQCHARTZOOM_H
#define TESTQCHARTZOOM_H

#include <QMainWindow>
#include <QtCharts>
#include <QLabel>
#include "TestQChartZoom.h"
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class TestQChartZoom; }
QT_END_NAMESPACE

class TestQChartZoom : public QMainWindow
{
    Q_OBJECT
private:
    QLabel  *labXYValue; //״̬����ʾ���ֱ�ǩ
    void    createChart(); //����ͼ��
    void    prepareData();  //׼������
public:
    explicit TestQChartZoom(QWidget *parent = nullptr);
    ~TestQChartZoom();

private slots:
    void on_mouseMovePoint(QPoint point); //����ƶ��¼����Զ���ۺ���
    void on_LegendMarkerClicked();// ���ߺ�ͼ����ǵĹ����ۺ���
    void on_actZoomReset_triggered();//��λ
    void on_actZoomIn_triggered();//�Ŵ�
    void on_actZoomOut_triggered();//��С
private:
    Ui::TestQChartZoom *ui;
};
#endif // TESTQCHARTZOOM_H
