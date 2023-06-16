import QtQuick

Column {
    padding: 10

    Text {
        font.pointSize: 24
        text: "<b>Hello</b> <i>World!</i>"
    }
    Text {
        font.pointSize: 24; textFormat: Text.RichText
        text: "<b>Hello</b> <i>World!</i>"
    }
    Text {
        font.pointSize: 24; textFormat: Text.PlainText
        text: "<b>Hello</b> <i>World!</i>"
    }
    Text {
        font.pointSize: 24; textFormat: Text.StyledText
        text: "<del>Hello</del> <h1>World!</h1>"
    }
    Text {
        font.pointSize: 24; textFormat: Text.MarkdownText
        text: "**Hello** *World!*"
    }
}

