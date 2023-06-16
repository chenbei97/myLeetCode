import QtQuick

Item {
    property string title
    height: 100

    TitleText {
        size: 22
        anchors.top: parent.top
    }

    TitleText {
        size: 18
        anchors.bottom: parent.bottom
    }
}
