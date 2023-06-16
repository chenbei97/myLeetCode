import QtQuick
import QtQuick.Controls

Window {
    width: 300; height: 200
    visible: true

    Rectangle {
        x:100; y:100
        width: 50; height: 40
        color:"red"

        Control {
            width: 40; height: 30

            topInset: -2
            leftInset: -2
            rightInset: -6
            bottomInset: -6

            background: Rectangle {
                color: "green"
            }
            contentItem: Rectangle {
                color: "yellow"
            }
            topPadding: 5; leftPadding: 2
        }
    }
}
