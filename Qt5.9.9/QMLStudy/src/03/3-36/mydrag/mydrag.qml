import QtQuick 2.12

Item {
    width: 400; height: 150

    DropArea { // 拖动区域是矩形可以把MyRect拖进来
        x: 175; y: 75
        width: 50; height: 50
        Rectangle {
            id: area; anchors.fill: parent
            border.color: "black"
        }
        onEntered: {
            area.color = drag.source.color // 拖入事件会调用的函数.这里让大矩形和拖动源颜色相同
        }
        onExited: {
            area.color = "white"
            //console.log(drag.x)
        }
    }

    MyRect{id:blue;color: "blue"; x:110 }
    MyRect{color: "red"; x:140 }
    MyRect{color: "yellow"; x:170 }
    MyRect{color: "black"; x:200 }
    MyRect{color: "steelblue"; x:230 }
    MyRect{color: "green"; x:260 }
}
