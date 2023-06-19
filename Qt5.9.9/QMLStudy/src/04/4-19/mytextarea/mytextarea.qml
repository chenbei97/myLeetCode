import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

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

        TextField { // 单行文本编辑器
            placeholderText: qsTr("Enter name")
            onAccepted: console.log(text)
        }
    }
}




