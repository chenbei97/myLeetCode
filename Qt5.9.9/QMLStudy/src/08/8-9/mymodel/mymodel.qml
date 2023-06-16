import QtQuick

Item {
    width: 200; height: 250

//    ListModel {
//        id: myModel
//        ListElement { type: "Dog"; age: 8; noise: "meow" }
//        ListElement { type: "Cat"; age: 5; noise: "woof" }
//    }

//    component MyDelegate : Text {
//        required property string type
//        required property int age
//        text: type + ", " + age
//    }

//    ListView {
//        anchors.fill: parent
//        model: myModel
//        delegate: MyDelegate {}
//    }


    ListView {
        anchors.fill: parent

        model: ListModel {
            ListElement { color: "red" ; text: "red" }
            ListElement { color: "green"; text: "green" }
        }

        delegate: Text {
            required color
            required text
        }
    }
}

