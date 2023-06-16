// myapplication.qml
import QtQuick

Rectangle {
    width: 400; height: 300

    SquareButton {
        anchors.centerIn: parent
        onDeactivated: console.log("Deactivated!")
        onActivated: (xPosition, yPosition)
                     => console.log("Activated at " + xPosition + "," + yPosition)
    }
}

