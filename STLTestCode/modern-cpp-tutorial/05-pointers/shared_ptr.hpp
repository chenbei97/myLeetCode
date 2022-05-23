/*** 
 * @Author: chenbei
 * @Date: 2022-05-23 08:55:29
 * @LastEditTime: 2022-05-23 09:06:17
 * @Description: shared_ptr.hpp
 * @FilePath: \myLeetCode\STLTestCode\modern-cpp-tutorial\05-pointers\shared_ptr.hpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <memory>
// std::shared_ptr能够记录多少个 shared_ptr共同指向一个对象，从而消除显式的调用 delete
// 当引用计数变为零的时候就会将对象自动删除，但还不够，因为使用 std::shared_ptr 仍然需要使用 new 来调用
// std::make_shared 就能够用来消除显式的使用 new
void foo_shared_ptr(std::shared_ptr<int> i) {
    (*i)++;
}

// std::shared_ptr 可以通过 get() 方法来获取原始指针
// 通过 reset() 来减少一个引用计数， 并通过use_count()来查看一个对象的引用计数
void test_shared_ptr_api(){
    auto pointer = std::make_shared<int>(10);
    auto pointer2 = pointer; // 引用计数+1
    auto pointer3 = pointer; // 引用计数+1
    int *p = pointer.get(); // 这样不会增加引用计数,获取原始指针
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 3
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3

    pointer2.reset();
    std::cout << "reset pointer2:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 2
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0, pointer2 已 reset
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2
    
    pointer3.reset();
    std::cout << "reset pointer3:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 1
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 0, pointer3 已 reset
}
void test_shared_ptr(){
    // auto pointer = new int(10); // illegal, no direct assignment
    // Constructed a std::shared_ptr
    auto pointer = std::make_shared<int>(10); // 使用make_shared避免显示调用new
    foo_shared_ptr(pointer);
    std::cout << *pointer << std::endl; // 11
    // The shared_ptr will be destructed before leaving the scope

    test_shared_ptr_api();
}