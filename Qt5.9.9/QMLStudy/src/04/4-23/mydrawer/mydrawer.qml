import QtQuick
import QtQuick.Controls

ApplicationWindow {
    id: window
    width: 300; height: 400
    visible: true

    header: ToolBar {
        ToolButton {
            text: qsTr("⋮")
            onClicked: drawer.open()
        }
    }

    Drawer {
        id: drawer
        y: header.height;
        width: window.width * 0.6
        height: window.height - header.height

        Label {
            text: "Content goes here!"
            anchors.centerIn: parent
        }
    }

    Label {
        id: content

        text: "Content"
        font.pixelSize: 60
        anchors.fill: parent
        verticalAlignment: Label.AlignVCenter
        horizontalAlignment: Label.AlignHCenter

        transform: Translate {
            x: drawer.position * content.width * 0.33
        }
    }
}



