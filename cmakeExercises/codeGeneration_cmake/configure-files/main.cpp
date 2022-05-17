/*** 
 * @Author: chenbei
 * @Date: 2022-05-17 15:09:21
 * @LastEditTime: 2022-05-17 15:13:06
 * @Description:configure file's main.cpp 
 * @FilePath: \myLeetCode\cmakeExercises\codeGeneration_cmake\configure-files\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include "ver.h"
#include "path.h"
int main(int argc, char *argv[])
{
    // ver和path不需要自己编写,借助2个文件path.h.in和ver.h.in
    // 不过要注意的是带有.in后缀,这个文件是编译时自动生成的,不需要手动编写
    // ver是常量字符串,const char*,包含于ver.h
    std::cout << "Hello Version " << ver << "!" << std::endl;
    std::cout << "Path is " << path << std::endl;
   return 0;
}