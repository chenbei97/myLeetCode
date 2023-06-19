import QtQuick 2.14
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    width: 320; height: 260
    visible: true

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if (mouse.button === Qt.RightButton) //右键菜单
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


