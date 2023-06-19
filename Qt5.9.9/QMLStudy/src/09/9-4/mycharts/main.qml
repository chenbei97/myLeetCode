import QtQuick 2.9
import QtCharts 2.3
import QtQuick.Window 2.3

Window {
    visible: true
    width: 640
    height: 480

    ChartView {
        title: "LineSeries"
        anchors.fill: parent
        antialiasing: true

        DateTimeAxis {
            id: xAxis
            format: "MM-dd"
            tickCount: 12
            min: new Date(2023, 0, 15)
            max: new Date(2023, 11, 1)

            color: "blue"
            gridLineColor: "lightgreen"
            labelsAngle: 90
            labelsColor: "red"
            labelsFont { bold: true; pixelSize: 15 }
            shadesVisible: true
            shadesColor: "lightgrey"
            titleText: "date"
            titleFont { bold: true; pixelSize: 30 }
        }

        LineSeries {
            name: "LineSeries"
            axisX: xAxis

            XYPoint { x: toMsecsSinceEpoch(new Date(2023, 0, 2)); y: -5 }
            XYPoint { x: toMsecsSinceEpoch(new Date(2023, 1, 10)); y: 45 }
            XYPoint { x: toMsecsSinceEpoch(new Date(2023, 2, 23)); y: 5 }
            XYPoint { x: toMsecsSinceEpoch(new Date(2023, 3, 21)); y: 12 }
            XYPoint { x: toMsecsSinceEpoch(new Date(2023, 4, 12)); y: 12 }
            XYPoint { x: toMsecsSinceEpoch(new Date(2023, 5, 13)); y: 18 }
            XYPoint { x: toMsecsSinceEpoch(new Date(2023, 6, 19)); y: 30 }
            XYPoint { x: toMsecsSinceEpoch(new Date(2023, 7, 29)); y: 40 }
            XYPoint { x: toMsecsSinceEpoch(new Date(2023, 8, 30)); y: 30 }
            XYPoint { x: toMsecsSinceEpoch(new Date(2023, 9, 14)); y: 30 }
        }
    }

    function toMsecsSinceEpoch(date) {
        var msecs = date.getTime();
        return msecs;
    }
}





