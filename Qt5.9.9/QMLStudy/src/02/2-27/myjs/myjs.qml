import QtQuick
import "factorial.js" as MathFunctions

Item {
    width: 400; height: 300
    MouseArea {
        anchors.fill: parent
        onClicked: console.log(MathFunctions.factorial(10))
    }
}



