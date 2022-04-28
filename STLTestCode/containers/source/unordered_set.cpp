/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:51:38
 * @LastEditTime: 2022-04-28 16:53:49
 * @Description: test unordered_set<T>
 * @FilePath: \myLeetCode\STLTestCode\containers\source\unordered_set.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\unordered_set_g++ unordered_set.cpp
..\output\unordered_set_g++.exe
cl /Fo"..\output\unordered_set_cl" /Fe"..\output\unordered_set_cl.exe" /std:c++latest ".\unordered_set.cpp"
..\output\unordered_set_cl.exe
*/
#include <iostream>
#include <unordered_set>
#include <iterator>
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
    // unordered_set的构造函数
    unordered_set<int> uset1 = {10,-1,2,4,-5,1}; // 支持列表初始化
    unordered_set<int> uset2(uset1.begin(),uset1.end()); // 支持迭代器初始化
    unordered_set<int> uset3(uset1); // 支持复制构造初始化
    copy(uset3.begin(),uset3.end(),out);// 1 -5 4 2 -1 10 
    cout << endl;
    // 可以使用operator=
    unordered_set<int> uset4 = uset3;

    // 常规函数
    cout<<"uset1.size() = "<<uset1.size()<<endl;
    cout<<"uset1.max_size() = "<<uset1.max_size()<<endl;
    cout<<"uset1.empty() = "<<uset1.empty()<<endl;
    cout<<"uset1.count(1) = "<<uset1.count(1)<<endl;
    cout<<"uset1.count(10) = "<<uset1.count(10)<<endl;
    
    // 使用contains来判断元素是否存在,g++不可,cl可以
    // if(uset1.contains(1))
    // {
    //     cout<<"uset1 contains 1"<<endl;
    // }
    // else
    // {
    //     cout<<"uset1 not contains 1"<<endl;
    // }

    // unordered_set的元素没有排序,不能使用lower_bound和upper_bound,但是可以使用equal_range
    copy(uset1.begin(),uset1.end(),out);
    cout << endl; // 2 10 4 -1 -5 1
    auto er = uset1.equal_range(1);
    // 寻找1时因为在最后,所以下边界存在,上边界不存在
    cout<<"uset1.equal_range(1) = "<<*er.first<<" "<<*er.second<<endl; // 1 4587552
    auto er2 = uset1.equal_range(10);
    // 10的下边界是4,无序的,g++编译会有问题,注释掉
    //cout<<"uset1.equal_range(10) = "<<*er2.first<<" "<<*er2.second<<endl; // 10 4

    // 使用find查找,返回迭代器,不存在返回end
    auto it = uset1.find(1);
    cout<<"uset1.find(1) = "<<*it<<endl; // 1
    auto it2 = uset1.find(15);
    if (it2 == uset1.end())
    {
        cout<<"uset1 not find 15"<<endl;
    }
    else
    {
        cout<<"uset1 find 15"<<endl; // ok
    }

    // 可以使用insert插入,可以直接插入元素,也可以指定迭代器位置插入元素
    // 可以插入{}列表,也可插入迭代器表示的范围
    uset1.insert(12); // 只插入12
    uset1.insert(uset1.begin(),15); // 插入15
    unordered_set<int> uset5 = {31,32};
    uset1.insert(uset5.begin(),uset5.end()); // 插入31,32
    uset1.insert({55,56}); // 插入55,56
    copy(uset1.begin(),uset1.end(),out); 
    cout << endl; // cl : 2 10 12 4 -1 -5 1 15 31 32 55 56/g++: 55 31 32 12 1 -5 56 4 15 2 -1 10
    
    // 使用emplace和emplace_hint插入元素,可以指定迭代器位置插入元素
    auto ue1 = uset1.emplace(18); // 插入18
    std::pair<std::unordered_set<int>::iterator, bool> ue2 = uset1.emplace(19); // 插入19
    cout<<"ue2.first = "<<*ue2.first<<endl; // 19
    cout<<"ue2.second = "<<ue2.second<<endl; // true
    auto ue3 = uset1.emplace_hint(next(uset1.begin(),3),20); // 插入20
    cout<<"ue3 = "<<*ue3<<endl; // 20
    copy(uset1.begin(),uset1.end(),out);
    cout << endl; // 2 10 12 4 -1 -5 1 15 31 32 55 56 18 19 20
    cout<<"for_each : ";
    for_each(uset1.begin(),uset1.end(),[](int i){cout<<i<<" ";});
    cout<<"\n";

    // 删除元素,返回删除的元素个数
    cout<<"uset1.erase(1) = "<<uset1.erase(1)<<endl; // 1
    cout<<"uset1.erase(10) = "<<uset1.erase(10)<<endl; // 1
    // 删除范围内的元素,返回迭代器指向end
    auto ua1 = uset1.erase(next(uset1.begin(),8),uset1.end());
    copy(uset1.begin(),uset1.end(),out);
    cout << endl; // 2 12 4 -1 -5 15 31 32
    //--ua1; // 不支持-,+,++,--在g++也不支持,cl可以
    // cout<<"ua1 = "<<*ua1<<endl; // 32

    // 归并操作支持,但是未必按照顺序插入
    unordered_set<int> uset7 = {1,3,5,7,9};
    unordered_set<int> uset8 = {2,4,6,8,10};
    uset7.merge(uset8);
    copy(uset7.begin(),uset7.end(),out);
    cout << endl; // 9 1 3 5 7 2 10 4 6 8

    // 可以交换
    uset7.swap(uset8);

    uset7.reserve(100); // 分配100个空间

    std::equal_to<int> uskeq = uset7.key_eq(); // 比较函数
    cout<<"uskeq(1,1) = "<<uskeq(1,1)<<endl; // true
    cout<<"uskeq(1,2) = "<<uskeq(1,2)<<endl; // false
    cout<<"uskeq(2,1) = "<<uskeq(2,1)<<endl; // false

    // 提取底层的红黑树节点以及通过move插入回去
    std::unordered_set<int>::node_type ua2 = uset7.extract(1);
    cout<<"ua2.empty() = "<<ua2.empty()<<endl; // false

    unordered_set<int> uset9 = {1,5,7};
    // 提取节点
    std::unordered_set<int>::node_type ua3 = uset9.extract(uset9.begin());
    // 查看ua3属性
    cout<<"ua3.empty() = "<<ua3.empty()<<endl; // false
    cout<<"ua3.value() = "<<ua3.value()<<endl; // 7
    // 交换节点是可以的
    auto ua4 = uset9.extract(5);
    cout<<"ua4.empty() = "<<ua4.empty()<<endl; // false
    cout<<"ua4.value() = "<<ua4.value()<<endl; // 5
    ua3.swap(ua4);
    cout<<"ua3.value() = "<<ua3.value()<<endl; // 5
    copy(uset9.begin(),uset9.end(),out);
    cout << endl; // 1
    // 把2个节点都借助move插入回去
    uset9.insert(std::move(ua3));
    uset9.insert(std::move(ua4));
    copy(uset9.begin(),uset9.end(),out);
    cout << endl; // 7 5 1

    // 还有一些哈希值相关的算法
    // 重新哈希
    uset9.rehash(100);
    cout<<"uset9.size() = "<<uset9.size()<<endl; // 3
    cout<<"uset9.bucket_count() = "<<uset9.bucket_count()<<endl; // 103
    // 计算桶的数量和大小
    cout<<"uset9.bucket(7) = "<<uset9.bucket(7)<<endl; // 7是key
    cout<<"uset9.bucket_size(7) = "<<uset9.bucket_size(7)<<endl; // 1
    cout<<"uset9.bucker_count() = "<<uset9.bucket_count()<<endl; // 103

    cout <<"uset9.bucket(5) = "<<uset9.bucket(5)<<endl; // 5是key
    cout<<"uset9.bucket_size(5) = "<<uset9.bucket_size(5)<<endl; // 1

    // 还可以获取factor
    cout<<"uset9.max_load_factor() = "<<uset9.max_load_factor()<<endl; // 1
    // 直接加载也可以
    cout<<"uset9.load_factor() = "<<uset9.load_factor()<<endl; // 0.0291262

    return 0;
}
