import QtQuick 2.12

Rectangle {
    width: 200; height: 200

    Loader {
        id: loader
        focus: true // 是个焦点作用域必须设置焦点
    }

    MouseArea {
        anchors.fill: parent
        onClicked: loader.source = "KeyReader.qml"
    }

    Keys.onPressed: (event)=> {
        console.log("Captured:", event.text); //不会传播到矩形
    }
}
