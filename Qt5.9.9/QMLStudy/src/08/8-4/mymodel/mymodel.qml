import QtQuick 2.14
import QtQuick.XmlListModel 2.0
import QtQuick.Controls 2.5

Rectangle {
    width: 300; height: 400

    XmlListModel {
        id: xmlModel
        source: "http://www.people.com.cn/rss/edu.xml"
        query: "/rss/channel/item" // 查找这个xml子路径下

        XmlRole{ name: "title"; query: "title/string()" }
        XmlRole { name: "pubDate"; query: "pubDate/string()" }
    }

    ListView {
        id: view
        anchors.fill: parent
        model: xmlModel
        focus: true // 不为真的话键盘上下按键不能导航
        spacing: 8
        delegate: Label { // 使用label代理
            id: label
            width: view.width; height: 50 // 高度指定，宽度和ListView相同
            verticalAlignment: Text.AlignVCenter // 文本垂直居中
            text: title + ": " + pubDate // 文本内容
            font.pixelSize: 15; elide: Text.ElideRight // 15号字 靠右侧的话隐藏文本,也就是窗口宽度比较小
            color: label.ListView.isCurrentItem ? "blue" : "green"
            background: Image {
                visible: label.ListView.isCurrentItem
                source: "bg.png"
            }
        }
    }
}





