import QtQuick 2.9
import QtQuick.Controls 2.5

Rectangle {
    width: 800; height: 800

    Flickable {
        id: flickable
        width: 800; height: 800
        contentWidth: image.width; contentHeight: image.height
        clip: true

        Image { id: image; source: "bigImage.jpg" }


//        ScrollIndicator.vertical: ScrollIndicator { } // 两种方法都可以加滚动条
//        ScrollIndicator.horizontal: ScrollIndicator { }

        ScrollBar.vertical: ScrollBar { }
        //ScrollBar.horizontal: ScrollBar { }
    }

    Rectangle { // 使用矩形实现滑动条效果，visibleArea描述了当前可视区域的位置和大小
        id: scrollbar
        anchors.right: flickable.right
        y: flickable.visibleArea.yPosition * flickable.height
        width: 10
        height: flickable.visibleArea.heightRatio * flickable.height
        color: "black"
    }

}



