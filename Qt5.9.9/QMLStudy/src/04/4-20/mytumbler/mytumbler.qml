import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: frame.implicitWidth + 10
    height: frame.implicitHeight + 10

    function formatText(count, modelData) {
        var data = count === 12 ? modelData + 1 : modelData; // 是12就为modelData + 1 也就是下一个
        return data.toString().length < 2 ? "0" + data : data; // 显示带个0
    }

    Component {
        id: delegateComponent

        Label {
            text: formatText(Tumbler.tumbler.count, modelData)
            opacity: 1.0 - Math.abs(Tumbler.displacement)
                     / (Tumbler.tumbler.visibleItemCount / 2)
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Frame {
        id: frame
        anchors.centerIn: parent; padding: 0

        Row {
            id: row

            Tumbler {
                id: hoursTumbler
                model: 12; delegate: delegateComponent
            }

            Tumbler {
                id: minutesTumbler
                model: 60; delegate: delegateComponent
            }

            Tumbler {
                id: amPmTumbler
                model: ["AM", "PM"]; delegate: delegateComponent
            }
        }
    }
}





