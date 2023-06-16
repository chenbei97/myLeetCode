import QtQuick

Rectangle {
    id: coloredrectangle
    property alias color: bluerectangle.color
    width: 400; height: 300

    Rectangle {
        id: bluerectangle
        color: "#1234ff"
        width: 100; height: 100
    }

    Component.onCompleted: {
        console.log(coloredrectangle.color) // #1234ff
        setInternalColor()
        console.log(coloredrectangle.color) // #111100
        coloredrectangle.color = "#884646"
        console.log(coloredrectangle.color) // #884646
    }

    // 内部函数访问内部属性
    function setInternalColor() {
        color = "#111100"
    }
}


