#ifndef CUSTOMCHARTVIEW_H
#define CUSTOMCHARTVIEW_H

#include <QObject>
#include <QtCharts>
#include    <QChartView>

// QCharView������û������¼����źźͱ����̳к�����
// ����һ����Ϊ��ʹ��QChartView������,һ���滹Ҫ�Զ�������¼�,������Ҫ��������
// �پ���ϣ��ʵ�ֵ������ͼ���ܹ���ͼ�������һ������
// ֮ǰ������ֻ�ܶ�ͼ��������ƶ���ѡ�У�����ʹ�������Ӿ���һ���Ŵ���С
// ����Ψһ�ĸĽ���ͨ�����ƾ��ο�Ϳ���ʵ�ַŴ�
QT_CHARTS_USE_NAMESPACE

class customChartView :public QChartView
{
    Q_OBJECT
private:
    QPoint  beginPoint; //ѡ������������
    QPoint  endPoint;  //ѡ����������յ�
protected:
    void mousePressEvent(QMouseEvent *event); //����������
    void mouseMoveEvent(QMouseEvent *event); //����ƶ�
    void mouseReleaseEvent(QMouseEvent *event); //����ͷ����
    void keyPressEvent(QKeyEvent *event); //�����¼�
public:
    explicit customChartView(QWidget* parent=0);
signals:
    void mouseMovePoint(QPoint point); //����ƶ��źţ���mouseMoveEvent()�¼��д���
};

#endif // CUSTOMCHARTVIEW_H
