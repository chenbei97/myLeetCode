import QtQuick

Rectangle {
    id: forwarder
    width: 400; height: 300

    signal send()
    onSend: console.log("Send clicked")

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: console.log("MouseArea clicked")
    }

    Component.onCompleted: {
        mouseArea.clicked.connect(send)
    }
}



