import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 200; height: 300
    visible: true

    ScrollView {
        id: view
        anchors.fill: parent

        TextArea {
            placeholderText: qsTr("可以在这里输入内容")
            wrapMode: Text.WordWrap
        }
    }

    footer: RowLayout {
        Label {
            text: qsTr("姓名："); font.pointSize: 7
            background: Rectangle { color: "lightgrey" }
        }

        TextField {
            placeholderText: qsTr("Enter name")
            onAccepted: console.log(text)
        }
    }
}




