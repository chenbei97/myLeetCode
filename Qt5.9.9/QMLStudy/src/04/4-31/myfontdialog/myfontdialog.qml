import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.1

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
            font: fontDialog.currentFont
        }
    }

    FontDialog {
        id: fontDialog
    }
}



