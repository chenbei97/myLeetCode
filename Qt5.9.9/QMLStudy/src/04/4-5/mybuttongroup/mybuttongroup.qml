import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 400; height: 200
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
                text: qsTr("Parent"); checkState: childGroup.checkState
            }

            CheckBox {
                checked: true; text: qsTr("Child 1")
                leftPadding: indicator.width; ButtonGroup.group: childGroup
            }

            CheckBox {
                text: qsTr("Child 2"); leftPadding: indicator.width
                ButtonGroup.group: childGroup
            }
        }

        ButtonGroup { id: radioGroup }

        ColumnLayout {
            Label { text: qsTr("组1") }

            RadioButton {
                checked: true; text: qsTr("选项1");
                ButtonGroup.group: radioGroup
            }

            RadioButton {
                text: qsTr("选项2"); ButtonGroup.group: radioGroup
            }
        }

        ColumnLayout {
            Label { text: qsTr("组2") }

            RadioButton {
                text: qsTr("选项3"); ButtonGroup.group: radioGroup
            }

            RadioButton {
                text: qsTr("选项4"); ButtonGroup.group: radioGroup
            }
        }
    }
}
















