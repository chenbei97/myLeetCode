#ifndef LISTFILES_TEST_H
#define LISTFILES_TEST_H
#include <core/list_files.h> // 对 list_files的函数测试
void list_files_test()
{
    //qDebug()<<listFiles("..",QStringList() << "*.cpp" << "*.h"); // 或者../也可以
    qDebug()<<listFiles("../login",QStringList() << "*.cpp" << "*.h");
}
#endif // LISTFILES_TEST_H
