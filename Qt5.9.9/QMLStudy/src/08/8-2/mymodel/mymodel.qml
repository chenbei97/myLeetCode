import QtQuick 2.0

Item {
    width: 200; height: 250
    Component {
        id: itemDelegate
        Text { text: "I am item number: " + index
            color: view.isCurrentItem ? "black":"red"
        }
    }
    ListView {
        id:view
        anchors.fill: parent
        model: 5
        delegate: itemDelegate
    }
}
