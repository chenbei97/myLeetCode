import QtQuick 2.12

Item {
    width: 100; height: 100

    Loader {
       id: myLoader
       source: "MyItem.qml"
    }

    Connections {
        target: myLoader.item
        function onMessage(msg) { console.log(msg) }
    }
}

