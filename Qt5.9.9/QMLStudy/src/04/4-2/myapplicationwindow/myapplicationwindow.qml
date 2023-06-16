import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

ApplicationWindow {
    title: "My Application"
    width: 600; height: 450
    visible: true

    menuBar: MenuBar { // 菜单栏下有2个菜单
        id: menuBar

        Menu {
            id: fileMenu
            title: qsTr("文件")

            MenuItem {
                text: qsTr("关闭")
                icon.source: "close.png"
                onTriggered: close()
            }
            MenuSeparator {}
            MenuItem {
                text: qsTr("关于")
                icon.source: "about.png"
                onTriggered: popup.open()
            }
        }
    }

    header: ToolBar { // 工具栏 有翻页<,>,⚪,文本和一个⋮
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("<")
                visible: footerbar.currentIndex === 0
                enabled: stack.depth > 1
                onClicked: stack.pop() // 推出
            }

            ToolButton {
                text: qsTr(">")
                visible: footerbar.currentIndex === 0
                enabled: stack.depth < 3
                onClicked: stack.push(mainView) // 压入
            }
            PageIndicator {
                id: indicator
                visible: footerbar.currentIndex === 0
                count: stack.depth
                currentIndex: stack.depth // 显示的⚪个数取决于当前堆叠深度
            }
            Label {
                text: "工具栏"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            ToolButton {
                text: qsTr("⋮")
                onClicked: popup.open()
            }
        }
    }

    Popup { //弹出式组件
        id: popup
        parent: Overlay.overlay
        x: Math.round((parent.width - width) / 2) // 弹出位置在中间
        y: Math.round((parent.height - height) / 2)
        width: 250; height: 150
        modal: true
        focus: true

        Label {
            id: label
            text: "这是个Popup"
            font.pixelSize: 16
            font.italic: true
            x: Math.round((parent.width - width) / 2)
            y: Math.round((parent.height - height) / 2)
        }

        Button {
            text: "Ok"
            onClicked: popup.close()
            anchors.top: label.bottom //锚定标签的底部
            anchors.topMargin: 10 // 保持10的距离
            anchors.horizontalCenter: label.horizontalCenter // 中心位置锚定否则可能变成左对齐了
        }
    }

    footer: TabBar {
        id: footerbar
        width: parent.width

        TabButton {
            text: qsTr("图片")
        }
        TabButton {
            text: qsTr("音乐")
        }
        TabButton {
            text: qsTr("视频")
        }
    }

    StackLayout {
        id: view
        currentIndex: footerbar.currentIndex // 堆叠显示的界面和footerbar勾选的一致
        anchors.fill: parent // 占满窗口

        StackView {
            id: stack
            initialItem: mainView // 堆叠顶层是"图片" 一个组件Component组成
        }
        Rectangle { // "视频"和"音乐"简单替代
            id: secondPage
            color: "lightyellow"
        }
        Rectangle {
            id: thirdPage
            color: "lightblue"
        }
    }

    Component {
        id: mainView
        Item {
            Rectangle {
                anchors.fill: parent
                Image {
                    anchors.fill: parent
                    source: stack.depth + ".png" // 根据堆叠深度显示不同的图片,而stack.depth通过2个Toolbutton的push和pop自动改变的
                }
                Text {
                    text: qsTr("页面") + stack.depth
                }

            }
        }
    }
}










