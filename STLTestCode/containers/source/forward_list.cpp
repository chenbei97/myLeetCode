/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:45:40
 * @LastEditTime: 2022-04-27 15:33:30
 * @Description: test forward_list<T>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\forward_list.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\forward_list_g++ forward_list.cpp
..\output\forward_list_g++.exe
cl /Fo"..\output\forward_list_cl" /Fe"..\output\forward_list_cl.exe" /std:c++latest ".\forward_list.cpp"
..\output\forward_list_cl.exe
*/
#include <iostream>
#include <forward_list>
#include <iterator>
using namespace std;
int main()
{
    // 和list的区别是只能前向迭代,如果不需要双向迭代器,它更加高效
    // 具备和list相似的大部分性质,但是移除了pop_back,push_back
    forward_list<int> FL1 = {1,2,3,4,5,6,7,8,9,10}; // 可以列表初始化
    forward_list<int> FL2; // 初始化为空
    forward_list<int> FL3(10,100); // 初始化为10个100
    forward_list<int> FL4(FL1.begin(),FL1.end()); // 初始化为FL1的副本
    forward_list<int> FL5(FL1); // 初始化为FL1的副本
    forward_list<int> FL6{1,2,3,4,5,6,7,8,9,10}; // 可以构造列表初始化
    forward_list<int> FL7{}; // 初始化为空
    forward_list<int> FL8 = FL1; // 支持operator=
    FL8.assign(FL1.begin(),FL1.end()); // 支持assign
    FL8.assign(10,100); // 支持assign
    FL8.assign({1,2,3,4,5,6,7,8,9,10}); // 支持assign
    
    // 访问元素支持++,--的迭代器,不支持+,-,
    // 可以使用front,cbegin,cend,begin,end
    // 不能使用[],at
    cout<<"FL8.front() = "<<FL8.front()<<endl;
    //cout<<"FL8.back() = "<<FL8.back()<<endl; // 无back成员
    cout<<"FL8.cbegin() = "<<*FL8.cbegin()<<endl;
    // cout<<"FL8.cend() = "<<*FL8.cend()<<endl; // 语法没有错误,但是没有值
    //cout<<"FL8.rbegin() = "<<*FL8.rbegin()<<endl; // 无此成员
    //cout<<"FL8.rend() = "<<*FL8.rend()<<endl;// 无此成员
    cout<<"FL8.begin() = "<<*FL8.begin()<<endl;
    // cout<<"FL8.end() = "<<*FL8.end()<<endl;// 语法没有错误,但是没有值
    //cout<<"FL8.end()-1 = "<<*(FL8.end()-1)<<endl;//不支持+,-
    forward_list<int>::iterator itEnd = FL8.end();
    //--it; // 前向迭代器,不支持--
    forward_list<int>::iterator itBegin = FL8.begin();
    ++itBegin; // 后向迭代器,支持++
    cout<<"FL8.begin()+1 = "<<*itBegin<<endl; // 这样可以,支持++
    //cout<<"FL8[0] = "<<FL8[0]<<endl; // 不支持[]
    //cout<<"FL8.at(0) = "<<FL8.at(0)<<endl; // 不支持at

    // 新增2个位置迭代器,before_begin,cbefore_begin,但是都在begin之前,没有end之后
    auto itBegin_before = FL8.before_begin(); // 前向迭代器,支持++
    ++itBegin_before; // 前向迭代器,支持++
    *itBegin_before = 100; // 允许赋值
    auto citBegin_before = FL8.cbefore_begin(); // 前向迭代器,支持++
    ++citBegin_before; // 前向迭代器,支持++
    // *citBegin_before = 100; // 不允许赋值
    
    ostream_iterator<int> out(cout," ");
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 100 2 3 4 5 6 7 8 9 10

    // 支持insert_after代替insert
    FL8.insert_after(FL8.begin(),200); // 在begin之后插入200
    FL8.insert_after(next(begin(FL8),2),300); // 在begin之后的2个位置插入300
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 100 200 2 300 3 4 5 6 7 8 9 10
    // 直接插入n个值或者{}括起来的列表也可以
    FL8.insert_after(FL8.begin(),{400,500,600});
    FL8.insert_after(FL8.begin(),3,-1);
    copy(FL8.begin(),FL8.end(),out); 
    cout<<endl;// 100 -1 -1 -1 400 500 600 200 2 300 3 4 5 6 7 8 9 10

    // 使用emplace_after和emplace_front插入元素更有效率,支持2个方向的插入
    FL8.emplace_after(FL8.begin(),1000); // 在begin之后插入1000
    FL8.emplace_front(2000); // 默认在begin之前插入2000
    // FL8.emplace_front(next(FL8.begin(),1),3000); // 在begin之前1个单位插入3000,会报错
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 2000 100 1000 -1 -1 -1 400 500 600 200 2 300 3 4 5 6 7 8 9 10

    // 同样支持删除操作erase_after,pop_front
    FL8.pop_front(); // 删除begin位置的元素2000
    FL8.erase_after(FL8.begin()); // 删除begin之后的元素1000
    FL8.erase_after(next(FL8.begin(),2)); // 删除begin+@之后的1个元素-1
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 100 -1 -1 400 500 600 200 2 300 3 4 5 6 7 8 9 10
    FL8.erase_after(FL8.begin(),next(FL8.begin(),3)); // 删除(begin,begin+3)的2个元素-1,-1
    copy(FL8.begin(),FL8.end(),out); //  100 400 500 600 200 2 300 3 4 5 6 7 8 9 10
    cout<<endl;

    // 可以移除指定元素或者依据条件移除
    FL8.remove(100); // 移除100
    FL8.remove_if([](int i){return i<10;}); // 移除小于10的元素
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 400 500 600 200 300 10

    // 去重操作也是可以的
    FL8.insert_after(FL8.begin(),400); // 在begin之后插入400
    FL8.unique(); // 去重,400被移除
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 400 500 600 200 300 10
    // 依据条件去重
    FL8.unique([](int i,int j){return i<j;}); // 去重,不按顺序的元素
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 400 200 10,比400大的500,500被移除,比200大的300,300被移除,比10大的被移除

    // 支持反转
    FL8.reverse(); // 反转
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 10 200 400

    // 支持排序,要求降序
    FL8.sort(greater<int>()); // 降序
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 400 200 10

    // 支持归并,前提有序
    forward_list<int> FL9{9,8,7,6,5,4,3,2,1,0};
    FL8.merge(FL9,less_equal<int>()); // 升序合并
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 9 8 7 6 5 4 3 2 1 0 400 200 10

    // 常见的方法移除了size
    // cout <<"size: "<<FL8.size()<<endl; // 没有size成员
    cout<<"max_size: "<<FL8.max_size()<<endl; // 最大容量
    FL8.clear(); // 清空
    cout<<boolalpha<<"empty: "<<FL8.empty()<<endl; // true
    FL8.resize(10); // 扩容,默认以0填充
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl;// 0 0 0 0 0 0 0 0 0 0

    FL8.clear(); // 清空
    FL8.push_front(10); // 在begin位置插入10,如果是空的splice_after无法插入元素
    forward_list<int> FL10{10,9,8,7,6,5,4,3,2,1};
    FL8.splice_after(FL8.begin(),FL10,FL10.begin()); // 将FL10的begin位置的元素插入到FL8的begin位置
    // 也可以串接范围内的元素
    FL8.splice_after(FL8.begin(),FL10,next(FL10.begin(),2),next(FL10.begin(),5)); // 将FL10的(begin+2,begin+5)之间的元素插入到FL8的begin位置
    copy(FL8.begin(),FL8.end(),out);
    cout<<endl; // 10 6 5 9

    // forward_list有自己的内存分配器,但是也是很少用
    auto alloc = forward_list<int>::allocator_type(); // 同样是_Alloc的别名
    int * p  = alloc.allocate(10); // 分配10个元素的内存
    for (int i=0;i<10;i++) p[i] = i; // 初始化
    forward_list<int> FL11(p,p+10); // 初始化
    alloc.deallocate(p,10); // 释放内存
    // 如果forward_list的元素是指针,那么也需要释放内存
    copy(FL11.begin(),FL11.end(),out);
    cout<<endl; // 0 1 2 3 4 5 6 7 8 9
    return 0;
}