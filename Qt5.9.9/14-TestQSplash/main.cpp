#include "TestQSplash.h"
#include "LoginDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog * login = new LoginDialog;
    if (login->exec() == QDialog::Accepted) // 模态方式运行对话框,如果返回了Accepted说明用户名和密码均正确
    {
        TestQSplash w;
        w.show();
        return a.exec();
    }
    else return 0;
}
