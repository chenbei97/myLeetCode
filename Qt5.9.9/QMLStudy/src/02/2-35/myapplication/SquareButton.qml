import QtQuick

Rectangle {
    id: root

    property bool pressed: mouseArea.pressed

    signal buttonClicked(real xPos, real yPos)

    function randomizeColor() {
        root.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
    }

    width: 100; height: 100
    color: "red"

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: (mouse)=> root.buttonClicked(mouse.x, mouse.y)
    }
}
