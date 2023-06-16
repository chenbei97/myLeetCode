import QtQuick 2.14
import QtQuick.Window 2.0
import QtQuick.Controls 2.14

Item{
    id:w
        width: 400;
        height: 300;
        signal username(string name)
        signal password(string pwd)
//        Column
//        {
//                Row {
//                    id:row1
//                    Text {
//                        id: user_label
//                        text: qsTr("用户名: ")

//                    }
//                    TextEdit {
//                        id: user
//                        text: qsTr("admin")
//                        //anchors.left: user_label.right
//                    }
//                }
//                Row {
//                    id:row2
//                    //anchors.top: row1.bottom
//                    Text {
//                        id: pwd_label
//                        text: qsTr("密码: ")
//                    }
//                    TextEdit {
//                        id: pwd
//                        text: qsTr("123456")
//                        //anchors.left: user_label.right
//                    }
//                }
//    }
        Column {
            anchors.centerIn: parent
        Rectangle {
id:r1
                            Text {
                                id: user_label
                                text: qsTr("用户名: ")
                                //anchors.centerIn : parent
                            }
                            TextEdit {
                                id: user
                                text: qsTr("admin")
                                anchors.left: user_label.right
                            }
            }
        Rectangle {
            //anchors.centerIn: parent
            anchors.top: r1
            anchors.topMargin: 10
                            Text {
                                id: pwd_label
                                text: qsTr("密码: ")
                            }
                            TextEdit {
                                id: pwd
                                text: qsTr("123456")
                                anchors.left: pwd_label.right

                            }
        }
        }
        Button {
            y: 150
            x:300
            onClicked:  {
                username(user.text); password(pwd.text);
               // console.log(user.text,pwd.text)
            }
        }
}
