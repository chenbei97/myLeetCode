import QtQuick

ListView {
    width: 400; height: 400; model: 1
    delegate: myItem.mycomponent

    MyItem { id: myItem }
}


