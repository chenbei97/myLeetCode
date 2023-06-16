import QtQuick

Rectangle {
    id: rect
    color: "yellow"
    property color nextColor: "blue"
    width: 400; height: 300
    Component.onCompleted: {
        rect.color = "red"
    }
    MouseArea {
        anchors.fill:parent
        onClicked: color = nextColor
    }
}



