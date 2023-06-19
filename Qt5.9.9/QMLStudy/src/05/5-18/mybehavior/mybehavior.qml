import QtQuick

Item {
    width: 800; height: 800

    Ball { id: ball }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            ball.color = Qt.rgba(Math.random(256),
                                 Math.random(256), Math.random(256), 1)
            ball.x += 100
            ball.y += 50
        }
    }
}

