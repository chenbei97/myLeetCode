import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 320; height: 260
    visible: true

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if (mouse.button === Qt.RightButton)
                contextMenu.popup()
        }

        Menu {
            id: contextMenu
            MenuItem { text: qsTr("Cut") }
            MenuItem { text: qsTr("Copy") }
            MenuItem { text: qsTr("Paste") }
        }
    }

    //    Button {
    //        id: fileButton
    //        text: "File"
    //        onClicked: menu.open()

    //        Menu {
    //            id: menu
    //            y: fileButton.height

    //            MenuItem { text: qsTr("New...") }
    //            MenuItem { text: qsTr("Open...") }
    //            MenuItem { text: qsTr("Save") }
    //        }
    //    }
}


