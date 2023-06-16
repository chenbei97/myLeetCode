import QtQuick 2.12

Item {
    width: 500; height: 150

    Rectangle{
        id: rect1; x:10; y:20
        width: 100; height: 100; color: "lightgrey"

        Text { text: "rect1"; anchors.centerIn: parent }
    }
    Rectangle{
        id: rect2
        width: 100; height: 100; color: "black"
//        anchors.left: rect1.right
//        anchors.left: rect1.right; anchors.top: rect1.bottom;

        anchors.left: rect1.right; anchors.right: rect3.left; anchors.top: rect1.top

        Text { text: "rect2"; color: "white"; anchors.centerIn: parent }
    }

    Rectangle{
        id: rect3; x:300; y:20
        width: 100; height: 100; color: "lightgrey"

        Text { text: "rect3"; anchors.centerIn: parent }
    }
}
