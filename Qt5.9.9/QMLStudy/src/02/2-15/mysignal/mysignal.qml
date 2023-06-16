import QtQuick

Rectangle {
    id: rect
    width: 400; height: 300

    MouseArea {
        anchors.fill: parent
        onClicked: {
            rect.color = Qt.rgba(Math.random(),
                                 Math.random(), Math.random(), 1);
        }
    }
}

