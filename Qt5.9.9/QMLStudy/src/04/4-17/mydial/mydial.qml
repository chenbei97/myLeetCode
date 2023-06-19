import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

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

