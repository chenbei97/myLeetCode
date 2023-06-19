import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 400; height: 400

    header: Label {
        text: view.currentItem.title
        horizontalAlignment: Text.AlignHCenter
    }

    SwipeView {
        id: view
        anchors.fill: parent

        Page {
            title: qsTr("页面1")
            header: ToolBar{
                RowLayout {
                    anchors.fill: parent
                    ToolButton { text: qsTr("按钮1") }
                    ToolButton { text: qsTr("按钮2") }
                }
            }
            footer: ToolBar{
                Label {
                    text: qsTr("工具栏")
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }

        Page {
            title: qsTr("页面2")
            header: TabBar {
                TabButton { text: qsTr("选项1") }
                TabButton { text: qsTr("选项2") }
            }
        }
    }

    PageIndicator {
        currentIndex: view.currentIndex
        count: view.count
        anchors.bottom: view.bottom; anchors.bottomMargin: 30
        anchors.horizontalCenter: view.horizontalCenter
    }
}

