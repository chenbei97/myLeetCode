import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Window 2.0

Window {
    width: 600; height: 800
    visible: true

    Rectangle {
        x:100; y:100
        width: 200; height: 180
        color:"red"

        Control {

            width: 150; height: 120

            topInset: -2 // 背景区域大于超过内容项目
            leftInset: -2
            rightInset: -6
            bottomInset: -6

            background: Rectangle { // 背景项目
                color: "green"
            }
            contentItem: Rectangle { // 内容项目
                color: "yellow"
            }
            topPadding: 5; leftPadding: 2
        }

//        Button {
//            icon: "document-open.png"
//        }
    }
}
