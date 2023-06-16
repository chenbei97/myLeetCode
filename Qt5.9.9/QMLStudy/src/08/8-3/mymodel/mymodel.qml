import QtQuick 2.0

Item {
    width: 400; height: 250

    ListModel {
        id: fruitModel

        ListElement {
            name: "Apple"; cost: 2.45
            attributes: [
                ListElement { description: "Core" },
                ListElement { description: "Deciduous" }
            ]
        }
        ListElement {
            name: "Orange"; cost: 3.25
            attributes: [
                ListElement { description: "Citrus" }
            ]
        }
        ListElement {
            name: "Banana"; cost: 1.95
            attributes: [
                ListElement { description: "Tropical" },
                ListElement { description: "Seedless" }
            ]
        }
    }

    Component {
        id: fruitDelegate

        Item {
            width: 200; height: 50

            Text { id: nameField; text: name }
            Text { text: '$' + cost; anchors.left: nameField.right } // 一左一右依次是姓名和花费
            Row { // 紧接着其实又是一行文本，包括2部分：Attributes:和重复的内容
                anchors.top: nameField.bottom; spacing: 5
                Text { text: "Attributes:" }
                Repeater {
                    model: attributes // 提供数据的是attributes
                    Text { text: description } // 要重复的是描述，但重复的是当前nameField对应的描述，其实就是attributes.description
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: fruitModel.setProperty(index, "cost", cost * 2) // index获取被单机的数据项索引
            }
        }
    }

    ListView {
        anchors.fill: parent
        model: fruitModel; delegate: fruitDelegate
    }
}

