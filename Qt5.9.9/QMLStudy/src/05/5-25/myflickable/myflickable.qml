import QtQuick
import QtQuick.Controls

Rectangle {
    width: 300; height: 300

    Flickable {
        id: flickable
        width: 300; height: 300
        contentWidth: image.width; contentHeight: image.height
        clip: true

        Image { id: image; source: "bigImage.jpg" }


        ScrollIndicator.vertical: ScrollIndicator { }
        ScrollIndicator.horizontal: ScrollIndicator { }

//        ScrollBar.vertical: ScrollBar { }
//        ScrollBar.horizontal: ScrollBar { }
    }

//    Rectangle {
//        id: scrollbar
//        anchors.right: flickable.right
//        y: flickable.visibleArea.yPosition * flickable.height
//        width: 10
//        height: flickable.visibleArea.heightRatio * flickable.height
//        color: "black"
//    }

}



