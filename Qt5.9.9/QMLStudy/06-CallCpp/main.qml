import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id:btn1
        text: "btn1"
        onClicked: ChenBei.printInfo()//调用Q_INVOKABLE声明的公共函数
    }
    Button {
        id:btn2
        anchors.top: btn1.bottom
        anchors.horizontalCenter: btn1.horizontalCenter
        text: "btn2"
        onClicked: ChenBei.print()//调用槽函数
    }
    Button {
        objectName: "btn3"
        anchors.top: btn2.bottom
        anchors.horizontalCenter: btn2.horizontalCenter
        text: "btn3"
        //这里不写槽函数,在main.cpp写,
    }
}
