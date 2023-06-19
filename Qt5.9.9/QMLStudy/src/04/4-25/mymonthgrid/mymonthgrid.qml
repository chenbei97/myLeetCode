import QtQuick 2.14
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3
import Qt.labs.calendar 1.0

Window {
    width: 750; height: 550
    visible: true

    ColumnLayout { // gridlayout+listview
        spacing: 20

        GridLayout {
            columns: 2

            DayOfWeekRow { // 第一排显示指定年月的周一到周日
                //locale: grid.locale // 和MonthGrid一起使用
                locale: Qt.locale("en_US")
                Layout.column: 1
                Layout.fillWidth: true
            }

            WeekNumberColumn {  // 对月历显示周数,左侧显示48-53周
                month: grid.month; year: grid.year
                locale: grid.locale
                Layout.fillHeight: true
            }

            MonthGrid { // 显示指定年的指定月，1-31天
                id: grid
                month: Calendar.June; year: 2023
                locale: Qt.locale("zh_CN")
                Layout.fillWidth: true
                Layout.fillHeight: true

                onClicked: (date) => console.log(date)
            }
        }

        ListView {
            id: listview
            spacing: 10
            width: 450; height: 300
            snapMode: ListView.SnapOneItem // 拖动或者轻弹视图和开始的视图对齐
            orientation: ListView.Horizontal
            highlightRangeMode: ListView.StrictlyEnforceRange// 高亮永远不会移动到范围之外

            model: CalendarModel {
                from: new Date(2023, 0, 1)
                to: new Date(2023, 12, 31)
            }

            delegate: Frame {
                width: 300; height: 300

                ColumnLayout {
                    anchors.fill: parent

                    Label {
                        id: label
                        text: monthGrid.title
                    }

                    DayOfWeekRow {
                        locale: monthGrid.locale
                        Layout.fillWidth: true
                    }

                    MonthGrid {
                        id: monthGrid
                        background: Rectangle { color:"lightgrey" }
                        month: model.month
                        year: model.year
                        locale: Qt.locale("en_US")
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }
                }
            }

            ScrollIndicator.horizontal: ScrollIndicator { }
        }
    }
}





