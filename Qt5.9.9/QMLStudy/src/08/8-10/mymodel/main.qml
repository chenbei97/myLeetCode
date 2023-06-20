import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.5

Window {
    width: 640; height: 480
    visible: true

    ListView {
        anchors.fill: parent
        model: stringListModel
        delegate: Rectangle {
            height: 25; width: 100
            Text { text: modelData ;color: "red"}
        }
    }
}
