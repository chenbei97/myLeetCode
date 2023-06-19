import QtQuick 2.14
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

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

    Drawer { // 一个侧边栏控件
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



