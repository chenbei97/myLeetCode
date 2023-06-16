import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12

Rectangle {
    LayoutMirroring.enabled: true // 启用镜像
    LayoutMirroring.childrenInherit: true // 子项目继承 才能镜像

    width: 300; height: 60
    color: "lightyellow"
    border.width: 1

    Row {
        anchors { left: parent.left; margins: 5 } // 锚定在左侧由于进行了反转就锚定在右侧了
        y: 5; spacing: 5; padding: 5

        Repeater {
            model: 5

            Rectangle {
                color: "grey"
                opacity: (5 - index) / 5
                width: 40; height: 40

                Text {
                    text: index + 1
                    anchors.centerIn: parent
                    font.bold: true
                }
            }
        }
    }
}
