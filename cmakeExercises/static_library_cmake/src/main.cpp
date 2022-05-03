#include "static/hello.h"
// 使用此方法包含头文件,在项目中使用多个库时,头文件名冲突的可能性较小
int main(int argc, char *argv[])
{
    Hello hi;
    hi.sayHello();
    return 0;
}