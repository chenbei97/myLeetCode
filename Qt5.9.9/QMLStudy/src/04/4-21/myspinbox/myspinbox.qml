import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    RowLayout {

        SpinBox {
            id: spinBox
            from: 0; to: items.length - 1
            value: 1 // "Medium"

            property var items: ["Small", "Medium", "Large"]

            validator: RegularExpressionValidator {
                regularExpression: new RegExp("(Small|Medium|Large)", "i")
            }

            textFromValue: function(value) {
                return items[value];
            }

            valueFromText: function(text) {
                for (var i = 0; i < items.length; ++i) {
                    if (items[i].toLowerCase().indexOf(text.toLowerCase()) === 0)
                        return i
                }
                return spinBox.value
            }
        }


        SpinBox {
            id: spinbox
            from: 0;  to: 100 * 100
            value: 110; stepSize: 100

            property int decimals: 2
            property real realValue: value / 100

            validator: DoubleValidator {
                bottom: Math.min(spinbox.from, spinbox.to)
                top:  Math.max(spinbox.from, spinbox.to)
            }

            textFromValue: function(value, locale) {
                return Number(value / 100).toLocaleString(locale, 'f', spinbox.decimals)
            }

            valueFromText: function(text, locale) {
                return Number.fromLocaleString(locale, text) * 100
            }
        }
    }
}



