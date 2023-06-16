import QtQuick

Item {
    width: 600; height: 600
    Rectangle {
        width: 50; height: width * 2
        color: "red"; anchors.centerIn: parent; focus: true
        Keys.onSpacePressed: height = Qt.binding(
                                 function() { return width * 3 })

        MouseArea {
            anchors.fill: parent
            onClicked: parent.width += 10
        }
    }
}
