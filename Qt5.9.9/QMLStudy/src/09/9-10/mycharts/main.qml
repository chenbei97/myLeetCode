import QtQuick
import QtCharts

Window {
    visible: true
    width: 400
    height: 320

    ChartView {
        title: "Bar series"
//      title: "Stacked Bar series"
//      title: "Percent Bar series"
        anchors.fill: parent
        legend { alignment: Qt.AlignBottom }
        antialiasing: true

        BarSeries {
//      StackedBarSeries {
//      PercentBarSeries {
            axisX: BarCategoryAxis { categories: ["2007", "2008", "2009"] }
            BarSet { label: "Bob"; values: [2, 2, 3] }
            BarSet { label: "Susan"; values: [5, 1, 2] }
            BarSet { label: "James"; values: [3, 5, 8] }
        }
    }
}

