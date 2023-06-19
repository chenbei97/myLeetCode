import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

Window {
    //width: 400; height: 300
    visible: true
    width: layout.implicitWidth
    height: layout.implicitHeight

    RowLayout {
        id: layout
        anchors.fill: parent
        spacing: 20
        Rectangle {
            color: 'lightgrey'
            Layout.fillWidth: true
            Layout.minimumWidth: 50
            Layout.preferredWidth: 100
            Layout.maximumWidth: 300 // 限制最大宽度300
            Layout.minimumHeight: 150

            Layout.fillHeight: true // 不限制高度

            Text {
                anchors.centerIn: parent
                text: parent.width + 'x' + parent.height
            }
        }
        Rectangle {
            color: 'black'
            Layout.fillWidth: true
            Layout.minimumWidth: 100
            Layout.preferredWidth: 200
            Layout.preferredHeight: 100

            Layout.fillHeight: true
            Layout.maximumHeight: 300;//限制高度300
            Layout.minimumHeight: 100; // 最低100
            Text {
                anchors.centerIn: parent
                text: parent.width + 'x' + parent.height
                color: "white"
            }
        }
    }
}

