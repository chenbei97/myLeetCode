import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 500
    height: 250
    visible: true

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
                required property int index
            }
        }
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn
    }
}


