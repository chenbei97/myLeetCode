import QtQuick 2.12

Item {
    width: 200; height: 200

    Loader {
        anchors.fill: parent // 和Item一样大小
        //anchors.centerIn: parent // 原本的Component大小
        sourceComponent: rect
    }

    Component {
        id: rect
        Rectangle {
            width: 50; height: 50
            color: "red"
        }
    }
}
