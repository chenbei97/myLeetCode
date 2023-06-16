import QtQuick

Window {
    width: 640; height: 480
    visible: true

    ListView {
        anchors.fill: parent
        model: stringListModel
        delegate: Rectangle {
            height: 25; width: 100
            Text { text: modelData }
        }
    }
}
