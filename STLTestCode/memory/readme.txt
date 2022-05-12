cd STLTestCode\\memory\\source
引用计数这种计数是为了防止内存泄露而产生的
基本想法是对于动态分配的对象，进行引用计数，每当增加一次对同一个对象的引用，
那么引用对象的引用计数就会增加一次，每删除一次引用，引用计数就会减一
当一个对象的引用计数减为零时，就自动删除指向的堆内存

传统 C++ 中，『记得』手动释放资源，总不是最佳实践。因为我们很有可能就忘记了去释放资源而导致泄露
所以通常的做法是对于一个对象而言，我们在构造函数的时候申请空间
而在析构函数（在离开作用域时调用）的时候释放空间，也就是我们常说的 RAII 资源获取即初始化技术。

凡事都有例外，我们总会有需要将对象在自由存储上分配的需求，在传统 C++ 里我们只好使用 new
和 delete 去『记得』对资源进行释放。而 C++11 引入智能指针的概念，使用引用计数的想法，让程序员不
再需要关心手动释放内存。这些智能指针就包括 std::shared_ptr/std::unique_ptr/std::weak_ptr，
使用它们需要包含头文件 <memory>。

注意：引用计数不是垃圾回收，引用计数能够尽快收回不再被使用的对象
同时在回收的过程中也不会造成长时间的等待，更能够清晰明确的表明资源的生命周期
/*
g++ -o ..\output\m m.cpp
..\output\m.exe
cl /Fo"..\output\m" /Fe"..\output\m.exe" /std:c++latest ".\m.cpp"
..\output\m.exe
*/
#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
using namespace std;
int main()
{
    /*
        
    */
    vector<int> src = {};
    ostream_iterator<int> out(cout," ");
    return 0;
}