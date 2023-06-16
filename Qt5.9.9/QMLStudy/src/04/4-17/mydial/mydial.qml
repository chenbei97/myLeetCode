import QtQuick
import QtQuick.Controls

Window {
    width: 640; height: 480
    visible: true

    Dial {
        id: dial
        from: 1; to: 10
        stepSize: 1; wrap: true
    }

    Label {
        anchors.top: dial.bottom
        text: dial.value
    }
}

