import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Layouts
import QtCore

ApplicationWindow {
    width: 640; height: 480
    visible: true

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("目录对话框")
                onClicked: folderDialog.open()
            }
            Label { id: label; text: folderDialog.selectedFolder}
        }
    }

    FolderDialog {
        id: folderDialog
        currentFolder: StandardPaths.standardLocations
                       (StandardPaths.DocumentsLocation)[0]
    }
}
