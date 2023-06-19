import QtQuick 2.9
import QtCharts 2.3
import QtQuick.Window 2.3
import QtQml.Models 2.3

Window {
    visible: true
    width: 640
    height: 480

    ChartView {
        id: chart
        title: "PieSeries"
        anchors.fill: parent
        legend { alignment: Qt.AlignBottom }
        antialiasing: true

        PieSeries {
            id: pieSeries
            PieSlice { label: "Volkswagen"; value: 13.5 }
            PieSlice { label: "Toyota"; value: 10.9 }
            PieSlice { label: "Ford"; value: 8.6 }
            PieSlice { label: "Skoda"; value: 8.2 }
            PieSlice { label: "Volvo"; value: 6.8 }
        }
    }

    Component.onCompleted: {
        pieSeries.append("Others", 52.0);
        var pieSlice = pieSeries.find("Volkswagen");
        pieSlice.exploded = true;
        pieSlice.labelVisible = true;
    }
}

