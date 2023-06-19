import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

Window {
    width: 500
    height: 250
    visible: true
//Rectangle {
//    Row {
//        TabBar {
//            id: tabBar

//            currentIndex: 0
//            width: parent.width - addButton.width

//            TabButton { text: "TabButton" }
//        }

//        Component {
//            id: tabButton // 可以调用.createObject(tabBar)
//            TabButton { text: "TabButton" }
//        }

//        Button {
//            id: addButton
//            text: "+"
//            flat: true
//            onClicked: {
//                tabBar.addItem(tabButton.createObject(tabBar)) // 点击+动态添加对象
//                console.log("added:", tabBar.itemAt(tabBar.count - 1))
//            }
//        }
//    }
//}

    ScrollView {
        x: 10; y: 10
        width: 200; height: 200
        Label { text: "ABC"; font.pixelSize: 224 }
    }

    ScrollView {
        x: 240; y: 10
        width: 200; height: 200

        ListView {
            model: 20
            delegate: ItemDelegate {
                text: "Item " + index
            }
        }
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
    }
}


