import QtQuick 2.0

Rectangle {
    property int frames
    width: animation.width; height: animation.height + 8

    AnimatedImage { id: animation; source: "animation.gif"}

    Component.onCompleted: {
        frames = animation.frameCount
    }

    Rectangle {
        width: 4; height: 8
        x: (animation.width - width) * animation.currentFrame / frames
        y: animation.height // 实现小矩形移动的效果,随着帧的移动最终x移动到animation.width - width位置
        color: "red" // 这个位置就是动图的宽度减去自身小矩形的宽度
        onXChanged: console.log(x);
    }
}


