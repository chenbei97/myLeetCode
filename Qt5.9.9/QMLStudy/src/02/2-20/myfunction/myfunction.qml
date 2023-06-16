import QtQuick

Rectangle {
    id: rect

    function calculateHeight() : real {
        return rect.width / 2;
    }

    width: 400; height: calculateHeight()
}

