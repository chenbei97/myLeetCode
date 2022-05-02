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

同时编译且输出可以这样做
g++ -o m m.cpp && .\m
g++ m.cpp && .\a
不过本版本测试以后不能通过编译,说是g++版本不支持&&

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

char.cpp说明了一些char字面量的用法,c++11引入char16_t和char32_t
g++ char.cpp -o char.exe
./char.exe

float.cpp说明了一些精度问题,以及如何设置打印精度
g++ float.cpp -o float.exe
./float.exe

convert.cpp说明了溢出问题,有符号最高位是符号位
unsigned char a = 255;
unsigned char b = 1;
int c1 = a + b ;
unsigned int c2 = a + b ;
unsigned char c3 = a + b ;
cout<<"c1 = "<<c1<<endl; // 256
cout<<"c2 = "<<c2<<endl; // 256
cout<<"c3 = "<<c3<<endl; // 没有结果,直接溢出
g++ convert.cpp -o convert.exe
./convert.exe

stdint.cpp定义了一些常见的int类型宏的最大值
int8_t,int16_t,int32_t,int64_t
uint8_t,uint16_t,uint32_t,uint64_t
INT8_MIN,INT16_MIN,INT32_MIN,INT64_MIN
INT8_MAX,INT16_MAX,INT32_MAX,INT64_MAX
UINT8_MAX,UINT16_MAX,UINT32_MAX,UINT64_MAX
g++ stdint.cpp -o stdint.exe
./stdint.exe
