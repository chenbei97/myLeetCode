/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 08:48:47
 * @LastEditTime: 2022-05-23 09:22:49
 * @Description: pointers.cpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\05-pointers\pointers.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o pointers -std=c++20 pointers.cpp
.\pointers
*/
#include <iostream>
#include <vector>
#include "shared_ptr.hpp"
#include "unique_ptr.hpp"
#include "weak_ptr.hpp"
using namespace std;
int main()
{
    /*
        C++11 引入智能指针的概念，使用引用计数的想法，让程序员不再需要关心手动释放内存
        这些智能指针包括 std::shared_ptr/std::unique_ptr/std::weak_ptr，使用它们需要包含头文件 <memory>
        注意：引用计数不是垃圾回收，引用计数能尽快收回不再被使用的对象，回收过程不会造成长时间的等待，能够清晰明确的表明资源的生命周期。
        1. std::shared_ptr
        std::shared_ptr能够记录多少个 shared_ptr共同指向一个对象，从而消除显式的调用 delete
        当引用计数变为零的时候就会将对象自动删除，但还不够，因为使用 std::shared_ptr 仍然需要使用 new 来调用
        std::make_shared 就能够用来消除显式的使用 new
        std::shared_ptr 可以通过 get() 方法来获取原始指针
        通过 reset() 来减少一个引用计数， 并通过use_count()来查看一个对象的引用计数
        2. std::unique_ptr
        std::unique_ptr 是一种独占的智能指针，它禁止其他智能指针与其共享同一个对象，从而保证代码的安全
        std::unique_ptr<int> pointer = std::make_unique<int>(10); // make_unique 从 C++14 引入
        std::unique_ptr<int> pointer2 = pointer; // 非法
        既然是独占，换句话说就是不可复制。但是，我们可以利用 std::move 将其转移给其他的 unique_ptr
        3. std::weak_ptr 
        仔细思考 std::shared_ptr 就会发现依然存在着资源无法释放的问题
        std::weak_ptr 没有 * 运算符和 -> 运算符，所以不能够对资源进行操作，它可以用于检查 std::shared_ptr 是否存在
        expired() 方法能在资源未被释放时，会返回 false，否则返回 true
        除此之外，它也可以用于获取指向原始对象的 std::shared_ptr 指针
        其 lock() 方法在原始对象未被释放时，返回一个指向原始对象的 std::shared_ptr 指针，进而访问原始对象的资源，否则返回nullptr
    */
    test_shared_ptr();
    test_unique_ptr();
    test_weak_ptr();
    return 0;
}