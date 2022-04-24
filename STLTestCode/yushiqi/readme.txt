#include <iostream>
using namespace std;
int main()
{
    return 0;
}

mul.hpp包含了一个返回乘积的函数声明
int mul(int x, int y);
mul.cpp给出了其完整定义
这里可以直接直接编译2个文件
cd STLTestCode\\yushiqi
g++ main.cpp mul.cpp -o mul.exe
./mul

但是更常用的是分别编译,然后动态链接,同样可以得到结果
g++ -c main.cpp
g++ -c mul.cpp
g++ mul.o main.o -o linkedmul
./linkedmul

常见的预处理命令
define、undef、include、if、ifdef
else、elif、endif、line、error、pragma
例如定义宏常量、宏函数、依据条件包含头文件
```
#define PI 3.1415926535
#if defined(_OPENMP)
#include <omp.h>
#endif
```

主函数是可以带参数的,见argument.cpp
int main(int argc,char** argv){...}
先编译g++ argument.cpp -o argument.exe
可以在exe文件后跟上参数,以逗号分割
./argument.exe hello world ! hello C++ !
输出结果,可以知道参数0就是自身：
param 0: C:\Users\chenb\VscodeItems\myLeetCode\STLTestCode\yushiqi\argument.exe
param 1: hello
param 2: world
param 3: !
param 4: hello
param 5: C++
param 6: !

sizeof是个操作符,不是函数,因为它可接收非参数,sizeof(int)
g++ sizeof.cpp -o sizeof.exe
./sizeof.exe

char.cpp说明了一些char字面量的用法
g++ char.cpp -o char.exe
./char.exe