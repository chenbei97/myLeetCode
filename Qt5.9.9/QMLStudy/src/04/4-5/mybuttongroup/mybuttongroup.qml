import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

Window {
    width:800; height: 200
    visible: true

    RowLayout {
        spacing: 20

        ColumnLayout {
            CheckBox { checked: true; text: qsTr("First") }
            CheckBox { text: qsTr("Second") }
            CheckBox { checked: true; text: qsTr("Third") }
        }

        ColumnLayout {
            RadioButton { checked: true; text: qsTr("First") }
            RadioButton { text: qsTr("Second") }
            RadioButton { text: qsTr("Third") }
        }

        ColumnLayout {
            ButtonGroup {
                id: childGroup
                exclusive: false; checkState: parentBox.checkState
            }

            CheckBox {
                id: parentBox;
                text: qsTr("Parent"); checkState: childGroup.checkState // 第1个checkbox的选中状态和buttongroup的选中状态绑定
            }

            CheckBox {
                checked: true; text: qsTr("Child 1")
                leftPadding: indicator.width; ButtonGroup.group: childGroup // 2个checkbox都属于buttongroup,和parentBox的左边距是指示器的跨度
            }

            CheckBox {
                text: qsTr("Child 2"); leftPadding: indicator.width
                ButtonGroup.group: childGroup
            }
        }

        ButtonGroup { id: radioGroup }

        ColumnLayout {
            id : col1
            Label { text: qsTr("组1") } // 这里还有个标签，所以不能用col1.children之类的技术，而是把按钮归类于某个button group

            RadioButton {
                checked: true; text: qsTr("选项1");
                ButtonGroup.group: radioGroup
            }

            RadioButton {
                text: qsTr("选项2"); ButtonGroup.group: radioGroup
            }
        }

        ColumnLayout {
            id : col2
            Label { text: qsTr("组2") }

            RadioButton {
                text: qsTr("选项3"); ButtonGroup.group: radioGroup // 这样虽然是2组,但是4个按钮之间是互斥的
            }

            RadioButton {
                text: qsTr("选项4"); ButtonGroup.group: radioGroup
            }
        }
    }
}
















