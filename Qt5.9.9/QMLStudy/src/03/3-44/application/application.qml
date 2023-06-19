import QtQuick 2.12

Rectangle {
    width: 200; height: 200

    Loader {
        id: loader
        focus: true // 是一个焦点作用域，如果希望子项目都可以获得焦点，这里必须设置true
    }

    MouseArea {
        anchors.fill: parent
        onClicked: loader.source = "KeyReader.qml"
    }

    Keys.onPressed: (event)=> {
        console.log("Captured:", event.text); //KeyReader会接收键盘事件，但不会传播到矩形
    }
}
