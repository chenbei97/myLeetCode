import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

Window {
    width: 640
    height: 480
    visible: true

    Button {
        text: qsTr("消息对话框")
        onClicked: dlg.open()
    }

    MessageDialog {
        id: dlg
        title: qsTr("消息对话框")
        text: qsTr("这里是text的内容")
        informativeText: qsTr("这里是informativeText的内容")
        detailedText: qsTr("这里是detailedText的内容")
        buttons: MessageDialog.Ok | MessageDialog.Cancel
        onAccepted: console.log("ok")
    }
}


