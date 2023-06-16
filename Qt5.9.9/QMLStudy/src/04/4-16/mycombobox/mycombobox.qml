import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true

    ComboBox {
        editable: true
        model: ListModel {
            id: model
            ListElement { text: "Banana" }
            ListElement { text: "Apple" }
            ListElement { text: "Coconut" }
        }
        onAccepted: {
            console.log(currentIndex + currentText)
            if (find(editText) === -1)
                model.append({text: editText})
        }
    }
}




