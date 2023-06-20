import QtQuick 2.9

Flipable {
    id: flipable
    width: 240
    height: 240

    property bool flipped: false
// 2种状态
    front: Image { source: "front.png"; anchors.centerIn: parent }
    back: Image { source: "back.png"; anchors.centerIn: parent }

    transform: Rotation {
        id: rotation
        origin.x: flipable.width/2 // 中心反转 y轴
        origin.y: flipable.height/2
        axis.x: 0; axis.y: 1; axis.z: 0
        angle: 0
    }

    states: State {
        name: "back"
        PropertyChanges { target: rotation; angle: 180 }
        when: flipable.flipped // 状态back,当属性反转时动作
    }

    transitions: Transition { // 反转有个过度效果
        NumberAnimation { target: rotation; property: "angle"; duration: 4000 }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: flipable.flipped = !flipable.flipped // 点击时反转
    }
}
