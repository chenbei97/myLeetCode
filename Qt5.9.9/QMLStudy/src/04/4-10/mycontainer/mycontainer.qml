import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    width: 400; height: 250
    visible: true

    header: ToolBar{
        RowLayout {
            ToolButton {
                text: qsTr("Home")
                onClicked: swipeView.setCurrentIndex(0)
                enabled: swipeView.currentIndex !== 0
            }

            ToolButton {
                text: qsTr("<")
                onClicked: swipeView.decrementCurrentIndex()
                enabled: swipeView.currentIndex > 0
            }

            ToolButton {
                text: qsTr(">")
                onClicked: swipeView.incrementCurrentIndex()
                enabled: swipeView.currentIndex < swipeView.count - 1
            }
        }
    }

    SwipeView {
        id: swipeView
        currentIndex: tabBar.currentIndex
        implicitWidth: parent.width; height: 100
        background: Rectangle { color: "lightblue" }

        Repeater {
            model: 5
            Loader {
                active: SwipeView.isCurrentItem || SwipeView.isNextItem || SwipeView.isPreviousItem
                sourceComponent: Text {
                    text: qsTr("页面") + (index + 1)
                    Component.onCompleted: console.log("created:" + index)
                    Component.onDestruction: console.log("destroyed:", index)
                }
            }
        }
    }

    TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        width: parent.width; anchors.top: swipeView.bottom

        Repeater {
            model: ["First", "Second", "Third", "Fourth", "Fifth"]

            TabButton {
                text: modelData
                width: Math.max(100, tabBar.width / 5)
            }
        }
    }

    Row {
        width: parent.width
        anchors.top: tabBar.bottom; anchors.topMargin: 30

        TabBar {
            id: tabBar1
            currentIndex: 0
            width: parent.width - addButton.width

            TabButton { text: "TabButton" }
        }

        Component {
            id: tabButton
            TabButton { text: "TabButton" }
        }

        Button {
            id: addButton
            text: "+"
            flat: true
            onClicked: {
                tabBar1.addItem(tabButton.createObject(tabBar1))
                console.log("added:", tabBar1.itemAt(tabBar1.count - 1))
            }
        }
    }
}






