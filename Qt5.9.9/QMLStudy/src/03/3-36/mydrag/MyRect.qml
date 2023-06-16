import QtQuick 2.12

Rectangle {
    id: rect
    width: 20; height: 20

    Drag.active: dragArea.drag.active // 鼠标区域就是全部矩形区域
    Drag.hotSpot.x: 10
    Drag.hotSpot.y: 10
    Drag.source: rect
    MouseArea {
        id: dragArea
        anchors.fill: parent
        drag.target: parent // 可以拖动
    }
}

