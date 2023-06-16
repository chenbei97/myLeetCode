import QtQuick 2.12

FocusScope {
    id: scope
    property alias color: rectangle.color
    x: rectangle.x; y: rectangle.y
    width: rectangle.width; height: rectangle.height

    Rectangle {
        id: rectangle
        anchors.centerIn: parent
        color: "lightsteelblue"; width: 175; height: 25;
        radius: 10; antialiasing: true
        Text { id: label; anchors.centerIn: parent }
        focus: true
        Keys.onPressed: (event)=> {
            if (event.key === Qt.Key_A)
                label.text = 'Key A was pressed'
            else if (event.key === Qt.Key_B)
                label.text = 'Key B was pressed'
            else if (event.key === Qt.Key_C)
                label.text = 'Key C was pressed'
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: (mouse) =>{ scope.focus = true // 点击组件时获取焦点其他自动失去焦点
                    //mouse.accepted = true;
        }
    }
}
