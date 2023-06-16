import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Display {
        title: "hello"
        Person {id:person; title: "Qt"}

        Component.onCompleted:  console.log
                                (person.fullName()+getTitle())  /*qml: Qt  hello*/
        // person.fullName() 使用person自己的作用域也就是Qt
        // getTitle()调用的是Display的已经赋值了hello
    }

    Column {
        spacing: 2
        Rectangle {color:"red"; width: 50;height: 50}
        Rectangle {color:"green"; width: 50;height: 50; id:greenRect}
        Rectangle {color:"blue"; width: 50;height: 50}

        move: Transition {
            NumberAnimation {duration:1000;properties: "x,y"; to:100}
        }
        focus: true
        Keys.onSpacePressed: {greenRect.visible = !greenRect.visible;
            greenRect.x = greenRect.visible?50:100;
        }

    }

    Grid {
        padding: 5
        spacing: 10
        y: 150
        Repeater {
            model:16
            Rectangle {
                id: rect
                width: 40; height: 40
                border.width: 1
                color: Positioner.isFirstItem? "yellow": "skyblue"
                Text {
                    text: rect.Positioner.index;
                    anchors.centerIn: parent
                }
            }
        }
    }

    Item {
        focus: true
        Keys.onPressed: {
            if (event.key === Qt.Key_Left) {
                console.log("move left");
                event.accepted = true;
            }
        }
        Keys.onReturnPressed: console.log("Pressed return");
//        Image {
//            source: "tile.png"
//        }
        Image {
            x: 80
            width: 100
            height: 100
            source: "tile.png"
        }
        Image {
            x: 190
            width: 100
            height: 100
            fillMode: Image.Tile
            source: "tile.png"
        }
    }
}
