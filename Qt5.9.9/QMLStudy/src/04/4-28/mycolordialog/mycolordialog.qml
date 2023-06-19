import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.1

ApplicationWindow {
    width: 640; height: 550
    visible: true

    header: ToolBar {
        RowLayout {
            anchors.fill: parent

            ToolButton {
                text: qsTr("颜色对话框")
                onClicked: colorDialog.open()
            }
            Label { id: label; text: qsTr("颜色展示")}
        }
    }

    ColorDialog {
        id: colorDialog

        options: ColorDialog.ShowAlphaChannel
        onAccepted: label.color = currentColor
    }
}
