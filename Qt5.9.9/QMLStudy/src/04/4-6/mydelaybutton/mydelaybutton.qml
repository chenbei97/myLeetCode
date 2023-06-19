import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

Window {
    width: 400; height: 100
    visible: true

    RowLayout {
        x:20; y:20; spacing: 20

        DelayButton {
            text: qsTr("延迟按钮"); delay: 1000
            onActivated: text = qsTr("已启动")
        }

        Switch {
            text: qsTr("Wi-Fi")
            onToggled: console.log(checked)
        }
    }
}


