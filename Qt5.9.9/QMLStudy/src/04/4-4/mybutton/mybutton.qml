import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

Window {
    width: 350; height: 200
    visible: true

    RowLayout {
        anchors.fill: parent
        spacing: 10
        Button { text: qsTr("普通按钮"); onClicked: close() }
        Button { text: qsTr("flat按钮"); flat: true }
        Button { text: qsTr("高亮按钮"); highlighted: true }
        RoundButton { text: qsTr("圆角按钮"); radius: 5 }
        RoundButton { text: qsTr("圆形按钮"); implicitWidth: 60;
            implicitHeight: 60; radius: width / 2 }
    }
}
