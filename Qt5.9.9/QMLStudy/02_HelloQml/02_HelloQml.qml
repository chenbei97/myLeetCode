import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        property list<Rectangle> childRects: [
            Rectangle {color:"red"},
            Rectangle {color:"skyblue"}
        ]
        width: 400;height: 300; color: childRects[1].color
    }

    MyText {
        id: cc
        anchors.centerIn: parent
        MouseArea {
            anchors.fill: parent
            onClicked: console.log("text's color = ",parent.color)
        }
    }

    Text {
        id: name2
        text: qsTr("123456")
//        anchors.centerIn: cc
        anchors.top: cc.bottom
        anchors.horizontalCenter: cc.horizontalCenter
        Keys.onUpPressed:  font.pixelSize+=10
        Keys.onDownPressed:  font.pixelSize-=10
        focus: true


    }

}
