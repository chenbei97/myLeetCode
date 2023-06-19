import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

Window {
    width: 640; height: 480
    visible: true

    Pane {
        width: 400; height: 300; x:100; y: 50

        Image {
            id: image; anchors.fill: parent
            source: "https://www.qter.org/temp/back.png"
            //source:"https://github.com/chenbei97/myLeetCode/blob/main/%E9%98%BF%E9%87%8C%E4%BA%91%E5%A4%A9%E6%B1%A0leetcode%E8%AF%81%E4%B9%A6.png"
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

