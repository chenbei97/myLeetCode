import QtQuick 2.12

Rectangle {
    color: "lightsteelblue"; width: 400; height: 250
    Text { id: myText }
    Item {
        id: keyHandler
        focus: true
        Keys.onPressed: (event)=> {
            if (event.key === Qt.Key_A)
                myText.text = 'Key A was pressed'
            else if (event.key === Qt.Key_B)
                myText.text = 'Key B was pressed'
            else if (event.key === Qt.Key_C)
                myText.text = 'Key C was pressed'
        }
    }
}
