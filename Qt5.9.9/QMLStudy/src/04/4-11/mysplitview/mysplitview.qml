import QtQuick
import QtQuick.Controls
import Qt.labs.settings

ApplicationWindow {
    width: 640; height: 480
    visible: true

    SplitView {
        id: splitView
        anchors.fill: parent; orientation: Qt.Horizontal

        Rectangle {
            implicitWidth: 200
            SplitView.maximumWidth: 400; color: "lightblue"
            Label { text: "View 1"; anchors.centerIn: parent }
        }
        Rectangle {
            id: centerItem
            SplitView.minimumWidth: 50; SplitView.fillWidth: true
            color: "lightgray"
            Label { text: "View 2"; anchors.centerIn: parent }
        }
        Rectangle {
            implicitWidth: 200; color: "lightgreen"
            Label { text: "View 3"; anchors.centerIn: parent }
        }
    }

    Component.onCompleted: splitView.restoreState(settings.splitView)
    Component.onDestruction: settings.splitView = splitView.saveState()

    Settings {
        id: settings
        property var splitView
    }
}


