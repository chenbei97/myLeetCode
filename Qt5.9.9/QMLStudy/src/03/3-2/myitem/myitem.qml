import QtQuick 2.0

//Item {
//    Rectangle {
//        color: "red"
//        width: 100; height: 100
//    }
//    Rectangle {
//        color: "blue"
//        x: 50; y: 50; width: 100; height: 100
//    }
//}

//Item {
//    Rectangle {
//        z: 1
//        color: "red"
//        width: 100; height: 100
//    }
//    Rectangle {
//        color: "blue"
//        x: 50; y: 50; width: 100; height: 100
//    }
//}

//Item {
//    Rectangle {
//        color: "red"
//        width: 100; height: 100
//        Rectangle {
//            color: "blue"
//            x: 50; y: 50; width: 100; height: 100
//        }
//    }
//}

Item {
    width: 400;height: 400
    Rectangle {
        color: "red"
        width: 100; height: 100
        x:100; y:100
        Rectangle {
            id:rect1
            z: -1
            color: "blue"
            x: 50; y: 50; width: 100; height: 100

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("mapFromItem: ",mapFromItem(rect1,20,20));
                    console.log("mapToItem: ",mapToItem(rect1,20,20));
                }
            }
        }
    }
}
