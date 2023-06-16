import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts

ApplicationWindow {
    width: 640; height: 550
    visible: true

    RowLayout {
        Button {
            text: qsTr("字体对话框")
            onClicked: fontDialog.open()
        }

        Label {
            id: label
            text: qsTr("字体展示")
            font: fontDialog.selectedFont
        }
    }

    FontDialog {
        id: fontDialog
    }
}



