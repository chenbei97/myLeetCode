import QtQuick 2.12

Item {
    focus: true
    Keys.onPressed: (event)=> {
        if (event.key === Qt.Key_Left) {
            console.log("move left");
            event.accepted = true;
        }
    }
    Keys.onReturnPressed: console.log("Pressed return");
}
