import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Window {
    width: 640; height: 480
    visible: true

    ColumnLayout {
        spacing: 20

        CheckBox { text: qsTr("First") }
        Button {text: qsTr("Button") }
        BusyIndicator { running: image.status === Image.Loading }
        ProgressBar { value: 0.5 }
        Dial { value: 0.5 }
    }
}
