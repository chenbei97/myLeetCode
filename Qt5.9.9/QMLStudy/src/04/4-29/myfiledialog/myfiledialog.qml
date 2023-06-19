import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.3
import Qt.labs.platform 1.1


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
        folder: StandardPaths.writableLocation
                       (StandardPaths.PicturesLocation)
        acceptLabel: qsTr("选择图片")
        onAccepted: image.source = currentFile
    }
}
