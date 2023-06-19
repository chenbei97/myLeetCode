import QtQuick 2.12

Rectangle {
    id: window
    width: 300; height: 300
    color: "lightgrey"

    Rectangle { id: myRect; width: 100; height: 100; color: "black" }

    states: State {
        name: "reanchored"

        AnchorChanges { //运行时修改项目的锚.必须在State内使用
            target: myRect
            anchors.top: window.top // 让myRect顶部和window顶部保持对齐
            anchors.bottom: window.bottom // 以及底部也要对齐
            anchors.horizontalCenter: window.horizontalCenter // 让myRect到中央位置
        }
        PropertyChanges { // AnchorChanges不能修改项目边距，这里可以定义
            target: myRect
            anchors.topMargin: 10 // 锚定时myRect和window之间的锚线留出距离10
            anchors.bottomMargin: 10
        }
    }

    transitions: Transition {
        AnchorAnimation { duration: 1000 }
    }

    MouseArea {
        anchors.fill: parent;
        onClicked: window.state = "reanchored" // 点击大矩形区域切换状态
    }
}
