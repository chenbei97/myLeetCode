import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.1
import QtQuick.Window 2.0

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


