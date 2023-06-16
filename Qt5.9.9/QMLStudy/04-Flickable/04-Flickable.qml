import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 1000
    height: 800
    title: qsTr("Hello World")

    Column {
//            Flickable {
//                width: 200; height: 200
//                contentWidth: -image.width; contentHeight: image.height

//                Image { id: image; source: "bigImage.png" }
//            }

            ListView {
                width: 180; height: 200
                model: ContactModel {}
                delegate: Text {
                    text: name + ": " + number
                    font.pixelSize: 40
                    color: "red"
                }
            }

//            Rectangle {
//                  width: 180; height: 200
//                    y: 600
//                    x:600
//                  Component {
//                      id: contactDelegate
//                      Text { // 代理不能用Rectangle下方就没highlight的效果了,item可以
//                          width: 180; height: 40
//                          Column {
//                              Text { text: '<b>Name:</b> ' + name }
//                              Text { text: '<b>Number:</b> ' + number }
//                          }
//                      }
//                  }

//                  ListView {
//                      anchors.fill: parent
//                      model: ContactModel {}
//                      delegate: contactDelegate
//                      highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
//                      focus: true
//                  }
//              }


            ListView {
                width: 180; height: 200

                Component {
                    id: contactsDelegate
                    Rectangle {
                        id: wrapper
                        width: 180
                        height: contactInfo.height //矩形高度是文本高度
                        color: ListView.isCurrentItem ? "black" : "red"
                        Text {
                            id: contactInfo
                            text: name + ": " + number
                            color: wrapper.ListView.isCurrentItem ? "red" : "black" // 文本颜色和矩形颜色保持相反要借助id
                        }
                    }
                }

                model: ContactModel {}
                delegate: contactsDelegate
                focus: true
            }
    }
}
