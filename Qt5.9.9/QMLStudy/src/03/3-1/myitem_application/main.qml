import QtQuick 2.0

Item {
    width: 300; height: 300
    Rectangle {
        color: "lightgrey"
        width: 100; height: 100
        Rectangle {
            color: "black"
            x: 50; y: 50; width: 100; height: 100
            opacity: 0.5
        }
    }
}
