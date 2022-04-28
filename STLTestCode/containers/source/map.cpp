/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:49:10
 * @LastEditTime: 2022-04-28 16:03:02
 * @Description: test map<const k,v>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\map.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\map_g++ map.cpp
..\output\map_g++.exe
cl /Fo"..\output\map_cl" /Fe"..\output\map_cl.exe" /std:c++latest ".\map.cpp"
..\output\map_cl.exe
*/
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
#include <iterator>
#include <assert.h>
using namespace std;
int main()
{
    ostream_iterator<int> out(cout," ");
    // 从构造函数说起
    // map的特点是不能重复，按照插入的顺序排列,unsorted_map不按照插入的顺序排列
    // 支持多种初始化操作
    map<int, string> m1 = {{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"}}; // 列表初始化
    map<int, string> m2 = {}; // 空初始化
    map<int, string> m3(m1.begin(), m1.end()); // 迭代器拷贝初始化
    map<int, string> m4(m1); // 拷贝构造函数初始化
    // map<int, string> m5 = {1,"one",2,"two",3,"three",4,"four",5,"five"}; // 必须有二级{}

    // 支持operator=,但是没有assign()
    map<int, string> m6 = m1; // ok

    // 如果插入相同key，则替换
    m1[1] = "one1";
    m1[2] = "two2";
    m1[3] = "three3";
    m1[4] = "four4";
    m1[5] = "five5";
    m1[6] = "six6";
    m1.at(1) = "one1"; // 使用at和[]都可以访问

    // copy(m1.begin(), m1.end(), out); 不能使用copy,因为是pair类型
    // cout << endl;
    // 可以使用for_each代替遍历map
    for_each(m1.begin(), m1.end(), [](pair<int, string> p){cout << p.first << " " << p.second << endl;}); // ok
    

    // 查找元素,没找到返回end()
    auto it1 = m1.find(1);
    if(it1 != m1.end())
    {
        cout << it1->first << " " << it1->second << endl; // 1 one
    }
    auto it2 = m1.find(6);
    if(it2 == m1.end())
    {
        cout << "not found" << endl; // ok
    }

    // 检查是否包含某个元素,使用count和contains均可
    if(m1.count(1) == 1)
    {
        cout << "found 1" << endl; // ok
    }
    else
    {
        cout << "not found 1" << endl; 
    }
    // 对于contains只能使用cl编译,g++不支持
    // if(m1.contains(10))
    // {
    //     cout << "found 10" << endl; 
    // }
    // else
    // {
    //     cout << "not found 10" << endl; // 0k 
    // }

    // 访问元素可以使用迭代器、at和operator[]
    cout << m1.at(1) << endl; // one1
    cout << m1[1] << endl; // one1
    cout<< m1.begin()->first << " " << m1.begin()->second << endl; // 1 one1

    // 也有上下边界以及范围的操作
    map<int,string> m7 = {{1,"one"},{3,"three"},{5,"five"},{7,"seven"}};
    // 如果存在这个元素,则返回这个元素的迭代器,否则返回end()
    map<int,string>::iterator it3 = m7.lower_bound(1); // 返回第一个大于等于1的元素
    cout << it3->first << " " << it3->second << endl; // 1 one
    map<int,string>::iterator it4 = m7.upper_bound(1); // 返回第一个大于1的元素
    cout << it4->first << " " << it4->second << endl; // 3 three
    // 如果不存在这个元素,但是确实是在范围内
    map<int,string>::iterator it5 = m7.lower_bound(4); // 返回第一个大于等于4的元素
    cout << it5->first << " " << it5->second << endl; // 5 five
    map<int,string>::iterator it6 = m7.upper_bound(4); // 返回第一个大于4的元素
    cout << it6->first << " " << it6->second << endl; // 5 five
    // 如果不存在这个元素且不在范围内,则返回end()
    map<int,string>::iterator it7 = m7.lower_bound(10); // 返回第一个大于等于10的元素
    if(it7 == m7.end())
    {
        cout << "not found" << endl; // ok
    }
    it7 = m7.upper_bound(10); // 返回第一个大于10的元素
    assert(it7 == m7.end()); // ok
    // 找出查找元素的上下边界
    typedef map<int,string>::iterator iterator; // 取个别名方便
    std::pair<iterator, iterator> it8 = m7.equal_range(4); // 返回4的上下边界
    cout << it8.first->first << " " << it8.first->second << endl; // 5 five

    // 常规方法
    cout<<"size: "<<m7.size()<<endl;// 4
    cout<<"empty: "<<m7.empty()<<endl;// false
    cout<<"max_size: "<<m7.max_size()<<endl;// 0
    m7.clear();
    m7.swap(m1);//交换
    for_each(m7.begin(), m7.end(), [](pair<int, string> p){cout << p.first << " " << p.second << endl;}); // ok
    
    // 删除元素
    auto st1 = m7.erase(2); //删除指定key
    auto st2 = m7.erase(next(m7.begin(),4), m7.end()); //删除指定范围
    auto st3 = m7.erase(15); //删除不存在的key
    cout<<"st1 = "<<st1<<endl; // 1
    cout<<"st3 = "<<st3<<endl; // 0
    // cout<<"(*st2).first = "<<(*st2).first<<endl; // 4
    // cout<<"(*st2).second = "<<(*st2).second<<endl; // 好像会乱码,连带着后边全乱码,所以这2行注释掉

    map<int,string> m8;
    // 可以插入元素,insert
    m8.insert(make_pair(1,"one"));
    // 不使用make_pair,可以使用构造函数
    m8.insert(map<int,string>::value_type(2,"two"));
    // 也可以直接使用{}
    m8.insert({{3,"three"},{4,"four"}});//要有二级括号
    // 指定位置也行,但是没有意义
    m8.insert(m8.begin(), make_pair(5,"five"));
    for_each(m8.begin(), m8.end(), [](pair<int, string> p){cout << p.first << " " << p.second << endl;}); // ok

    // 使用emplace插入元素也可以,会返回一个conditional和bool的组合,可以用来判断是否插入成功
    auto it9 = m8.emplace(6, "six");
    auto it9_first = it9.first; 
    int it9_first_first = it9_first->first;
    string it9_first_second = it9_first->second;
    cout<<"it9_first_first = "<<it9_first_first<<endl; // 6
    cout<<"it9_first_second = "<<it9_first_second<<endl; // six
    bool it9_second = it9.second;
    cout<<"it9->second = "<<it9.second<<endl; // 1=true
    // 指定位置插入元素使用emplace_hint
    m8.emplace_hint(m8.begin(), 7, "seven");
    for_each(m8.begin(), m8.end(), [](pair<int, string> p){cout << p.first << " " << p.second << endl;}); // ok

    // try_emplace插入元素,如果key存在,则返回一个pair,其中first是指向key的迭代器,second是false
    // 如果key不存在,则返回一个pair,其中first是指向新插入的元素的迭代器,second是true
    // 插入1个不存在的元素
    auto it10 = m8.try_emplace(8, "eight");
    auto it10_first = it10.first;
    cout<<"it10_first->first = "<<it10_first->first<<endl; // 8
    cout<<"it10_first->second = "<<it10_first->second<<endl; // eight
    bool it10_second = it10.second;
    cout<<"it10_second = "<<it10_second<<endl; // 1=true
    // 插入一个存在的元素
    auto it11 = m8.try_emplace(8, "eight");
    auto it11_first = it11.first;
    cout<<"it11_first->first = "<<it11_first->first<<endl; // 8
    cout<<"it11_first->second = "<<it11_first->second<<endl; // eight
    bool it11_second = it11.second;
    cout<<"it11_second = "<<it11_second<<endl; // 0=false,因为已经存在所以返回false

    // 也可以删除元素,erase
    m8.erase(8);//删除指定key
    m8.erase(m8.begin(), next(m8.begin(),3));//删除指定范围
    
    // 还可以使用insert_or_assign插入元素,如果key存在,则更新元素,如果不存在,则插入元素
    map<int,string> m9;
    m9[1] = "F";
    m9[3] = "B";
    // 现在插入已存在的key,其值会被更新,但是返回的是一个pair,其中first是指向key的迭代器,second是false
    auto it12 = m9.insert_or_assign(1, "A");
    auto it12_first = it12.first;
    cout<<"it12_first->first = "<<it12_first->first<<endl; // 1
    cout<<"it12_first->second = "<<it12_first->second<<endl; // A
    bool it12_second = it12.second;
    cout<<"it12_second = "<<it12_second<<endl; // 0=false,因为已经存在所以返回false
    // 插入不存在的key,其值会被插入,但是返回的是一个pair,其中first是指向新插入的元素的迭代器,second是true
    auto it13 = m9.insert_or_assign(2, "C");
    auto it13_first = it13.first;
    cout<<"it13_first->first = "<<it13_first->first<<endl; // 2
    cout<<"it13_first->second = "<<it13_first->second<<endl; // C
    bool it13_second = it13.second;
    cout<<"it13_second = "<<it13_second<<endl; // 1=true
    // 在以上基础还可以指定位置,不过没有意义
    m9.insert_or_assign(m9.begin(), 3, "D");// D把B挤掉了
    for_each(m9.begin(), m9.end(), [](pair<int, string> p){cout << p.first << " " << p.second << endl;}); // ok

    // map也支持归并,merge
    map<int,string> m10;
    m10[7] = "F";
    m10[9] = "B";
    m10.merge(m9);
    for_each(m10.begin(), m10.end(), [](pair<int, string> p){cout << p.first << " " << p.second << endl;}); // ok
    
    // 底层是红黑树,可以使用extract返回节点
    std::map<int, std::string>::node_type it14 = m10.extract(7);
    cout<<boolalpha<<"it14.empty() = "<<it14.empty()<<endl; // 0=false
    cout<<"it14.key() = "<<it14.key()<<endl; // 7
    cout<<"it14.mapped() = "<<it14.mapped()<<endl; // F
    auto it15 = m10.extract(9);
    it14.swap(it14); // 底层直接交换2个节点也是允许的
    cout<<boolalpha<<"it14.empty() = "<<it14.empty()<<endl; // 0=false
    cout<<"it14.key() = "<<it14.key()<<endl; // 7
    cout<<"it14.mapped() = "<<it14.mapped()<<endl; // F
    // 直接修改节点的key也可以
    it14.key() = 8;
    cout<<"it14.key() = "<<it14.key()<<endl; // 8
    cout<<"it14.mapped() = "<<it14.mapped()<<endl; // F
    for_each(m10.begin(), m10.end(), [](pair<int, string> p){cout << p.first << " " << p.second << endl;}); // ok
    // 1 A 2 C 3 D
    // 借助move插回去
    m10.insert(std::move(it14));
    for_each(m10.begin(), m10.end(), [](pair<int, string> p){cout << p.first << " " << p.second << endl;}); // ok
    // 1 A 2 C 3 D 8 F
    
    // 可以获取key比较器
    auto cmp = m10.key_comp();
    cout<<"cmp(1,2) = "<<cmp(1,2)<<endl; // 0=false
    cout<<"cmp(2,1) = "<<cmp(2,1)<<endl; // 1=true
    cout<<"cmp(1,1) = "<<cmp(1,1)<<endl; // 0=false

    // 可以获取值比较器
    auto cmp2 = m10.value_comp();
    cout<<"cmp2(1,2) = "<<cmp2({1,"1"},{2,"2"})<<endl; // 1=true
    cout<<"cmp2(2,1) = "<<cmp2({2,"2"},{1,"1"})<<endl; // 0=false
    cout<<"cmp2(1,1) = "<<cmp2({1,"1"},{1,"1"})<<endl; // 0=false

    // map也有自己的内存分配器,可以自己指定
    // 直接定义分配这样的内存
    map<int,string,std::less<int>,std::allocator<pair<int,string>>> m11;
    m11[1] = "F";
    m11[3] = "B";

    // 直接使用allocator也可以
    std::allocator<std::pair<int, const char*>> alloc = m10.get_allocator();
    std::pair<int, const char*> * pm = alloc.allocate(5);
    // 直接赋值g++可以,clang++不行
    try {
        for (int i = 0; i < 5; ++i) {
            pm[i] = std::make_pair(i, "A"); // 必须使用const char*,使用string不报错但是不能插入
        }
    } catch (...) {
        alloc.deallocate(pm, 5);
        throw bad_alloc();
    }
    for_each(pm, pm+5, [](pair<int, const char*> p){cout << p.first << " " << p.second << endl;}); // ok

    // 使用构造函数也可以,但是不支持clang++,提示不存在construct
    // for (int i = 0; i < 5; ++i) {
    //     alloc.construct(&pm[i], std::make_pair(i, "B"));
    // }
    // for_each(pm, pm+5, [](pair<int, const char*> p){cout << p.first << " " << p.second << endl;}); // ok

    return 0;
}