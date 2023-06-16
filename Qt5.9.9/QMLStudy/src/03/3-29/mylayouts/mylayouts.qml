import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

Window {
    width: 640; height: 480
    visible: true

    StackLayout {
        id: layout
        anchors.fill: parent
        currentIndex: 1
        Rectangle {
            color: 'teal'
            implicitWidth: 200; implicitHeight: 200
        }
        Rectangle {
            color: 'plum'
            implicitWidth: 300; implicitHeight: 200
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (layout.currentIndex === 1)
                layout.currentIndex = 0;
            else
                layout.currentIndex = 1
        }
    }
}


