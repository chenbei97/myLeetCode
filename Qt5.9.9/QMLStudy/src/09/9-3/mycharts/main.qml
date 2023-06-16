import QtQuick
import QtCharts

Window {
    visible: true
    width: 640
    height: 480

    ChartView {
        title: "BarSeries"
        anchors.fill: parent
        antialiasing: true

        BarSeries {
            axisX: BarCategoryAxis { categories: ["2007", "2008", "2009",
                    "2010", "2011", "2012" ] }
            BarSet { label: "Bob"; values: [2, 2, 3, 4, 5, 6] }
            BarSet { label: "Susan"; values: [5, 1, 2, 4, 1, 7] }
            BarSet { label: "James"; values: [3, 5, 8, 13, 5, 8] }
        }
    }
}






