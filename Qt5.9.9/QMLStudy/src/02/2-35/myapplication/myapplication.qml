import QtQuick

SquareButton {
    id: squareButton

    onButtonClicked: (xPos, yPos)=> {
        console.log("Clicked", xPos, yPos)
        randomizeColor()
    }

    Text { text: squareButton.pressed ? "Down" : "Up" }
}
