import QtQuick

Rectangle {
    property color previousColor
    property color nextColor
    onNextColorChanged:
        console.log("The next color will be: " + nextColor.toString())
    nextColor: "red"
    width: 400; height: 300; color: nextColor
    MouseArea {
        anchors.fill: parent
        onClicked: nextColor = "yellow"
    }
}

