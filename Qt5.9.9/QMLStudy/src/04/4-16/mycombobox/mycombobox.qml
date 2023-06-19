import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import QtQuick.Layouts 1.3

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
                model.append({text: editText}) // 按回车如果没有这个项会自动添加进去
        }
    }
}




