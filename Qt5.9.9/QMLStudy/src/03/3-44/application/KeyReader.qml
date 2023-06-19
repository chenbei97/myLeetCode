import QtQuick 2.12

Item {
    Item {
        focus: true
        Keys.onPressed: (event)=> {
            console.log("Loaded item captured:", event.text);
                            event.accepted = true; //  //KeyReader会接收键盘事件，但不会传播到矩形
        }
    }
}
