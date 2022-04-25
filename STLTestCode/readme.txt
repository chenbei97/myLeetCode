这是关于Boost一些库函数的测试,持续更新
https://www.boost.org/doc/libs/1_79_0/?view=condensed&sort=cxxstd

也有《STL源码剖析》以及《深度探索C++对象模型》的一些小脚本
ecm打头的都是后者书中出现过的一些例子，ecm = explore c++ model

《STL源码剖析》脚本都只有1个主函数，可以使用ctrl+shift+p编译

《深度探索C++对象模型》都是使用终端编译,每个脚本都有main函数

yushiqi的文件夹是于仕琪老师在b站的课的一些知识补充笔记
https://www.bilibili.com/video/BV1Vf4y1P7pq?spm_id_from=333.337.search-card.all.click

other是一些新特性

/*
cd STLTestCode
g++ -o ecm1_0_pointer3d_c ecm1_0_pointer3d_c.cpp 
.\ecm1_0_pointer3d_c.exe
*/
#include <iostream>
using namespace std;
int main()
{
    return 0;
}

// 如果需要使用VS的cl.exe来编译文件,遵循以下操作
一、在VS的目录下，一般是C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC
找到路径：C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64
将其放在环境变量PATH中
二、新建环境变量WINDOWS_SDK_VERSION
其值为10.0.19041.0，这个遵循自己电脑的版本
三、新建环境变量INCLUDE
找到VC\Tools\MSVC下的include文件夹,然后找到Windows Kits\Include下的3个文件夹ucrt,shared,um,路径用分号隔开
C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC\14.29.30133\include\
C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt
C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\shared
C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\um
四、新建环境变量LIB
返回到Windows Kits\Lib下,2个文件夹包含进去ucrt,um,以及C\Tools\MSVC下的lib\x64文件夹
C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\ucrt
C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\um
C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC\14.29.30133\lib\x64
五、一定要重启终端,VSCode也是重启即可命令行使用
cl hello.cpp类似的命令
六、参考配置网址
https://zhuanlan.zhihu.com/p/98384105