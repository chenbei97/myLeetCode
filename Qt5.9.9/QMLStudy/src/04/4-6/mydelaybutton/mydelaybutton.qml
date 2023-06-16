import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 250; height: 100
    visible: true

    RowLayout {
        x:20; y:20; spacing: 20

        DelayButton {
            text: qsTr("延迟按钮"); delay: 5000
            onActivated: text = qsTr("已启动")
        }

        Switch {
            text: qsTr("Wi-Fi")
            onToggled: console.log(checked)
        }
    }
}


