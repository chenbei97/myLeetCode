import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

Window {
    width: 200; height: 240
    visible: true
    title: qsTr("SwipeDelegate")

    ListView {
        id: listView
        anchors.fill: parent
        model: listModel
        delegate: myDelegate

        ListModel {
            id: listModel
            ListElement { title: "Qt Quick Guidelines" }
            ListElement { title: "Pixmap and Threaded Image Support" }
            ListElement { title: "the C++ API provided by the Qt Quick module" }
            ListElement { title: "a list of QML types provided by the QtQuick import" }
            ListElement { title: "provides a particle system for Qt Quick" }
        }

        Component{
            id: myDelegate

            SwipeDelegate {
                id: swipeDelegate
                text: index + " - " + title
                width: listView.width

                ListView.onRemove: animation.start()

                SequentialAnimation {
                    id: animation
                    PropertyAction {
                        target: swipeDelegate
                        property: "ListView.delayRemove"// 延时删除
                        value: true
                    }
                    NumberAnimation {
                        target: swipeDelegate
                        property: "height"
                        to: 0 ; duration: 500
                        easing.type: Easing.InOutQuad
                    }
                    PropertyAction {
                        target: swipeDelegate
                        property: "ListView.delayRemove" // 延时删除作为动画对象
                        value: false
                    }
                }

                swipe.right: Label { // 这里swipe右边定义的文本用于删除
                    id: deleteLabel
                    text: qsTr("Delete")
                    color: "white"; padding: 12
                    verticalAlignment: Label.AlignVCenter
                    height: parent.height
                    anchors.right: parent.right

                    SwipeDelegate.onClicked: listView.model.remove(index) // 删除对象

                    background: Rectangle {
                        color: deleteLabel.SwipeDelegate.pressed ?
                                   Qt.darker("tomato", 1.1) : "tomato"
                    }
                }
            }
        }
    }
}
