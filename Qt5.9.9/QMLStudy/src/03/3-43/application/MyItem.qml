import QtQuick 2.12

Rectangle {
   id: myItem
   signal message(string msg)

   width: 100; height: 100
   color: "blue"

   MouseArea {
       anchors.fill: parent
       onClicked: myItem.message("clicked!")
   }
}
