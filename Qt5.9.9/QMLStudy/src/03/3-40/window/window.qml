import QtQuick 2.12

Rectangle {
    id: window
    color: "white"; width: 240; height: 150

    Column {
        anchors.centerIn: parent; spacing: 15

        MyWidget {
            id:w1
            color: "lightblue"
            Component.onCompleted: console.log("1")
        }
        MyWidget {
            id:w2
            focus: true
            color: "palegreen"
            Component.onCompleted: console.log("2")
        }
        MyWidget {
            id:w3
            color: "red"
            Component.onCompleted: console.log("3")
        }
    }
}

