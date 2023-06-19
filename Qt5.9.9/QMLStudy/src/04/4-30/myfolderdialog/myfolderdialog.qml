import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.1

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
            Label { id: label; text: folderDialog.currentFolder}
        }
    }

    FolderDialog {
        id: folderDialog
        currentFolder: StandardPaths.standardLocations
                       (StandardPaths.DocumentsLocation)[0]
    }
}
