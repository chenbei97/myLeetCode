/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:55:24
 * @LastEditTime: 2022-04-27 11:21:00
 * @Description: test queue<T>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\queue.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\queue_g++ queue.cpp
..\output\queue_g++.exe
cl /Fo"..\output\queue_cl" /Fe"..\output\queue_cl.exe" /std:c++latest ".\queue.cpp"
..\output\queue_cl.exe
*/
#include <iostream>
// #include <deque>
#include <queue>
#include <iterator>
using namespace std;
int main()
{
    // queue是deque的一个派生类,先进先出的数据结构,不支持迭代器
    // 具有和deque相似的方法,但是没有push_back和pop_front,取代的是push和pop
    // queue<int> q = {1,2,3,4,5}; // 不支持列表初始化
    // queue<int> q{1,2,3,4,5};// 不支持构造列表
    // queue<int> q(5); // 不支持参数构造
    // queue<int> q(5,1); // 不支持参数构造
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    queue<int> q2 = q; // 可以operator=
    queue<int> q3(q); // 可以复制构造 
    ostream_iterator<int> out(cout," ");
    // copy(q.begin(),q.end(),out); 不支持迭代器
    // for (auto i : q) // 也不支持基于范围的遍历,需要迭代器
    // {
    //     cout << i << " ";
    // }
    // 想要访问queue的元素,需要借助pop和front实现
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop(); // 1,2,3
    }
    cout << endl;

    // 可以使用emplace插入元素
    q.emplace(4);
    q.emplace(5);
    q.emplace(6);

    // 可以使用front和back来访问队列的头部和尾部元素
    cout <<"q.front() = " << q.front() << endl; // 4
    cout <<"q.back() = " << q.back() << endl; // 6
    // // 可以使用empty和size来判断队列是否为空
    cout <<boolalpha<<"q.empty() = " << q.empty() << endl; // false
    cout <<"q.size() = " << q.size() << endl; // 3
    // 可以使用swap来交换两个队列
    queue<int> q4;
    q4.emplace(7);
    q4.emplace(8);
    q4.emplace(9);
    q.swap(q4);
    cout <<"q.front() = " << q.front() << endl; // 7
    cout <<"q.back() = " << q.back() << endl;// 9
    return 0;
}