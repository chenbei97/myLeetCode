import QtQuick
import QtCharts
import QtQml.Models

Window {
    visible: true
    width: 640; height: 480
    property int currentIndex: -1

    ChartView {
        id: chartView
        anchors.fill: parent
        title: qsTr("我的网站访问量")
        theme: ChartView.ChartThemeBlueCerulean
        antialiasing: true
    }

    ListModel {
        id: listModel

        ListElement { month: 1; pv: 205864 }
        ListElement { month: 2; pv: 254681 }
        ListElement { month: 3; pv: 306582 }
        ListElement { month: 4; pv: 284326 }
        ListElement { month: 5; pv: 248957 }
        ListElement { month: 6; pv: 315624 }
    }

    Timer {
        id: timer
        interval: 1500; repeat: true
        triggeredOnStart: true; running: true
        onTriggered: {
            currentIndex++;
            if (currentIndex < listModel.count) {
                var lineSeries = chartView.series("2018");
                // 第一次运行时创建曲线
                if (!lineSeries) {
                    lineSeries = chartView.createSeries(ChartView.SeriesTypeSpline, "2018");
                    chartView.axisY().min = 200000;
                    chartView.axisY().max = 320000;
                    chartView.axisY().tickCount = 6;
                    chartView.axisY().titleText = qsTr("PV");
                    chartView.axisX().visible = false
                    lineSeries.color = "#87CEFA"
                    lineSeries.pointsVisible = true
                    lineSeries.pointLabelsVisible = true
                    lineSeries.pointLabelsFormat = qsTr("@xPoint月份PV:@yPoint")
                    chartView.animationOptions = ChartView.SeriesAnimations
                }

                lineSeries.append(listModel.get(currentIndex).month,
                                  listModel.get(currentIndex).pv);

                if (listModel.get(currentIndex).month > 3) {
                    chartView.axisX().max =
                            Number(listModel.get(currentIndex).month) + 1;
                    chartView.axisX().min = chartView.axisX().max - 5;
                } else {
                    chartView.axisX().max = 5;
                    chartView.axisX().min = 0;
                }
                chartView.axisX().tickCount = chartView.axisX().max
                        - chartView.axisX().min + 1;
            } else {
                timer.stop();
                chartView.axisX().min = 0;
            }
        }
    }
}



