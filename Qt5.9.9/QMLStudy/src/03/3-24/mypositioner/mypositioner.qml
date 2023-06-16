import QtQuick

Grid {
    padding: 5

    Repeater {
        model: 16

        Rectangle {
            id: rect
            width: 40; height: 40
            border.width: 1
            color: Positioner.isFirstItem ? "yellow" : "lightsteelblue"

            Text { text: rect.Positioner.index; anchors.centerIn: parent }
        }
    }
}
