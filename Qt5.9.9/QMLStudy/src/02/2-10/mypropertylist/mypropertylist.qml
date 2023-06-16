import QtQuick

Rectangle {
    // 只声明，不初始化
    property list<Rectangle> siblingRects

    // 声明并且初始化
    property list<Rectangle> childRects: [
        Rectangle { color: "red" },
        Rectangle { color: "blue"}
    ]

    width: 400; height: 300; color: childRects[1].color

    MouseArea {
        anchors.fill:parent
        onClicked: {
            for (var i = 0; i < childRects.length; i++)
                console.log("color", i, childRects[i].color)
        }
    }
}



