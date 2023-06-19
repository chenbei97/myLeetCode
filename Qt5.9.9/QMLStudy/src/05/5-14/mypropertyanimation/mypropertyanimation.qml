import QtQuick

Image {
    id: fengche
    width: 300; height: 300
    source: "fengche.png"
    opacity: 0.1

    MouseArea {
        anchors.fill: parent
        onClicked: {
            animateRotation.start()
            animateOpacity.start()
        }
    }

    PropertyAnimation {
        id: animateOpacity
        target: fengche; properties: "opacity"
        to: 1.0; duration: 2000
    }

    NumberAnimation {
        id: animateRotation
        target: fengche; properties: "rotation"
        from: 0; to: 360; duration: 3000
        loops: Animation.Infinite
        easing {type: Easing.OutBack}
    }
}

