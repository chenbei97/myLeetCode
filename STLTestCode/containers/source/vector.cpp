/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 14:36:18
 * @LastEditTime: 2022-04-26 15:15:38
 * @Description: test vector<T>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\vector.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\vector_g++ vector.cpp
..\output\vector_g++.exe
// 注意这里不能使用cl.exe编译,因为swap_ranges找不到标识符,应该是只限于c++11
cl /Fo"..\output\vector_cl" /Fe"..\output\vector_cl.exe" /std:c++14 ".\vector.cpp"
..\output\vector_cl.exe
*/
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {1,2,3,4,5};
    // 可以使用begin和end来访问vector
    cout<<"src.begin() = "<<*src.begin()<<endl; // 1
    cout<<"src.end()-1 = "<<*(src.end()-1)<<endl; // 5
    // 可以使用at来访问vector
    cout<<"src.at(1) = "<<src.at(1)<<endl; // 2
    // 用[]来访问vector
    cout<<"src[1] = "<<src[1]<<endl; // 2
    // vector的一些方法
    cout<<"src.size() = "<<src.size()<<endl; // 5
    cout<<"src.max_size() = "<<src.max_size()<<endl; // 4294967295
    cout<<"src.capacity() = "<<src.capacity()<<endl; // 5
    cout<<boolalpha<<"src.empty() = "<<src.empty()<<endl; // 0
    cout<<"src.front() = "<<src.front()<<endl; // 1
    cout<<"src.back() = "<<src.back()<<endl; // 5
    // 可以使用push_back来添加元素
    src.push_back(6);
    // 倒序遍历vector
    for(auto it = src.rbegin(); it != src.rend(); it++)
    {
        cout<<*it<<" "; // 6 5 4 3 2 1
    }
    cout<<endl;
    // 可以使用pop_back来删除元素
    src.pop_back();
    // 使用const迭代器遍历vector
    vector<int>::const_iterator cit = src.cbegin();
    while(cit != src.cend())
    {
        cout<<*cit<<" ";
        cit++;
    } // 1 2 3 4 5
    cout<<endl;
    // 可以插入元素,例如头插
    src.insert(src.begin(), 0); // 提供一个迭代器和一个值
    src.insert(begin(src)+3,-1);// 使用begin函数也可以
    src.insert(end(src),{7,8,9});// 直接插入一段序列也可以,使用{}
    vector<int> tmp = {10,11,12};
    src.insert(end(src),tmp.begin(),tmp.end());// 使用迭代器插入也可
    src.insert(end(src),5,13);// 插入连续的5个13

    // emplace没有中间变量,比insert快
    // emplace_back是插入元素,但是不提供迭代器
    src.emplace_back(7);
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 0 1 2 -1 3 4 5 7 8 9 10 11 12 13 13 13 13 13 7

    // emplace是插入元素,需要提供迭代器
    src.emplace(src.begin(), 0);
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 0 0 1 2 -1 3 4 5 7 8 9 10 11 12 13 13 13 13 13 7

    // 还可以使用erase来删除元素
    src.erase(src.begin());
    src.erase(src.begin()+1);
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 0 2 -1 3 4 5 7 8 9 10 11 12 13 13 13 13 13 7

    // 使用clear来清空vector
    src.clear();

    // 使用assign或者直接赋值
    src.assign({1,2,3,4,5});
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 1 2 3 4 5
    src = tmp;
    src = {6,7,8,9,10};
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 6 7 8 9 10

    // 可以使用resize来重新设置大小
    // 如果大小比原来的大,则后面的元素被初始化为默认值
    // 如果大小比原来的小,则后面的元素被删除
    src.resize(3);
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 6 7 8
    src.resize(10,11);
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 6 7 8 11 11 11 11 11 11 11
    
    // 检查一下目前的vector容量
    cout<<"src.capacity() = "<<src.capacity()<<endl; // 20
    // 使用reserve来重新设置容量,预留出一些空间
    src.reserve(30);
    cout<<"src.capacity() = "<<src.capacity()<<endl; // 30

    // 可以使用shrink_to_fit来释放不必要的空间
    src.shrink_to_fit();
    cout<<"src.capacity() = "<<src.capacity()<<endl; // 10

    // 可以使用swap来交换两个vector
    vector<int> tmp2 = {1,2,3,4,5};
    swap(src, tmp2);
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 1 2 3 4 5
    copy(tmp2.begin(), tmp2.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 6 7 8 11 11 11 11 11 11 11
    src.swap(tmp2); // 再交换回来
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 6 7 8 11 11 11 11 11 11 11
    tmp2.swap(src); // 再交换回来

    // 可以使用move来交换两个vector,但是效率比swap高
    vector<int> tmp3 = {100,200,300,400,500};
    move(src.begin(), src.end(), tmp3.begin());
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 1 2 3 4 5 , 注意不是100,200,300,400,500,因为move没有拷贝
    copy(tmp3.begin(), tmp3.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 1,2,3,4,5

    // 可以使用swap_ranges来交换两个迭代器所指向的元素
    vector<int> tmp4 = {-5,-4,-3,-2,-1};
    swap_ranges(src.begin(), src.end(), tmp4.begin());
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // -5,-4,-3,-2,-1
    copy(tmp4.begin(), tmp4.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 1,2,3,4,5

    // get_allocator()返回一个内存分配器,默认为allocator<T>
    allocator<int> alloc = src.get_allocator();
    int * p = alloc.allocate(1); // 分配一个int类型的内存
    // 对分配的内存进行初始化
    *p = 100;
    cout<<"*p = "<<*p<<endl; // 100

    // 还可以分配数组空间内存
    int * p2 = alloc.allocate(10);
    for(int i = 0; i < 10; i++)
        p2[i] = i;
    copy(p2, p2+10, ostream_iterator<int>(cout, " "));
    cout<<endl; // 0 1 2 3 4 5 6 7 8 9

    // 分配内存后,需要释放
    alloc.deallocate(p, 1);
    alloc.deallocate(p2, 10);

    // 可以使用vector的内存分配器来分配内存
    vector<int, allocator<int>> v(10);
    for(int i = 0; i < 10; i++)
        v[i] = i;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout<<endl; // 0 1 2 3 4 5 6 7 8 9

    // 使用这个内存分配器的好处是,容器内的元素不会被访问
    // 同时访问以及修改他们都是安全的,不会出现越界的问题
    // 复制任何实例化的默认构造器也不会抛出异常,而是自动处理
    return 0;
}