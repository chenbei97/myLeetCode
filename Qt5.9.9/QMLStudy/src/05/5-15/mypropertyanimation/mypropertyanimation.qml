import QtQuick 2.9

Item {
    width: 300; height: 300

    Rectangle {
        id: rect
        width: 100; height: 100
        color: "red"

        PropertyAnimation on x { to: 100 ;duration:5000 }
        PropertyAnimation on y { to: 100 ;duration:5000}
    }
}
