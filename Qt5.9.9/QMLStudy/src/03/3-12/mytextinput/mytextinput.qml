import QtQuick

Item {
//    width: 100; height: 50
//    TextInput{
//        validator: IntValidator{ bottom: 11; top: 31; }
//        focus: true
//        onEditingFinished: console.log(text)
//    }

    Rectangle {
        id: rect
        width: input.contentWidth<100 ? 100 : input.contentWidth + 10
        height: input.contentHeight + 5
        color: "lightgrey"
        border.color: "grey"

        TextInput {
            id: input
            anchors.fill: parent
            anchors.margins: 2
            font.pointSize: 15
            focus: true

            inputMask: ">AA_9_a"
            onEditingFinished: text2.text = text
        }
    }

    Text { id: text2; anchors.top: rect.bottom}
}


