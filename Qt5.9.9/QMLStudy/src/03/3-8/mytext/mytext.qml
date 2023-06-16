import QtQuick

//Column {
//    FontLoader {
//        id: webFont
//        source: "https://qter-images.qter.org/other/myfont.ttf"
//    }

//    Text {
//        text: webFont.status === FontLoader.Ready ? 'Loaded' : 'Not loaded'
//        font.family: webFont.name
//        font.pointSize: 12
//    }
//}

Rectangle {
    width: 200; height: 200; color: "lightgrey"

    Text {
        width: 200; height: 200
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: qsTr("中心")
        font.pointSize: 20
    }
}




