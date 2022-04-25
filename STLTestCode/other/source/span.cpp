/*** 
 * @Author: chenbei
 * @Date: 2022-04-25 13:38:40
 * @LastEditTime: 2022-04-25 16:41:56
 * @Description: test span.cpp
 * @FilePath: \myLeetCode\STLTestCode\other\source\span.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\span span.cpp
..\output\span.exe
不再使用上述命令,因为msys2不支持c++20
可以在VS运行此程序
或者使用cl.exe命令行编译,如何配置可见STLTestCode/readme.txt,前提已经装了VS Studio
必须支持最新的c++20,可以编译span.cpp
cl /Fo"..\output\span" /Fe"..\output\span.exe" /std:c++latest ".\span.cpp"
..\output\span.exe

总的运行结果如下：
1 2 3 4 5 6 7 8 9 10
size: 6
front: 3
back: 8
data: 00000143D3A15818
empty: false
begin: 3
end-1: 8
iterator iteration list: 7 8
straight iteration list: 3 4 5 6 7 8
5 6 7
1 2 3 4 5 6 7 8 9 10
2 3 4
2 3 4 5 6 7 8 9
6 7 8 9 10
*/
#include <iostream>
#include <vector>
#include <span>
#include <iterator>
using namespace std;
void print(span<int const> s) { // const表明不能改变元素值
    for (auto& i : s) cout << i << " ";
    cout << "\n";
}
int main()
{
    // 必须包含span头文件
    vector<int> src = { 1,2,3,4,5,6,7,8,9,10 };
    for (auto &i : src) cout << i << " ";
    cout << "\n";
    // 创建一个span对象
    span<int> sp(src.begin() + 2, src.begin()+8);
    // span拥有类似容器的属性和方法
    cout << "size: " << sp.size() << endl; // size: 6
    cout << "front: " << sp.front() << endl; // front: 3
    cout << "back: " << sp.back() << endl; // back: 8
    cout << "data: " << sp.data() << endl; // data: 00000232FB4E92D8
    cout << boolalpha << "empty: " << sp.empty() << endl;// empty: false
    cout << "begin: " << *sp.begin() << endl; // begin: 3
    cout << "end-1: " << *(sp.end() - 1) << endl; //end-1: 8
    // 也具备迭代器
    cout << "iterator iteration list: ";
    span<int>::iterator it1 = sp.first(5).begin();// first必须有参数
    span<int> ::iterator it2 = sp.last(2).begin(); // last必须有参数
    while (it2 != sp.last(2).end())
    {
        cout << *it2 << " ";
        ++it2; // 迭代器遍历 7,8
    }
    cout << endl;
    // 直接遍历也可以
    cout << "straight iteration list: ";
    for (auto& item : sp)
    {
        cout << item << " "; // 3,4,5,6,7,8
    }
    cout << endl;

    // 对span再取子集也可以
    auto k = sp.subspan(2, 3);//起始+长度
    for (auto& i : k) cout << i << " "; // 5 6 7
    cout << "\n";

    // 还可以作为函数参数,例如打印函数,注意不能是引用类型的参数span<int const> &
    print(src); //s1 2 3 4 5 6 7 8 9 10
    print({ begin(src) + 1,3 }); // 2 3 4
    print({ begin(src) + 1,end(src)-1}); // 2 3 4 5 6 7 8 9

    // 其它构造函数
    span<int, 5> s1(src.begin()+5,5);
    for (auto& i : s1) cout << i << " ";
    cout << endl;
    return 0;
}