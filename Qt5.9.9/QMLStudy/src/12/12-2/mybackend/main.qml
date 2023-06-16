import QtQuick
import QtQuick.Controls
import io.qt.examples.backend

ApplicationWindow {
    id: root
    width: 300
    height: 480
    visible: true

    BackEnd {
        id: backend
        onUserNameChanged: console.log(backend.userName)
    }

    Column {
        spacing: 10
        anchors.centerIn: parent

        TextField {
            placeholderText: qsTr("User name")
            onTextChanged: backend.userName = text
        }

        Label {
            text: backend.userName
            width: 200; font.pointSize: 20
            background: Rectangle {
                color: "lightgrey"
            }
        }
    }
}
