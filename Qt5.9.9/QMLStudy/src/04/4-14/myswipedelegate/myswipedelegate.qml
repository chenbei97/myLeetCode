import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

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
                        property: "ListView.delayRemove"
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
                        property: "ListView.delayRemove"
                        value: false
                    }
                }

                swipe.right: Label {
                    id: deleteLabel
                    text: qsTr("Delete")
                    color: "white"; padding: 12
                    verticalAlignment: Label.AlignVCenter
                    height: parent.height
                    anchors.right: parent.right

                    SwipeDelegate.onClicked: listView.model.remove(index)

                    background: Rectangle {
                        color: deleteLabel.SwipeDelegate.pressed ?
                                   Qt.darker("tomato", 1.1) : "tomato"
                    }
                }
            }
        }
    }
}
