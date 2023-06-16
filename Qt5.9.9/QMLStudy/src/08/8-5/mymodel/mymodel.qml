import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    width: 220; height: 340

    ObjectModel {
        id: itemModel

        Rectangle { height: 30; width: 100; radius:5; color: "red" }

        Label { height: 20; width: 50; text: qsTr("标签控件") }

        Button { height: 30; width: 150; text: qsTr("按钮控件")}

        Switch { checked: true }

        Rectangle {
            height: 30; width: 60; border.width: 3; color: "yellow"
            Text { text: qsTr("文本项目"); anchors.centerIn: parent }
        }

        Frame {
            width: 150
            ColumnLayout {
                anchors.fill: parent
                CheckBox { text: qsTr("E-mail") }
                CheckBox { text: qsTr("Calendar") }
            }
        }

        ScrollView {
            width: 200; height: 70

            Label {
                text: "ABC"
                font.pixelSize: 90
            }
        }
    }

    ListView {
        anchors.fill: parent; anchors.margins: 5
        model: itemModel
        spacing: 10
    }
}

