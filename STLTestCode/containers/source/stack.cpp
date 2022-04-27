/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:54:11
 * @LastEditTime: 2022-04-27 11:28:54
 * @Description: test stack<T>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\stack.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\stack_g++ stack.cpp
..\output\stack_g++.exe
cl /Fo"..\output\stack_cl" /Fe"..\output\stack_cl.exe" /std:c++latest ".\stack.cpp"
..\output\stack_cl.exe
*/
#include <iostream>
#include <stack>
#include <iterator>
using namespace std;
int main()
{
    // stack是后进先出的结构,和queue不同,但底层借助deque实现
    // push和pop和deque相似,也不支持迭代器
    stack<int> s;
    // stack<int> s = {1,2,3,4,5}; 不支持
    // stack<int> s{1,2,3,4,5}; 不支持
    // stack<int> s(1); 不支持
    // stack<int> s(5,1); 不支持
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // 使用emplace也可以,好处就是避免临时变量
    s.emplace(6);
    s.emplace(7);
    cout<<"s.size() = "<<s.size()<<endl; // 7
    while (!s.empty()){ // 只能借助top和pop和遍历
        cout << s.top() << " ";
        s.pop(); // 7 6 5 4 3 2 1
    }
    cout << endl;
    s.push(5);
    s.push(10);
    // 交换2个栈
    stack<int> s1;
    s1.push(100);
    s1.push(200);
    s.swap(s1);
    cout<<"s.top() = "<<s.top()<<endl; // 200
    cout<<"s1.top() = "<<s1.top()<<endl; // 10

    ostream_iterator<int> out(cout," ");//不支持迭代器操作
    // copy(s.begin(),s.end(),out); 不支持迭代器操作
    return 0;
}