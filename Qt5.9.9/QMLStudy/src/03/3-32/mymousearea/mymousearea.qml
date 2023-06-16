import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

Rectangle {
    color: "yellow"
    width: 100; height: 100

    MouseArea {
        anchors.fill: parent
        onClicked: console.log("clicked yellow")
        onDoubleClicked: console.log("double clicked yellow")
    }

    Rectangle {
        color: "blue"
        width: 50; height: 50

        MouseArea {
            anchors.fill: parent
            propagateComposedEvents: true // 这样2个点击事件同时有效
            onClicked: (mouse)=> {
                console.log("clicked blue")
                mouse.accepted = false // 让点击事件继续传播
            }
            onDoubleClicked: (mouse)=> {
                console.log("double clicked blue")
                mouse.accepted = false // 具体可见MouseEvent类型
            }
        }
    }
}
