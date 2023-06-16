import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts

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
        selectedColor: label.color
        options: ColorDialog.ShowAlphaChannel
        onAccepted: label.color = selectedColor
    }
}
