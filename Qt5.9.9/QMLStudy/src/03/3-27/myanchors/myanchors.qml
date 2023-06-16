import QtQuick 2.12

Rectangle {
    id: window
    width: 160; height: 200
    color: "lightgrey"

    Rectangle { id: myRect; width: 100; height: 100; color: "black" }

    states: State {
        name: "reanchored"

        AnchorChanges { // 状态的锚改变
            target: myRect
            anchors.top: window.top // 让小矩形依然锚定大矩形顶部
            anchors.bottom: window.bottom // 底部锚定大矩形底部
        }
        PropertyChanges {
            target: myRect
            anchors.topMargin: 10 // 边缘部分可以留出10距离
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
