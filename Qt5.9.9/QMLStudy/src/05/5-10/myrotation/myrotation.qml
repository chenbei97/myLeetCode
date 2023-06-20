import QtQuick 2.0

Row {
    width: 300
    height: 300
    x: 10; y: 10
    spacing: 10

    Image { source: "qtlogo.png" }

    Image {
        source: "qtlogo.png"
        transform: Rotation { origin.x: 30; origin.y: 30;
            axis { x: 0; y: 1; z: 0 } angle: 150 }
            Scale{origin.x:25; origin.y:25; xScale: 4}
            Translate{x:500;y : 50}
    }
}


