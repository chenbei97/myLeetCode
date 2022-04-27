/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:44:51
 * @LastEditTime: 2022-04-27 14:15:48
 * @Description: test list<T>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\list.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\list_g++ list.cpp
..\output\list_g++.exe
cl /Fo"..\output\list_cl" /Fe"..\output\list_cl.exe" /std:c++latest ".\list.cpp"
..\output\list_cl.exe
*/
#include <iostream>
#include <list>
#include <iterator>
using namespace std;
int main()
{
    // list是不连续的内存空间,不支持迭代器
    ostream_iterator<int> out(cout," ");
    list<int> L1 = {1,2,3,4,5};// 支持列表初始化
    list<int> L2{6,7,8,9,10};// 支持构造列表
    list<int> L3(3);// 支持参数构造,1个3
    list<int> L4(3,100);// 支持参数构造,3个100
    list<int> L5(L1.begin(),L1.end());// 支持拷贝构造
    // 也可以直接使用next和迭代器结合
    list<int> L6(next(begin(L1)),end(L1));
    // 支持复制构造
    list<int> L7(L6);
    copy(begin(L7),end(L7),out); // 2 3 4 5
    cout<<endl;

    // 支持operator=和assign与{},迭代器,参数结合
    list<int> L8 = {11,12,13,14,15};
    L8 = L7;
    L8.assign(10,100);
    copy(begin(L8),end(L8),out);
    cout<<endl; // 10个100
    L8.assign(L7.begin(),L7.end());
    L8.assign({100,200,300,400,500});//结合{}

    // 可以使用front,back,begin,end,rbegin,rend来访问元素,不支持[]和at
    cout<<L8.front()<<endl; // 100
    cout<<L8.back()<<endl; // 500
    cout<<*L8.begin()<<endl; // 100
    // cout<<*(L8.begin()+5)<<endl; // 不支持迭代器加减法
    // cout<<*(L8.end()-1)<<endl; // 不支持迭代器加减法
    cout<<*(L8.end())<<endl; // 未定义行为,5
    cout<<*(L8.rbegin())<<endl; // 500
    cout<<*(L8.rend())<<endl; // 未定义行为,5
    // 可以用变量表示begin或者end,可以++,--,可以赋值
    list<int>::iterator it = L8.begin();
    ++it;
    cout<<*it<<endl; // 200
    list<int>::iterator it2 = L8.end();
    --it2;
    cout<<*it2<<endl; // 500
    // rbegin和rend,cbegin,cend同理
    list<int>::reverse_iterator rit = L8.rbegin();
    ++rit;
    cout<<*rit<<endl; // 400
    list<int>::reverse_iterator rit2 = L8.rend();
    --rit2;
    cout<<*rit2<<endl; // 100
    list<int>::const_iterator cit = L8.cbegin();
    ++cit;
    cout<<*cit<<endl; // 200
    list<int>::const_iterator cit2 = L8.cend();
    --cit2;
    cout<<*cit2<<endl; // 500

    cout<<"-----------------------"<<endl;
    // 可以使用一些方法查看属性
    cout<<"L8.size() = "<<L8.size()<<endl;
    cout<<boolalpha<<"L8.empty() = "<<L8.empty()<<endl;
    cout<<"L8.max_size() = "<<L8.max_size()<<endl;
    cout<<"L8.front() = "<<L8.front()<<endl;
    cout<<"L8.back() = "<<L8.back()<<endl;
    cout<<"L8.begin() = "<<*L8.begin()<<endl;
    cout<<"L8.end() = "<<*L8.end()<<endl;
    cout<<"L8.rbegin() = "<<*L8.rbegin()<<endl;
    cout<<"L8.rend() = "<<*L8.rend()<<endl;
    cout<<"L8.cbegin() = "<<*L8.cbegin()<<endl;
    cout<<"L8.cend() = "<<*L8.cend()<<endl;
    cout<<"L8.crbegin() = "<<*L8.crbegin()<<endl;
    cout<<"L8.crend() = "<<*L8.crend()<<endl;

    L8.clear(); // 清空
    cout<<"L8.size() = "<<L8.size()<<endl; // 0
    L8.resize(10); // 改变大小,填充0默认
    cout<<"L8.size() = "<<L8.size()<<endl; // 10
    L8.resize(10,100); // 改变大小,填充100
    cout<<"L8.size() = "<<L8.size()<<endl; // 10
    // 使用shrink_to_fit()减少内存占用,list不支持shrink_to_fit()

    // 可以使用swap来交换两个list
    L8.swap(L1);
    copy(begin(L8),end(L8),out); // 1 2 3 4 5
    cout<<endl;
    copy(begin(L1),end(L1),out); // 0 0 0 0 0 0 0 0 0 0
    cout<<endl;

    L8.sort([](int a, int b){return a>b;}); // 按照大小排序
    copy(begin(L8),end(L8),out); // 5 4 3 2 1
    cout<<endl;
    
    // 还可以反转回来
    L8.reverse();
    copy(begin(L8),end(L8),out); // 1 2 3 4 5
    cout<<endl;

    // L8支持各种插入,头插尾插等
    L8.push_front(100);
    L8.push_back(500);
    L8.emplace_front(1000);
    L8.emplace_back(2000);
    L8.insert(L8.begin(),-100);
    L8.emplace(next(L8.begin()),-10000); 
    list<int> l8 = {1,1,1,1};
    L8.insert(L8.begin(),l8.begin(),l8.end()); // 插入一段序列
    L8.insert(L8.begin(),{-100,-200,-300,-400,-500}); // 插入一段序列
    // 插入指定的几个值也可以
    L8.insert(L8.begin(),5,100);
    copy(begin(L8),end(L8),out);
    cout<<endl; // 100 100 100 100 100 -100 -200 -300 -400 -500 1 1 1 1 -100 -10000 1000 100 1 2 3 4 5 500 2000

    // 可以清除元素,头删、尾删和erase均可
    L8.pop_front();L8.pop_front();L8.pop_front();
    L8.pop_back();L8.pop_back();L8.pop_back();
    L8.erase(L8.begin()); //清除某个位置元素
    // L8.erase(L8.begin()+3); // 不支持+,-,但可以通过next来指定
    copy(begin(L8),end(L8),out); 
    cout<<endl; // 100 -100 -200 -300 -400 -500 1 1 1 1 -100 -10000 1000 100 1 2 3 4
    // 清除某个范围的元素也可以
    L8.erase(L8.begin(),next(L8.begin(),6)); // 清除[begin,begin+6)
    copy(begin(L8),end(L8),out);
    cout<<endl; // 1 1 1 1 -100 -10000 1000 100 1 2 3 4

    // 移除指定元素,和erase不同,不是移除范围内元素,针对value
    L8.remove(1); // 1都被移除
    copy(begin(L8),end(L8),out); // -100 -10000 1000 100 2 3 4
    cout<<endl;

    // 移除满足某个条件的元素也可以
    L8.remove_if([](int x){return x <0;});//移除<0的元素
    copy(begin(L8),end(L8),out); // 1000 100 2 3 4
    cout<<endl;

    // 去重unique也可以,但是不连续的两段是无法去重的
    L8.push_back(1000);L8.push_back(1000);
    L8.push_front(1000);
    L8.push_back(-1);
    L8.push_back(-1);
    L8.push_back(-4);
    L8.push_back(-1);
    L8.push_back(-1);
    copy(begin(L8),end(L8),out);
    cout<<endl; // 1000 1000 100 2 3 4 1000 1000 -1 -1 -4 -1 -1
    L8.unique(); // 去重
    copy(begin(L8),end(L8),out);
    cout<<endl; // 1000 100 2 3 4 1000 -1 -4 -1,可以看出1000,-1,4不相邻所以不是完整的去重

    // 也可以指定去重,例如指定相反数也可以去重
    L8.pop_back();
    L8.push_back(4);
    L8.unique([](int x, int y){return x==-y;});
    copy(begin(L8),end(L8),out);
    cout<<endl; // 1000 100 2 3 4 1000 -1 -4,4与-4一起4就被去重
    // 相加>0的元素也可以去重
    L8.unique([](int x, int y){return x+y>0;});
    copy(begin(L8),end(L8),out);
    cout<<endl; // 1000

    // 串联链表通过splice操作
    list<int> L9 = {1,2,3,4,5};
    L8.splice(L8.begin(),L9); // 将L9的元素插入到L8的开头
    copy(begin(L8),end(L8),out);
    cout<<endl; // 1 2 3 4 5 1000
    // 也可以指定的串联位置和被串联的位置
    list<int> L10 = {6,7,8,9,10};
    // 把L10[begin+2,begin+3]串联到L8[begin+3,end)之间
    L8.splice(next(L8.begin(),3),L10,next(L10.begin(),2),next(L10.begin(),5));
    copy(begin(L8),end(L8),out);
    cout<<endl; // 1 2 3 8 9 10 4 5 1000

    // 还可以进行归并merge,但是需要保证有序
    L8.sort();
    L8.merge(L9);
    L8.merge(L10);
    copy(begin(L8),end(L8),out);
    cout<<endl; // 1 2 3 4 5 6 7 8 9 10 1000
    return 0;
}