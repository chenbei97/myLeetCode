import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

Window {
    width: 640; height: 480
    visible: true

    Row {
        ListView {
            width: 160; height: 240
            focus: true
            model: Qt.fontFamilies()

            delegate: ItemDelegate {
                text: modelData
                highlighted: ListView.isCurrentItem
                onClicked: console.log("clicked:", modelData)
            }

            ScrollIndicator.vertical: ScrollIndicator { }
        }

        ListView {
            width: 140; height: 240
            model: ["Option 1", "Option 2", "Option 3"]
            delegate: CheckDelegate {
                text: modelData
            }
        }

        ButtonGroup {
            id: buttonGroup
        }

        ListView {
            width: 140; height: 240
            model: ["Option 1", "Option 2", "Option 3"]
            delegate: RadioDelegate {
                text: modelData
                checked: index === 0
                ButtonGroup.group: buttonGroup
            }
        }

        ListView {
            width: 140; height: 240
            model: ["Option 1", "Option 2", "Option 3"]
            delegate: SwitchDelegate {
                text: modelData
            }
        }
    }
}



