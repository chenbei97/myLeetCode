import QtQuick
import QtCharts

Window {
    visible: true
    width: 640
    height: 480

    ChartView {
        title: "Scatter"
        anchors.fill: parent
        antialiasing: true

        ScatterSeries {
            id: scatter1
            name: "Scatter1"
            markerShape: ScatterSeries.MarkerShapeRectangle
            markerSize: 20
            XYPoint { x: 1.51; y: 1.5 }
            XYPoint { x: 1.5; y: 1.6 }
            XYPoint { x: 1.57; y: 1.55 }
            XYPoint { x: 1.55; y: 1.55 }
            onPressed: (point) => console.log("onPressed: "
                                              + point.x + ", " + point.y);
            onReleased: (point) => console.log("onReleased: "
                                               + point.x + ", " + point.y);
        }

        ScatterSeries {
            id: scatter2
            name: "Scatter2"
            borderColor: "black"
            borderWidth: 5
            XYPoint { x: 1.52; y: 1.56 }
            XYPoint { x: 1.55; y: 1.58 }
            XYPoint { x: 1.53; y: 1.54 }
            XYPoint { x: 1.54; y: 1.59 }
            onClicked: (point) => console.log("onClicked: "
                                              + point.x + ", " + point.y);
        }
    }
}




