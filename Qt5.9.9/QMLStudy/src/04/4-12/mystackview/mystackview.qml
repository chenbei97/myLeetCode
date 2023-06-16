import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 640; height: 480
    visible: true

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("Push")
                onClicked: {
                    stack.push(rect1, {"color": "red"}, rect2, {"color": "green"},
                               rect3, {"color": "yellow"});
                    console.log(stack.depth)
                }
            }
            ToolButton {
                text: qsTr("Pop")
                onClicked: { stack.pop(); console.log(stack.depth) }
            }
            ToolButton {
                text: qsTr("Replace")
                onClicked: {
                    stack.replace(rect2, [rect1, rect2, rect3]);
                    console.log(stack.depth)
                }
            }
            ToolButton {
                text: qsTr("Find")
                onClicked: {
                    stack.find(function(item, index) {
                        console.log(index); return item === rect3 })
                }
            }
            ToolButton {
                text: qsTr("Clear")
                onClicked: { stack.clear(); console.log(stack.depth)}
            }
        }
    }

    StackView {
        id: stack
        anchors.fill: parent
    }

    Rectangle { id: rect1; visible: false; Text { text: qsTr("1")} }
    Rectangle { id: rect2; visible: false; Text { text: qsTr("2")} }
    Rectangle { id: rect3; visible: false; Text { text: qsTr("3")} }
}


