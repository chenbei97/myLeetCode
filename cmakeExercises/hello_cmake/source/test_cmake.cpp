/*
 * @Author: chenbei
 * @Date: 2022-04-30 16:55:32
 * @LastEditTime: 2022-04-30 16:57:02
 * @FilePath: \myLeetCode\cmakeExercises\hello_cmake\source\test_cmake.cpp
 * @Description: test for cmake
 * @Signature: A boy without dreams
 */
#include <iostream>
using namespace std;
int main(int argc,char**argv)
{
    cout<<"hello cmake!"<<endl;
    // 打印终端命令字符串
    for (int i = 0; i<argc;++i){
        cout<<argv[i]<<" ";
    }
    cout<<endl;
    return 0;
}
