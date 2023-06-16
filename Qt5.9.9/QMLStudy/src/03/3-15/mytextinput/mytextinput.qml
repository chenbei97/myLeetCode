import QtQuick

Rectangle {
    width: 200;height: 100

    TextInput{
        text: "hello Qt !"
        selectByMouse: true
        mouseSelectionMode: TextInput.SelectWords
        selectedTextColor: "red"
        selectionColor: "green"
        onAccepted: {
            console.log(selectedText.toString())
            console.log(selectionStart)
            console.log(selectionEnd)
            cut()
        }
    }
}
