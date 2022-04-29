/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:52:24
 * @LastEditTime: 2022-04-29 09:37:15
 * @Description: test unordered_map<T>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\unordered_map.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\unordered_map_g++ unordered_map.cpp
..\output\unordered_map_g++.exe
cl /Fo"..\output\unordered_map_cl" /Fe"..\output\unordered_map_cl.exe" /std:c++latest ".\unordered_map.cpp"
..\output\unordered_map_cl.exe
*/
#include <iostream>
#include <unordered_map>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ostream_iterator<int> out(cout," ");
    /*
        unordered_map的底层是一个防冗余的哈希表,map一般采用红黑树(RB Tree) 实现
        构造函数上,unordered_map 需要hash函数,等于函数
        map只需要比较函数(小于函数),unordered_map查找速度比 map 快
        查找速度基本和数据数据量大小无关，属于常数级别
        而map 的查找速度是 log(n) 级别
        考虑效率使用hash_map，考虑内存使用map
    */

   // unordered_map的几种构造函数
    unordered_map<string,int> m1; // 默认构造函数
    unordered_map<string,int> m2(10); // 带有默认值的构造函数,指定分配内存
    cout<<"m2.bucket_count() = "<<m2.bucket_count()<<endl; // 11
    cout<<"m2.max_bucket_count() = "<<m2.max_bucket_count()<<endl; // 164703072086692425
    cout<<"m2.load_factor() = "<<m2.load_factor()<<endl; // 0.0
    cout<<"m2.max_load_factor() = "<<m2.max_load_factor()<<endl; // 1
    // 现在对m2赋值就有一些变化了,可以使用[]赋值,但是不支持at赋值,但是可以访问
    m2["A"] = 1;
    m2["B"] = 2;
    m2["C"] = 3;
    // 不支持at赋值
    // m2.at("D") = 4;  // std::out_of_range,直接terminate了
    // m2.at("E") = 5; // std::out_of_range,直接terminate了
    // 但是at可以访问
    cout<<"m2.at(\"A\") = "<<m2.at("A")<<endl; // 1
    cout<<"m2.at(\"B\") = "<<m2.at("B")<<endl; // 2
    // 也不支持直接迭代器赋值
    // const string sf = "F";
    // next(m2.begin(),5)->first = sf; 不支持这种操作
    // next(m2.begin(),5)["F"] = 6; 不支持这种操作
    // next(m2.begin(),5)->second = 6; // 编译ok,但是下方不能遍历了
    // 但是可以迭代器访问
    cout<<"m2.begin()+1->first = "<<next(m2.begin(),1)->first<<endl; // B
    cout<<"m2.begin()+1->second = "<<next(m2.begin(),1)->second<<endl; // 2
    // 遍历结果是无序的 C 3 B 2 A 1
    for_each(m2.begin(),m2.end(),[](pair<string,int> p){cout<<p.first<<" "<<p.second<<endl;});
    
    // 再看看此时bucket_count(),max_bucket_count(),load_factor(),max_load_factor()
    // 只有load_factor()发生变化,因为11个内存有3个使用,3/11=0.272727
    cout<<"m2.bucket_count() = "<<m2.bucket_count()<<endl; // 11
    cout<<"m2.max_bucket_count() = "<<m2.max_bucket_count()<<endl; // 164703072086692425
    cout<<"m2.load_factor() = "<<m2.load_factor()<<endl; // 0.272727
    cout<<"m2.max_load_factor() = "<<m2.max_load_factor()<<endl; // 1

    // 回到开始的构造函数，还可以使用{},迭代器等初始化，也支持复制构造和等式赋值
    unordered_map<string,int> m3 = {{"A",1},{"B",2},{"C",3}}; // 必须有二级{}
    unordered_map<string,int> m4 = m3;
    unordered_map<string,int> m5(m3);
    unordered_map<string,int> m6(m3.begin(),m3.end());// ok

    // 类似的因为无序,也没有了上界、下届lower_bound、upper_bound函数,equal_range函数依然保留
    auto it1 = m6.equal_range("A"); // 寻找第一个大于等于A的元素
    cout<<"it1.first->first = "<<it1.first->first<<endl; // A
    cout<<"it1.first->second = "<<it1.first->second<<endl; // 1
    cout<<"it1.second->first = "<<it1.second->first<<endl; // C
    cout<<"it1.second->second = "<<it1.second->second<<endl; // 3

    // 可以使用find查找元素,不存在返回end()
    auto it2 = m6.find("A");
    cout<<"it2->first = "<<it2->first<<endl; // A
    cout<<"it2->second = "<<it2->second<<endl; // 1
    auto it3 = m6.find("D");
    if (it3 == m6.end())
    {
        cout<<"it3 not found"<<endl; // ok
    }
    else
    {
        cout<<"it3 found"<<endl;
    }

    // 可以使用contains和count查找元素,不存在返回0
    // 其中contains依然不支持g++,cl可以
    cout<<"m6.contains(\"A\") = "<<m6.contains("A")<<endl; // true,g++不支持
    cout<<"m6.count(1) = "<<m6.count("A")<<endl; // 1

    // 再来说明常规具备的方法,empty,size,max_size,clear,swap,merge,key_eq,reserve等
    cout<<"m6.empty() = "<<m6.empty()<<endl; // false
    cout<<"m6.size() = "<<m6.size()<<endl; // 3
    cout<<"m6.max_size() = "<<m6.max_size()<<endl; // 329406144173384850
    m6.clear();
    cout<<"m6.empty() = "<<m6.empty()<<endl; // true
    m6.swap(m3); // 和m3交换
    cout<<"m6.size() = "<<m6.size()<<endl; // 3
    // key_eq是比较器
    std::equal_to<std::string> comp = m6.key_eq();
    cout<<"comp(\"A\",\"A\") = "<<comp("A","A")<<endl; // true
    cout<<"comp(\"A\",\"B\") = "<<comp("A","B")<<endl; // false
    cout<<"comp(\"B\",\"A\") = "<<comp("B","A")<<endl; // false
    // 可以使用reserve来设置容量
    m6.reserve(10); // = rehash(ceil(n / max_load_factor())) = rehash(ceil(3 / 1)) = rehash(3)
    cout<<"m6.size() = "<<m6.size()<<endl; // 3
    cout<<"m6.bucket_count() = "<<m6.bucket_count()<<endl; // 16,可以体现容量,rehash后变成16
    // 归并merge也可以
    unordered_map<string,int> m7 = {{"X",20},{"Y",21},{"Z",22}};
    m6.merge(m7);
    // X，Y，Z，A，C，B 没有按照顺序
    for_each(m6.begin(),m6.end(),[](pair<string,int> p){cout<<p.first<<" "<<p.second<<endl;});

    // 现在再来看看insert、emplace、emplace_int、insert_or_assign等
    // insert支持多种插入方式,并且返回插入的结果一般不需要关心
    m6.insert({"A",10}); // 如果已经存在,则替换
    m6.insert({"D",4}); // 如果不存在,则插入
    // 指定迭代器位置插入也可
    m6.insert(m6.begin(),{"E",5});
    // 使用emplace效率高，emplace_hint支持指定位置
    m6.emplace("F",6);
    m6.emplace_hint(m6.begin(),"G",7); // 注意不要带{}
    // insert_or_assign和insert的区别是,insert_or_assign只有在不存在的情况下才插入
    std::pair<std::unordered_map<std::string, int>::iterator, bool> it4 = m6.insert_or_assign("A",11); // 如果已经存在,则替换
    // it4.second = false,表示插入失败,但是会覆盖;或者插入成功为true
    // it4.first->second = 11
    cout<<"it4.second = "<<it4.second<<endl; // false
    std::unordered_map<std::string, int>::iterator it4first = it4.first;
    cout <<"it4first->first = "<<it4first->first<<endl; // A
    cout <<"it4first->second = "<<it4first->second<<endl; // 11
    // try_emplace和emplace_hint的区别是,try_emplace只有在不存在的情况下才插入,和insert_or_assign一样
    std::pair<std::unordered_map<std::string, int>::iterator, bool> it5 = m6.try_emplace("A",12); // 如果已经存在,则不插入
    cout<<"it5.second = "<<it5.second<<endl; // false
    std::unordered_map<std::string, int>::iterator it5first = it5.first;
    cout <<"it5first->first = "<<it5first->first<<endl; // A
    cout <<"it5first->second = "<<it5first->second<<endl; // 11

    // 可以使用erase删除元素
    m6.erase("A");
    m6.erase(m6.begin());
    m6.erase(m6.begin(),m6.end());
    cout<<"m6.size() = "<<m6.size()<<endl; // 0

    // 重新哈希和reserve的作用差不多,但是计算方式不同
    m6.reserve(10);
    cout<<"m6.bucket_count() = "<<m6.bucket_count()<<endl; // 11
    // 可以使用rehash来重新哈希
    m6.rehash(100);
    cout<<"m6.bucket_count() = "<<m6.bucket_count()<<endl; // 103

    unordered_map<string,int> m8 = {{"A",10},{"B",20},{"C",30},{"D",40},{"E",50}};
    // 底层是红黑树，也可以得到节点
    std::unordered_map<std::string, int>::node_type it6 = m8.extract("A");
    // 具备empty,key,mapped
    cout<<"it6.empty() = "<<it6.empty()<<endl; // false
    cout<<"it6.key() = "<<it6.key()<<endl; // A
    cout<<"it6.mapped() = "<<it6.mapped()<<endl; // 10
    auto it7 = m8.extract("B");
    cout<<"it7.empty() = "<<it7.empty()<<endl; // true
    // 可以交换2个节点
    it6.swap(it7);
    // E D C
    for_each(m8.begin(),m8.end(),[](pair<string,int> p){cout<<p.first<<" "<<p.second<<endl;});
    // 把2个节点以move方式插回去
    m8.insert(std::move(it6));
    m8.insert(std::move(it7));
    for_each(m8.begin(),m8.end(),[](pair<string,int> p){cout<<p.first<<" "<<p.second<<endl;});
    
    // 拥有自己的内存分配器
    std::allocator<std::pair<const char*, int>> alloc = m8.get_allocator();
    std::pair<const char*, int> * it9 = alloc.allocate(10);
    // 直接赋值即可
    for (int i = 0; i < 10; i++) {
        it9[i] = std::make_pair("A",i);
    }
    for_each(it9,it9+10,[](pair<const char*, int> p){cout<<p.first<<" "<<p.second<<endl;});

    // 可以使用deallocate释放内存
    alloc.deallocate(it9,10);
    return 0;
}