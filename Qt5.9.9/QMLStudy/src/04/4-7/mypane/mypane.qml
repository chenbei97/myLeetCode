import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

Window {
    width: 900; height: 300
    visible: true

    RowLayout {
        x: 50; y: 50; spacing: 20

        Pane { // 窗格控件，只有一个列布局放了3个checkbox
            contentWidth: 150; contentHeight: 80

            ColumnLayout {
                   anchors.fill: parent
                   CheckBox { text: qsTr("E-mail") }
                   CheckBox { text: qsTr("Calendar") }
                   CheckBox { text: qsTr("Contacts") }
               }
         }

        Frame { // 带有边框的Pane
            contentWidth: 150; contentHeight: 80 // 高度80正好只框2个checkbox，150就都框进去了

            ColumnLayout {
                   anchors.fill: parent; anchors.leftMargin: 5 // 让3个checkbox和边框有些距离
                   CheckBox { text: qsTr("E-mail") }
                   CheckBox { text: qsTr("Calendar") }
                   CheckBox { text: qsTr("Contacts") }
               }
        }

        GroupBox { // 分组 带有标题的Frame
            contentWidth: 150; contentHeight:80 // 这个高度也是控制边框的高度，因为GroupBox继承Frame
             title: qsTr("Synchronize")

            ColumnLayout {
                anchors.fill: parent
                CheckBox { text: qsTr("E-mail") }
                CheckBox { text: qsTr("Calendar") }
                CheckBox { text: qsTr("Contacts") }
            }
        }


        GroupBox {
            contentWidth: 150; contentHeight: 90

            label: CheckBox { // label的附加属性
                id: checkBox
                checked: true;
                text: qsTr("Synchronize1")
            }

            ColumnLayout {
                anchors.fill: parent; anchors.topMargin: 10
                enabled: checkBox.checked // 金庸取决于label是否选中 没选中就禁用
                CheckBox { text: qsTr("E-mail") }
                CheckBox { text: qsTr("Calendar") }
                CheckBox { text: qsTr("Contacts") }
            }
        }
    }
}
