/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:43:17
 * @LastEditTime: 2022-04-27 09:07:00
 * @Description: test deque<T>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\deque.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\deque_g++ deque.cpp
..\output\deque_g++.exe
cl /Fo"..\output\deque_cl" /Fe"..\output\deque_cl.exe" /std:c++latest ".\deque.cpp"
..\output\deque_cl.exe
*/
#include <iostream>
#include <deque>
#include <iterator>
using namespace std;
int main()
{
    // deque是底层实现,双端队列,实现了queue单端队列的功能
    // deque支持迭代器,支持插入和删除,队首和队尾都可以插入和删除
    // queue不支持迭代器,只支持插入和删除,队首不可以删除,队尾可以插入和删除,先进先出
    // stack不支持迭代器,删除的是栈顶元素,后进先出
    
    // deque的迭代器用法,可以用begin和end来访问与构造新队列
    deque<int> d1{1,2,3,4,5,6,7,8,9};
    cout<<"d1 begin: "<<*d1.begin()<<endl;
    cout<<"d1 end: "<<*d1.end()<<endl;
    // 构造新队列
    deque<int> d2(d1.begin()+2,d1.end());
    // 拷贝构造
    deque<int> d3(d1); // 深拷贝
    // 指定n个元素构造
    deque<int> d4(10,1); // 10个1

    // 支持赋值运算,assign和operator=
    deque<int> d5 = d4; // 浅拷贝
    ostream_iterator<int> out(cout," ");
    cout<<"d5: ";
    copy(d5.begin(),d5.end(),out);
    cout<<endl; //  1 1 1 1 1 1 1 1 1 1
    // 使用assign,结合{}和迭代器,或者n个value
    d5.assign(10,2);
    cout<<"d5: ";
    copy(d5.begin(),d5.end(),out);
    cout<<endl; // 2 2 2 2 2 2 2 2 2 2
    d5.assign(d1.begin(),d1.end());
    cout<<"d5: ";
    copy(d5.begin(),d5.end(),out);
    cout<<endl; // 1 2 3 4 5 6 7 8 9
    d5.assign({-1,-2,-3,-4,-5});
    cout<<"d5: ";
    copy(d5.begin(),d5.end(),out);
    cout<<endl;// -1 -2 -3 -4 -5

    // 访问除了使用迭代器外也可以使用[],front和back,以及at,支持写入
    cout<<"d5[0]: "<<d5[0]<<endl; // -1
    cout<<"d5.front(): "<<d5.front()<<endl; // -1
    cout<<"d5.back(): "<<d5.back()<<endl; // -5
    cout<<"d5.at(0): "<<d5.at(0)<<endl; // -1
    // 支持写入
    d5[0] = -6;
    copy(d5.begin(),d5.end(),out);
    cout<<endl; // -6 -2 -3 -4 -5
    
    // 现在展示deque的一些方法
    cout<<"d5.size(): "<<d5.size()<<endl; // 5
    cout<<boolalpha<<"d5.empty(): "<<d5.empty()<<endl; // false
    cout<<"d5.max_size(): "<<d5.max_size()<<endl; // 9
    cout<<"clear d5"<<endl;
    d5.clear();
    cout<<"d5.size(): "<<d5.size()<<endl; // 0

    // 现在调整size
    d5.resize(10); // 将size调整为10,但是没有变量,所以全部为0
    copy(d5.begin(),d5.end(),out);
    cout<<endl;// 0 0 0 0 0 0 0 0 0 0
    // 指定元素也可以
    d5.resize(12,2);// 将size调整为5,所以后边的元素全部为2
    copy(d5.begin(),d5.end(),out);
    cout<<endl;// 0 0 0 0 0 0 0 0 0 0 2 2
    // 将size调整为5,第6个元素及以后都被忽略
    d5.resize(5);
    copy(d5.begin(),d5.end(),out);
    cout<<endl; // 0,0,0,0,0

    // 可以交换两个deque
    d5.swap(d1); 
    copy(d5.begin(),d5.end(),out);
    cout<<endl; // 1,2,3,4,5,6,7,8,9

    // 可以插入元素
    d5.insert(d5.begin(),-1); // 在开头位置插入-1
    d5.push_back(10); // 尾部插入10
    d5.push_front(-2);// 也可以头插
    // insert可以插入一段序列,使用{}或迭代器表示或指定插入n个元素
    d5.insert(d5.begin()+2,d4.begin(),d4.end());
    d5.insert(d5.end(),{-6,-7,-8});
    d5.insert(d5.begin(),3,100);//插入3个100
    // 使用emplace_back,emplace_front,emplace效率更高
    d5.emplace_back(1000);
    d5.emplace_front(-1000);
    d5.emplace(d5.begin()+2,2000);
    copy(d5.begin(),d5.end(),out);
    cout<<endl; 
    // -1000 100 2000 100 100 -2 -1 1 1 1 1 1 1 1 1 1 1 1 2 3 4 5 6 7 8 9 10 -6 -7 -8 1000

    // 可以删除元素,借助头删遍历删除前17个元素
    for(int i=0;i<17;i++)
        d5.pop_front();
    // 借助普通迭代器遍历打印元素
    for (auto it = d5.begin();it!=d5.end();it++)
        cout<<*it<<" ";
    cout<<endl; // 1 2 3 4 5 6 7 8 9 10 -6 -7 -8 1000
    // 借助尾删遍历删除后4个元素
    for(int i=0;i<4;i++)
        d5.pop_back();
    // 借助const迭代器遍历打印元素
    deque<int>::const_iterator cit = d5.cbegin();
    while(cit!=d5.cend())
        cout<<*cit++<<" ";
    cout<<endl; // 1 2 3 4 5 6 7 8 9 10
    // 借助erase删除后5个元素
    d5.erase(d5.begin(),d5.begin()+5);// 注意删除的是2个参数之间的元素,左闭右开
    // 反向迭代器遍历元素
    deque<int>::reverse_iterator rit = d5.rbegin();
    while(rit!=d5.rend())
        cout<<*rit++<<" ";
    cout<<endl; // 10 9 8 7 6
    
    // 申请和释放不必要的内存
    deque<int> d6(20); // 申请20个内存
    d6[0] = -1;
    d6[1] = -2;
    cout<<"d6.size(): "<<d6.size()<<endl; // 20
    d6.shrink_to_fit(); // 释放不必要的内存
    cout<<"d6.size(): "<<d6.size()<<endl; // 20,不起作用
    // 需要配合resize使用
    d6.resize(2);
    d6.shrink_to_fit();
    cout<<"d6.size(): "<<d6.size()<<endl; // 2

    // 也有自己的内存分配器
    auto alloc = deque<int>::allocator_type();//其实是_Alloc的别名
    auto p = alloc.allocate(10); // 申请10个内存
    for (int i=0;i<10;i++) p[i] = i;
    deque<int> d7(p,p+10); // 将p指向的内存构造成deque
    for (int i=0;i<10;i++) cout<<d7[i]<<" ";
    cout<<endl; // 0 1 2 3 4 5 6 7 8 9
    alloc.deallocate(p,10); // 记得释放内存
    
    // 申请string类型的deque
    auto str_alloc = string::allocator_type();
    auto p_str = str_alloc.allocate(10); // 是个char*指针,但是自动移除了const属性
    for (int i=0;i<10;i++) p_str[i] = 'a'+i;
    copy(p_str,p_str+10,out);
    cout<<endl; // a b c d e f g h i j/97 98 99 100 101 102 103 104 105 106

    return 0;
}