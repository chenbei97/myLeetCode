import QtQuick

Rectangle {
    id: rect; width: 400; height: 300

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Connections {
        target: mouseArea
        function onClicked() {
            rect.color = "red"
        }
    }
}


