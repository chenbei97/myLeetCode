import QtQuick.Controls 2.2

Slider {
    from: 1
    value: 25
    to: 100

    onValueChanged: print(value)
}
