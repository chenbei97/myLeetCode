import QtQuick 2.9

Flickable {
    width: 150; height: 150
    contentWidth: 300; contentHeight: 300

    rebound: Transition { // 当捕捉回可弹内容的边界时应用于内容视图的转换
        NumberAnimation {
            properties: "x,y"
            duration: 1000
            easing.type: Easing.OutBounce
        }
    }

    Rectangle {
        width: 300; height: 300
        color: "steelblue"
    }

    flickableDirection: Flickable.HorizontalFlick // 水平反转
}


