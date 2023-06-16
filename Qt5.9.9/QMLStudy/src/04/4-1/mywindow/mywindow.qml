import QtQuick 2.14
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: root
    property bool changed: true

    width: 640; height: 480
    x: 100; y:100
    visible: true
    title: qsTr("My Window")
    opacity: 0.7
    color: "lightblue"

    onClosing: (close) => {
                   if (changed) {
                       close.accepted = false // 没有这个关掉父窗口子窗口也会关掉
                       dialog.show()
                   }
                   else {
                       close.accepted = true
                        // 但还希望子窗口点确定的时候父窗口能够关掉,所以子窗口点击时让事件接受
                   }
               }

    Window {
        id: dialog
        width: 400; height: 200
        flags : Qt.Dialog
        modality : Qt.WindowModal

        Label {
            text: qsTr("确定要退出吗？")
            x: 120; y: 50
        }

        Row {
            spacing: 10
            x:120; y:80

            Button {
                text: qsTr("确定")
                onClicked: {
                    root.changed = false
                    dialog.close() // 让子窗口立即关闭
                    root.close()
                }
            }
            Button {
                text: qsTr("取消")
                onClicked: {
                    dialog.close()
                }
            }
        }
    }
}



