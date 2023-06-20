import QtQuick.LocalStorage 2.0
import QtQuick 2.0

Rectangle {
    width: 200; height: 100

    Text {
        text: "?"
        anchors.horizontalCenter: parent.horizontalCenter

        function findGreetings() { // identifier、version、description、estimated_size、callback(db)
            var db = LocalStorage.openDatabaseSync("QQmlExampleDB", "1.0", // 数据库预计大小1000000
                                                   "The Example QML SQL!", 1000000); // 创建失败时才会调用回调函数
            db.transaction(
                        function(tx) {
                            // 如果数据库不存在则创建数据库
                            tx.executeSql('CREATE TABLE IF NOT EXISTS Greeting
                                       (salutation TEXT, salutee TEXT)'); // Greeting是表名 括号（）内依次是名称和类型，定义每行
                            // 添加一条记录
                            tx.executeSql('INSERT INTO Greeting VALUES(?, ?)', // 插入1条值
                                          [ 'hello', 'world' ]);
                            tx.executeSql("INSERT INTO Greeting VALUES(\'c++', \'python')");// 插入1条值

                            // 显示内容
                            var rs = tx.executeSql('SELECT * FROM Greeting'); // 查询所有字段

                            var r = ""
                            for(var i = 0; i < rs.rows.length; i++) {
                                r += rs.rows.item(i).salutation + ", "
                                        + rs.rows.item(i).salutee + "\n"
                            }
                            text = r
                        }
                        )
        }
        Component.onCompleted: findGreetings()
    }
}


