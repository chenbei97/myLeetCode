import QtQuick
import Qt.labs.qmlmodels
import QtQuick.Controls

Window {
    width: 200; height: 150
    visible: true

    TableView {
        id: tableView
        anchors.fill: parent
        columnSpacing: 1; rowSpacing: 1
        clip: true

        model: TableModel {
            TableModelColumn { display: "name" }
            TableModelColumn { display: "color" }

            rows: [
                { "name": "cat", "color": "black" },
                { "name": "dog", "color": "brown" },
                { "name": "bird", "color": "white" },
                { "name": "fish", "color": "blue" },
                { "name": "cattle", "color": "yellow" }
            ]
        }

        delegate: tableViewDelegate

        selectionModel: ItemSelectionModel {  }

        Component {
            id: tableViewDelegate

            Rectangle {
                implicitWidth: 100; implicitHeight: 50
                border.width: 2
                required property bool current

                color: current ? "blue" : "white"

                TableView.onPooled: rotationAnimation.pause()
                TableView.onReused: rotationAnimation.resume()

                Text { id: txt; text: display; anchors.centerIn: parent }

                RotationAnimation {
                    id: rotationAnimation; target: txt
                    duration: (Math.random() * 5000) + 2000
                    from: 0;  to: 359; running: true
                    loops: Animation.Infinite
                }
            }
        }

        property var columnWidths: [100, 50]
        columnWidthProvider: function (column) { return columnWidths[column] }

        Timer {
            running: true; interval: 2000

            onTriggered: {
                tableView.columnWidths[1] = 100
                tableView.forceLayout();
            }
        }
    }
}
