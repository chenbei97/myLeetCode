import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 450; height: 490
    visible: true

    ColumnLayout {
        spacing: 20

        GridLayout {
            columns: 2

            DayOfWeekRow {
                locale: grid.locale
                Layout.column: 1
                Layout.fillWidth: true
            }

            WeekNumberColumn {
                month: grid.month; year: grid.year
                locale: grid.locale
                Layout.fillHeight: true
            }

            MonthGrid {
                id: grid
                month: Calendar.December; year: 2022
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
            snapMode: ListView.SnapOneItem
            orientation: ListView.Horizontal
            highlightRangeMode: ListView.StrictlyEnforceRange

            model: CalendarModel {
                from: new Date(2023, 0, 1)
                to: new Date(2023, 11, 31)
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





