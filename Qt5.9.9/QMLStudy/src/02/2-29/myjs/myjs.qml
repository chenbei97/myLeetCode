import QtQuick
import "componentCreation.js" as MyScript

Rectangle {
    id: appWindow
    width: 300; height: 300

    Component.onCompleted: MyScript.createSpriteObjects();
}


