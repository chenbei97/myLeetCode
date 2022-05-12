/*
g++ -o ..\output\shared_ptr_g++ shared_ptr.cpp
..\output\shared_ptr_g++.exe
cl /Fo"..\output\shared_ptr_cl" /Fe"..\output\shared_ptr_cl.exe" /std:c++latest ".\shared_ptr.cpp"
..\output\shared_ptr_cl.exe
*/
#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
using namespace std;
void foo(std::shared_ptr<int> i) { // 参数是一个绑定单一变量int*的智能指针
    (*i)++; // (*i) is a reference
}
int main()
{
    /*
        std::shared_ptr 是一种智能指针，它能够记录多少个 shared_ptr 共同指向一个对象
        从而消除显式的调用 delete，当引用计数变为零的时候就会将对象自动删除

        但还不够，因为使用 std::shared_ptr 仍然需要使用 new 来调用，这使得代码出现了某种程度上的不对称
        std::make_shared 就能够用来消除显式的使用 new
        所以 std::make_shared 会分配创建传入参数中的对象，并返回这个对象类型的 std::shared_ptr 指针

        这里注意一下使用cl编译是unique已经不是shared_ptr的成员函数,不能使用
    */
    // auto pointer = new shared_ptr<int>(10); // 注意这样是不合法的
    // 除非这样使用new构造
    auto pointer = new std::shared_ptr<int>(new int(10)); // 前者是新建智能指针,后者是新建底层的int*指针
    // 打印智能指针指向的值
    cout <<"*pointer: "<< *pointer << endl; // 就像普通指针那样使用它
    cout <<"**pointer: "<< **pointer << endl; // 就像普通指针那样使用它,实际上是两层
    // 也可以通过函数get()来获取智能指针底层指针
    cout <<"pointer->get(): "<< pointer->get() << endl; // 就像普通指针那样使用它
    // 使用reset()来重置智能指针
    pointer->reset(new int(20)); // ok
    cout <<"**pointer: "<< **pointer << endl; // 20
    // 使用swap()来交换智能指针
    std::shared_ptr<int> pointer2(new int(30)); // 新建一个智能指针
    pointer->swap(pointer2); // 交换智能指针
    cout <<"**pointer: "<< **pointer << endl; // 30
    // 使用unique()来判断智能指针是否是唯一的
    // cout <<boolalpha<<"pointer->unique(): "<< pointer->unique() << endl; // true
    // 直接使用reset会消除引用计数
    pointer->reset(); // ok
    cout <<"pointer->use_count(): "<< pointer->use_count() << endl; // 0
    // 这里固定一个变量
    int a = 100; int *pa = &a;
    // 使用2个智能指针指向它
    std::shared_ptr<int> pointer3(pa);
    std::shared_ptr<int> pointer4 = pointer3;
    // 现在再来判断它们是否是唯一的
    // cout <<boolalpha<<"pointer3.unique(): "<< pointer3.unique() << endl; // false
    // 使用use_count()来获取智能指针的引用计数
    cout <<"pointer3.use_count(): "<< pointer3.use_count() << endl; // 2
    // 使用owner_before()判断两个指针是否指向同一对象
    cout <<boolalpha<<"pointer3.owner_before(pointer4): "<< pointer3.owner_before(pointer4) << endl; // true

    // 除了直接构造智能指针也可以使用make_shared()
    auto pointer_ = std::make_shared<int>(10); // 免除了显式的使用new int 10
    foo(pointer_); // 参数是一个智能指针
    cout <<"*pointer_: "<< *pointer_ << endl; // 11,而且解引用后不再是底层指针了而是底层对象,无需双解引用
    return 0;
}