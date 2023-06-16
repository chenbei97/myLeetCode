import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 600; height: 400
    visible: true

    Button {
        text: qsTr("Button")
        onClicked: dialog.open()

        ToolTip.visible: down
        ToolTip.text: qsTr("打开对话框")
        ToolTip.timeout: 1000
        ToolTip.delay: 500

        Dialog {
            id: dialog
            title: qsTr("Dialog"); width: 300; height: 200
            parent: Overlay.overlay
            x: Math.round((parent.width - width) / 2)
            y: Math.round((parent.height - height) / 2)
            standardButtons: Dialog.Ok | Dialog.Cancel
            modal: true

            Label {
                text: qsTr("关闭对话框?")
                anchors.centerIn: parent
            }

            onAccepted: ApplicationWindow.window.close()
            onRejected: console.log("Cancel clicked")
        }
    }
}




