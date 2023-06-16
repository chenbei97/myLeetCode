import QtQuick

Row {
    spacing: 10; padding: 10

    Text { font.pointSize: 40; text: "Normal" }

    Text { font.pointSize: 40; text: "Raised"; color: "#FFAABB"
        style: Text.Raised; styleColor: "black" }

    Text { font.pointSize: 40; text: "Outline"; color: "white"
        style: Text.Outline; styleColor: "red" }

    Text { font.pointSize: 40; text: "Sunken"; color: "lightgrey"
        style: Text.Sunken; styleColor: "black" }
}

