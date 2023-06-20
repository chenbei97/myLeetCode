import QtQuick 2.9

Image {
    id: fengche
    width: 300; height: 300
    source: "fengche.png"
    opacity: 0.1

    MouseArea { // 点击就开始
        anchors.fill: parent
        onClicked: {
            animateRotation.start()
            animateOpacity.start()
        }
    }

    PropertyAnimation { // 控制图片的透明度,属于属性
        id: animateOpacity
        target: fengche; properties: "opacity"
        to: 1.0; duration: 2000
    }

    NumberAnimation {// 控制图片旋转的角度 一直循环
        id: animateRotation
        target: fengche; properties: "rotation"
        from: 0; to: 360; duration: 3000
        loops: Animation.Infinite
        easing {type: Easing.OutBack}
    }
}

