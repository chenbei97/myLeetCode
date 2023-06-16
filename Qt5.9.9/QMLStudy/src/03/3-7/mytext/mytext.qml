import QtQuick

Column {
    spacing: 20

    Text {
        width: 200
        text: qsTr("1使文本在单行中对于超出部分不要进行省略")
        font.pointSize: 20
    }
    Text {
        width: 200
        elide: Text.ElideLeft
        text: qsTr("2使文本在单行中对于超出部分从左边进行省略")
        font.pointSize: 20
    }
    Text {
        width: 200
        elide: Text.ElideMiddle
        text: qsTr("3使文本在单行中对于超出部分从中间进行省略")
        font.pointSize: 20
    }
    Text {
        width: 200
        elide: Text.ElideRight
        text: qsTr("4使文本在单行中对于超出部分从右边进行省略")
        font.pointSize: 20
    }
    Text {
        width: 200
        height: 90
        wrapMode: Text.WordWrap
        elide: Text.ElideRight
        text: qsTr("5可换行的多行文本，如果设置了高度，对超出部分从右边进行省略")
        font.pointSize: 20
    }
    Text {
        width: 200
        maximumLineCount: 2
        wrapMode: Text.WordWrap
        elide: Text.ElideRight
        text: qsTr("6可换行的多行文本，如果设置了最大行数，对超出部分从右边进行省略")
        font.pointSize: 20
    }
}

