import QtQuick 2.12

Grid {
    columns: 3
    spacing: 2; padding: 5

    Rectangle { color: "white"; border.width: 1; width: 50; height: 50 }
    Rectangle { color: "green"; width: 20; height: 50 }
    Rectangle { color: "lightgrey"; width: 50; height: 20 }
    Rectangle { color: "cyan"; width: 50; height: 50 }
    Rectangle { color: "magenta"; width: 10; height: 10 }
}
