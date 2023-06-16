import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 800; height: 250
    visible: true

    RowLayout {
        x: 50; y: 50; spacing: 20

        Pane {
            contentWidth: 150; contentHeight: 80

            ColumnLayout {
                   anchors.fill: parent
                   CheckBox { text: qsTr("E-mail") }
                   CheckBox { text: qsTr("Calendar") }
                   CheckBox { text: qsTr("Contacts") }
               }
         }

        Frame {
            contentWidth: 150; contentHeight: 80

            ColumnLayout {
                   anchors.fill: parent; anchors.leftMargin: 5
                   CheckBox { text: qsTr("E-mail") }
                   CheckBox { text: qsTr("Calendar") }
                   CheckBox { text: qsTr("Contacts") }
               }
        }

        GroupBox {
            contentWidth: 150; contentHeight: 80
            title: qsTr("Synchronize")

            ColumnLayout {
                anchors.fill: parent
                CheckBox { text: qsTr("E-mail") }
                CheckBox { text: qsTr("Calendar") }
                CheckBox { text: qsTr("Contacts") }
            }
        }


        GroupBox {
            contentWidth: 150; contentHeight: 80

            label: CheckBox {
                id: checkBox
                checked: true;
                text: qsTr("Synchronize")
            }

            ColumnLayout {
                anchors.fill: parent; anchors.topMargin: 10
                enabled: checkBox.checked
                CheckBox { text: qsTr("E-mail") }
                CheckBox { text: qsTr("Calendar") }
                CheckBox { text: qsTr("Contacts") }
            }
        }
    }
}


