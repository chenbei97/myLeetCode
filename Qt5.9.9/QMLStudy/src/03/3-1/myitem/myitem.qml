import QtQuick 2.0
//Item {
//    Rectangle {
//        color: "lightgrey"
//        width: 100; height: 100
//        Rectangle {
//            color: "black"
//            x: 50; y: 50; width: 100; height: 100
//        }
//    }
//}

Item {
    Rectangle {
        z:10
        opacity: 0.5
        color: "red"
        width: 100; height: 100
        Rectangle {
            color: "blue"
            x: 50; y: 50; width: 100; height: 100
            z:-1 // 子项目的话需要用负值
            MouseArea {
                anchors.fill: parent
                onClicked: console.log("childAt(50,50) = ",childAt(50,50))
            }
        }
    }
}
