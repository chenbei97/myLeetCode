VS新建一个动态DLL项目，在HelloDll文件夹中
注意删除自带生成的4个文件，2个头文件和2个源文件
新建hello.h和hello.cpp文件

"hello.h"：
#pragma once
#define DLL _declspec(dllexport)
class DLL Hello
{
public:
	void print();
};

"hello.cpp"：
#include <iostream>
#include "hello.h"
void Hello::print()
{
	std::cout << "hello world!" << std::endl;
}
然后在项目右击找到预编译头，取消它
然后右击项目点击生成即可，就会得到dll+lib文件

新建空白项目，testDll，写一个main.cpp，注意使用comment

#pragma comment (lib,"helloDll.lib")
#include "hello.h"
int main() {
	Hello hi;
	hi.print();
	return 0;
}

然后把生成的lib+dll+hello.h文件都放在main.cpp同一文件夹
同时工程资源文件把lib文件包含进来
经过测试dll+lib缺一不可，都要存在
即可运行项目