import QtQuick 2.0

Item {
    property string title
    property string detail

    Text {
        id: text
        text: "<b>"+title+"</b><br>"+detail
    }

    function getTitle()
    {
        return title
    }

    function setTitle(newTitle) {
        title = newTitle
    }
}
