非ecm打头的文件都是《STL源码剖析》的程序，每个文件都带有main函数，终端编译

ecm打头的文件都是《深度探索C++对象模型》的程序，每个文件都带有main函数，终端编译

所有输出的二进制文件都在output中

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    /*

    */
    return 0;
}
/*
cd STLTestCode\srcCodeAna
g++ -o .\output\m m.cpp 
.\output\m.exe
*/