import QtQuick

Rectangle {
    property alias buttonText: textItem.text
    width: 100; height: 30; color: "yellow"
    Text { id: textItem }
}

