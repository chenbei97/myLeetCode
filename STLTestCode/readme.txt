1、速查表
关于STL标准库的一些函数的图，可以快速查阅
2、algorithms
对<algorithms>的函数测试
3、containers
对所有容器类型进行测试
4、memory
针对3个智能指针测试，即unique_ptr、weak_ptr和shared_ptr
5、numeric
一些<numeric>的函数测试
6、other
other是一些c++17/20的一些新特性的测试
7、random
专门针对<random>的测试，说明了各种随机生成器和随机分布的应用
8、STLSourceCodeAnalysis
《STL源码剖析》一书的一些程序，可配合STLSourceCodeAnalysis.md一起查看
《STL源码剖析》脚本都只有1个主函数，可以使用ctrl+shift+p编译
也有《深度探索C++对象模型》的一些小脚本，《深度探索C++对象模型》都是使用终端编译,每个脚本都有main函数
ecm打头的都是《深度探索C++对象模型》书中出现过的一些例子，ecm = explore c++ model
9、thread
线程的知识，目前是依据b站的视频学习的
10、yushiqi
yushiqi的文件夹是于仕琪老师在b站的课的一些知识补充笔记
https://www.bilibili.com/video/BV1Vf4y1P7pq?spm_id_from=333.337.search-card.all.click
11、其它
readme.txt 说明
test_cl.cpp 因为有的函数似乎g++不能编译,所以纳入了VS的cl.exe进行编译，这是测试文件

/*
cd STLTestCode
g++ -o m m.cpp 
.\m.exe
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
C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\ucrt\x64
C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\um\x64
C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC\14.29.30133\lib\x64
五、一定要重启终端,VSCode也是重启即可命令行使用
cl hello.cpp类似的命令
六、参考配置网址
https://zhuanlan.zhihu.com/p/98384105
七、测试
终端输入cl,出现cl [ 选项... ] 文件名... [ /link 链接选项... ]说明正确
现在在../STLTestCode新建1个测试cl.exe的文件test_cl.cpp
```
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {5,4,3,2,1};
    sort(src.begin(),src.end());
    cout<<"src: ";
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    int sum = accumulate(src.begin(),src.end(),0);
    cout<<"sum: "<<sum<<endl;
    
    return 0;
}
```
然后输入命令:
cd STLTestCode
cl test_cl.cpp或
cl ./test_cl.cpp或
cl .\test_cl.cpp 均可
会自动生成a.obj和a.exe文件
执行.\test_cl.exe，但是./test_cl.exe和test_cl.exe不行

还可指定命名对象文件可用/Fo,可执行文件为/Fe,然后跟上被编译的文件,都用双引号指定好路径
cl /Fo"..\output\test_cl" /Fe"..\output\test_cl.exe" /std:c++latest ".\test_cl.cpp"
..\output\test_cl.exe
输出:
src: 1 2 3 4 5 
sum: 15

如果能通过编译，但连接时候提示LINK : fatal error LNK1104:无法打开文件“kernel32.lib”
找到C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\um\x64下的Uuid.Lib、kernel32.Lib 2个lib文件
以及C:\Program Files (x86)\Windows Kits\10\Lib\10.0.19041.0\ucrt\x64下的libucrt.lib、libucrtd.lib、ucrt.lib和ucrtd.lib 4个lib文件
将其复制到C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC\14.29.30133\lib\x64当中
注意：6个lib文件都要复制；其次根据自己的位数(x64)选择；是找到Windows Kits下的lib复制到Visual Studio下MSVC的lib中

cl /?可以查看命令参数列表,常见命令给定如下
```
/Fa[file] 命名程序集列表文件            /FA[scu] 配置程序集列表
/Fd[file] 命名 .PDB 文件                /Fe<file> 命名可执行文件
/Fm[file] 命名映射文件                  /Fo<file> 命名对象文件
/Fp<file> 命名预编译头文件              /Fr[file] 命名源浏览器文件
/FR[file] 命名扩展 .SBR 文件            /Fi[file] 命名预处理的文件
/Fd: <file> 命名 .PDB 文件              /Fe: <file> 命名可执行文件
/Fm: <file> 命名映射文件                /Fo: <file> 命名对象文件
/Fp: <file> 命名 .PCH 文件              /FR: <file> 命名扩展 .SBR 文件
/Fi: <file> 命名预处理的文件            /Ft<dir> 为 #import 生成的头文件的地址
/doc[file] 处理 XML 文档注释，并可选择命名 .xdc 文件
/AI<dir> 添加到程序集搜索路径           /FU<file> 强制使用程序集/模块 
/C 不抽出注释                           /D<name>{=|#}<text> 定义宏
/E 预处理到 stdout                      /EP 预处理到 stdout，无行号
/P 预处理到文件                         /Fx 将插入的代码合并到文件中
/FI<file> 命名强制包含文件              /U<name> 移除预定义的宏
/u 移除所有预定义的宏                   /I<dir> 添加到包含搜索路径
/X 忽略“标准位置”                     /PH 在预处理时生成 #pragma file_hash
/PD 打印所有宏定义
/std:<c++14|c++17|c++latest> C++ 标准版
    c++14 - ISO/IEC 14882:2014 (默认值)
    c++17 - ISO/IEC 14882:2017
    c++latest - 最新草案标准(功能集可能会更改)
/permissive[-] 使某些非符合代码可编译(功能集可更改)(默认开启)
```
