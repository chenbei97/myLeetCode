/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:48:45
 * @LastEditTime: 2022-04-28 13:39:26
 * @Description: test set<T>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\set.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\set_g++ set.cpp
..\output\set_g++.exe
cl /Fo"..\output\set_cl" /Fe"..\output\set_cl.exe" /std:c++latest ".\set.cpp"
..\output\set_cl.exe
*/
#include <iostream>
#include <set>
#include <iterator>
#include <string>
using namespace std;
int main()
{
    ostream_iterator<int> out(cout," ");
    
    // set的特点是不能重复，按照插入的顺序排列,unsorted_set不按照插入的顺序排列
    // 支持多种初始化操作
    set<int> s1 = {1, 2, 3, 4, 5}; // 列表初始化
    set<int> s2 = {}; // 空初始化
    set<int> s3(s1.begin(), s1.end()); // 迭代器拷贝初始化
    set<int> s4(s1); // 拷贝初始化
    // 需要注意的是即使初始化是无序的,set也会自动排序,重复的去重
    set<int> s5 = {3,-2,2,1,4,5,2};
    copy(s5.begin(), s5.end(), out);
    cout << endl; // -2 1 2 3 4 5 
    
    // 支持operator=,但是没有assign方法
    set<int> s6 = s5;
    copy(s6.begin(), s6.end(), out);
    cout << endl; // -2 1 2 3 4 5

    // 可以验证某个元素是否存在
    cout << boolalpha<<"s5.count(2) = " << s5.count(2) << endl; // 1
    cout << boolalpha<<"s5.count(6) = " << s5.count(6) << endl; // 0
    // 使用contains也可以,不过g++不支持,cl可以编译
    // cout << boolalpha<<"s5.contains(2) = " << s5.contains(2) << endl; // true
    // cout << boolalpha<<"s5.contains(6) = " << s5.contains(6) << endl; // false

    // 可以查找1个元素,找到返回指向元素的迭代器,找不到返回end()
    auto it1 = s5.find(2);
    if (it1 != s5.end())
    {
        cout << "s5.find(2) = " << *it1 << endl; // s5.find(2) = 2
    }
    else
    {
        cout << "s5.find(2) = not found" << endl;
    }
    auto it2 = s5.find(6);
    if (it2 != s5.end())
    {
        cout << "s5.find(6) = " << *it2 << endl; // not found
    }
    else
    {
        cout << "s5.find(6) = not found" << endl; // s5.find(6) = not found
    }

    // 可以查找某个元素的上下边界
    set<int> s7 = {1,3,5,7};
    auto it3 = s7.lower_bound(4);
    auto it4 = s7.upper_bound(4);
    // 如果查找元素在某2个元素之间,下边界和上边界返回的都是上边界
    cout << "s7.lower_bound(4) = " << *it3 << endl; // s7.lower_bound(4) = 5
    cout << "s7.upper_bound(4) = " << *it4 << endl; // s7.upper_bound(4) = 5
    // 如果查找的元素存在,下边界就是自己,上边界就是下一个元素
    auto it5 = s7.lower_bound(5);
    auto it6 = s7.upper_bound(5);
    cout << "s7.lower_bound(5) = " << *it5 << endl; // s7.lower_bound(5) = 5
    cout << "s7.upper_bound(5) = " << *it6 << endl; // s7.upper_bound(5) = 7

    // equal_range返回一个pair,first是下边界,second是上边界
    // 如果查找的元素不存在,返回pair(end(),end())
    auto it7 = s7.equal_range(5);
    cout << "s7.equal_range(5) = " << *it7.first << " " << *it7.second << endl; // s7.equal_range(5) = 5 7
    auto it8 = s7.equal_range(6);
    cout << "s7.equal_range(6) = " << *it8.first << " " << *it8.second << endl; // s7.equal_range(6) = 7 7
    auto it9 = s7.equal_range(7);
    cout << "s7.equal_range(7) = " << *it9.first << " " << (it9.second==s7.end()?"not found":to_string(*it9.second)) << endl; // s7.equal_range(7) = 7 not found    
    auto it10 = s7.equal_range(8);
    cout << "s7.equal_range(8) = " << (it10.first==s7.end()?"not found":to_string(*it10.first)) 
        << " " <<(it10.second==s7.end()? "not found":to_string(*it10.second)) << endl; // s7.equal_range(8) = not found not found

    // 常规方法clear,size,empty,swap都是存在的
    s7.clear();
    cout << "s7.size() = " << s7.size() << endl; // s7.size() = 0
    cout<<"s7.max_size() = "<<s7.max_size()<<endl; // s7.max_size() = 230584300921369395
    cout << "s7.empty() = " << boolalpha << s7.empty() << endl; // s7.empty() = true
    s7.swap(s5);
    copy(s7.begin(), s7.end(), out);
    cout << endl; // -2 1 2 3 4 5

    // 可以插入insert
    s7.insert(2); // 如果插入的元素存在,不会改变原来的set
    s7.insert(6); // 
    // 指定插入位置也可以
    s7.insert(s7.begin(), 8); // 但是指定位置没用
    copy(s7.begin(), s7.end(), out);
    cout << endl; // -2 1 2 3 4 5 8
    // 一次性插入{}列表也可以
    s7.insert({9,11});
    // 插入迭代器划定的范围也可以
    set<int> tmp = {12,14,16};
    s7.insert(tmp.begin(), tmp.end());
    copy(s7.begin(), s7.end(), out);
    cout << endl; // -2 1 2 3 4 5 8 9 11 12 14 16

    // 使用emplace插入元素,如果插入的元素存在,不会改变原来的set,而且会返回指向元素的迭代器
    auto it11 = s7.emplace(10);
    auto it12 = s7.emplace_hint(next(s7.begin(),3),13);
    copy(s7.begin(), s7.end(), out);
    cout << endl; // -2 1 2 3 4 5 8 9 11 12 14 16 10 13
    cout << "s7.emplace(10) = " << *it11.first <<boolalpha<<" "<<it11.second<< endl; // s7.emplace(10) = 10 true
    // emplace_hint插入位置指定,返回的迭代器也是指向插入位置的,但是没有bool值
    cout << "s7.emplace_hint(next(s7.begin(),3),13) = " << *it12<<endl; // s7.emplace_hint(next(s7.begin(),3),13) = 13 

    // 可以删除erase
    s7.erase(16);//指定删除元素
    s7.erase(next(s7.begin(),3)); // 删除排在第三的元素2
    s7.erase(s7.begin(), next(s7.begin(),3)); // 删除排在第一个元素到第三个元素-2,1,3
    copy(s7.begin(), s7.end(), out);
    cout << endl; // 4 5 6 8 9 10 11 12 13 14

    // 如果不是删除,只是去除也可以,使用extract
    // 返回的node_type
    set<int>::node_type it13 = s7.extract(8); // 因为set内部使用红黑树实现,所以返回的是node_type
    cout<<"node_type = "<<it13.value()<<endl; // node_type = 8
    cout<<"nod empty = "<<it13.empty()<<endl; // nod empty = false
    // 可以借助move把节点再插回去
    s7.insert(move(it13));

    // 支持3种迭代器遍历方式
    // 可以使用begin,end,cbegin,cend,rbegin,rend,crbegin,crend
    auto itbegin = s7.begin();
    auto itend = s7.end();
    while (itbegin != itend) {
        cout << *itbegin << " ";
        ++itbegin;
    }
    cout << endl; // 4 5 6 8 9 10 11 12 13 14

    set<int>::const_iterator citbegin = s7.cbegin();
    set<int>::const_iterator citend = s7.cend();
    while (citbegin != citend) {
        cout << *citbegin << " ";
        ++citbegin;
    }
    cout << endl; // 4 5 6 8 9 10 11 12 13 14

    set<int>::reverse_iterator ritbegin = s7.rbegin();
    set<int>::reverse_iterator ritend = s7.rend();
    while (ritbegin != ritend) {
        cout << *ritbegin << " ";
        ++ritbegin;
    }
    cout << endl; // 14 12 11 10 9 8 6 5 4

    less<int> compare = s7.key_comp(); // 直接返回比较器,要求必须是升序的
    cout << "compare(1,2) = " << compare(1,2) << endl; // compare = true,1<2
    cout << "compare(2,1) = " << compare(2,1) << endl; // compare = false,2>1
    cout << "compare(1,1) = " << compare(1,1) << endl; // compare = false,1=1

    // 和key是一样的,这是因为set可以具体化为pair类型,两个都是自动升序排序的
    less<int> comp = s7.value_comp(); // 返回值比较器,要求必须是升序的
    cout << "comp(1,2) = " << comp(1,2) << endl; // comp = true,1<2
    cout << "comp(2,1) = " << comp(2,1) << endl; // comp = false,2>1
    cout << "comp(1,1) = " << comp(1,1) << endl; // comp = false,1=1

    // 还可以交换swap
    set<int> s8 = {1,2,3,4,5,6,7,8,9,10};
    s7.swap(s8);
    copy(s7.begin(), s7.end(), out);
    cout << endl; // 1,2,3,4,5,6,7,8,9,10

    // 也可以进行归并,因为自动已经有序
    set<int> k1 = {1,3,5,7,9};
    set<int> k2 = {2,4,6,8,10};
    k1.merge(k2);
    copy(k1.begin(), k1.end(), out);
    cout << endl; // 1,2,3,4,5,6,7,8,9,10

    // set也有自己的内存分配器
    // 可以使用allocator_type来获取内存分配器
    set<pair<string,int>> s;
    std::allocator<pair<string,int>> alloc;
    alloc = s.get_allocator();
    cout << "allocator_type = " << typeid(alloc).name() << endl; 
    // allocator_type = class std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, int>>
    pair<string,int> *ps;
    ps = alloc.allocate(10); // 分配内存
    // set支持使用构造函数,g++可以编译,cl不行
    // for (int i = 0; i < 10; ++i) {
    //     alloc.construct(ps+i, make_pair("hello",i)); 
    // }
    // for (int i = 0; i < 10; ++i) {
    //     cout << ps[i].first << " " << ps[i].second << endl;
    // }
    // cout<<endl;

    //也可以直接初始化
    for (int i = 0; i < 10; ++i) {
        ps[i] = make_pair(to_string('a'+i+1),i+1); 
    }
    for (int i = 0; i < 10; ++i) {
        cout << ps[i].first << " " << ps[i].second << endl;
    }
    cout<<endl;

    // 同理cl.exe不能编译
    // for (int i = 0; i < 10; ++i) {
    //     alloc.destroy(ps+i); // set可以使用析构函数了
    // }

    alloc.deallocate(ps,10); // 清除内存
    return 0;
}