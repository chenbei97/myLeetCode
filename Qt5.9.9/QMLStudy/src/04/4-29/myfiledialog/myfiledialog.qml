import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import QtCore

ApplicationWindow {
    width: 640; height: 480
    visible: true

    header: ToolBar {
        Button {
            text: qsTr("Choose Image...")
            onClicked: fileDialog.open()
        }
    }

    Image {
        id: image
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    FileDialog {
        id: fileDialog
        nameFilters: ["Image files (*.png *.jpg)"]
        currentFolder: StandardPaths.writableLocation
                       (StandardPaths.PicturesLocation)
        acceptLabel: qsTr("选择图片")
        onAccepted: image.source = selectedFile
    }
}
