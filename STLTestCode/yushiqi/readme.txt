/*
cd STLTestCode\\yushiqi
g++ -o m m.cpp
./m
*/
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

do_while语句要注意至少执行1次，while可能一次也不执行
另外不要使用无符号size_t作为控制变量,当size_t变为0再--时就会出错

goto语句要少用,见goto.cpp

strlen可以计算char_8的字符长度，和sizeof不同，不会包含\0的长度

strcpy和strcmp有更安全的方式，见strcpy.cpp

opencv中step的含义是：每行需要的步，起始就是列的大小
利用步，即使在大矩阵中的某个小矩阵去获取数据，也可以通过data指针反复加上step就可以得到每行的首地址
可见图片opencv中step的用法.jpg的示意图
libfacedetection.jpg则是于仕琪老师的人脸检测库

myString.cpp说明了如何定义自己的operator=、复制构造函数以及析构释放函数
进行深拷贝，防止释放内存多次导致错误
void release(){
    cout<<"release() is called"<<endl;
    this->buf_size=0;
    if (this->characters!=nullptr){ // 不为空的话先释放
        delete[] this->characters;//先释放掉自己的空间
        this->characters=nullptr;
    }
}
bool create(int buf_size,const char*data){
    this->release(); // 先释放掉自己的空间
    this->buf_size=buf_size;
    if (this->buf_size !=0){ // 如果申请的空间不为0
        this->characters=new char[this->buf_size]{};
    }
    // 如果data不为空,就拷贝数据
    if(data) strncpy(this->characters,data,this->buf_size);
    return true;
}