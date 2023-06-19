import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import QtQuick.Window 2.3

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
