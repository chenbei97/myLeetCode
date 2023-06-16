import QtQuick

Item {
    width: 100; height: 50
    TextInput{
        id: textInput
        echoMode: TextInput.PasswordEchoOnEdit
        focus: true
        onAccepted: { textInput.focus = false}
    }
}
