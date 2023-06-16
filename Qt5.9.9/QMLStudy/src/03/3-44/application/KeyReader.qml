import QtQuick 2.12

Item {
    Item {
        focus: true
        Keys.onPressed: (event)=> {
            console.log("Loaded item captured:", event.text);
                            event.accepted = true;
           // event.accepted = false; // 这是被加载的项目设为true防止传播给Loader
        }
    }
}
