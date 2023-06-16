import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640; height: 480
    visible: true

    Pane {
        width: 400; height: 300; x:100; y: 50

        Image {
            id: image; anchors.fill: parent
            source: "https://www.qter.org/temp/back.png"
        }

        BusyIndicator {
            id:busy
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            running: image.status === Image.Loading
        }

        ProgressBar {
            width: parent.width - 20
            anchors.horizontalCenter: busy.horizontalCenter
            anchors.top: busy.bottom
            visible: image.status === Image.Loading
            value: image.progress
        }
    }
}

