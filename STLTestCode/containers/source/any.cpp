/*** 
 * @Author: chenbei
 * @Date: 2022-04-29 11:36:11
 * @LastEditTime: 2022-04-29 11:47:37
 * @Description: test for any
 * @FilePath: \myLeetCode\STLTestCode\containers\source\any.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\any_g++ any.cpp
..\output\any_g++.exe
cl /Fo"..\output\any_cl" /Fe"..\output\any_cl.exe" /std:c++latest ".\any.cpp"
..\output\any_cl.exe
*/
#include <iostream>
#include <vector>
#include <any>
using namespace std;
int main()
{
    // 定义一个变量来存放任意类型的数据
    // 可以存储任意类型的数据
    // 可以插入任意类型的数据
    // 可以进行交换
    // 可以判断是否为空
    // 可以赋值
    // 可以获取数据
    // 可以获取数据的类型

    vector<any> v;
    v.push_back(1);
    v.push_back(2.0);
    v.push_back("hello");
    for (auto &i : v)
    {
        cout<<"i.has_value() = "<<i.has_value()<<endl;
        cout << "i.type() = " << i.type().name() << endl;
        /*
            i.has_value() = 1
            i.type() = int
            i.has_value() = 1
            i.type() = double
            i.has_value() = 1
            i.type() = char const * __ptr64
        */
    }
    // 访问any修饰的容器,需要这样的迭代器和类型转换
    vector<any>::iterator it = v.begin();
    while (it != v.end())
    {
        if (it->type() == typeid(int))
        {
            cout << "int = " << any_cast<int>(*it) << endl; // 1
        }
        else if (it->type() == typeid(double))
        {
            cout << "double = " << any_cast<double>(*it) << endl; // 2
        }
        else if (it->type() == typeid(const char *))
        {
            cout << "char * = " << any_cast<const char *>(*it) << endl; // hello
        }
        it++;
    }

    // 使用any_of函数来判断是否包含某个类型的数据,g++和cl都不能编译可能是移除了
    // if (any_of(v.begin(), v.end(), [](const any &i) { return i.type() == typeid(int); }))
    // {
    //     cout << "int is in v" << endl;
    // }

    // 可以使用make_any函数来创建一个any对象
    any c1 = make_any<int>(1);
    any c2 = make_any<double>(2.0);
    any c3 = make_any<const char *>("hello");

    // 配合类型转换来输出any对象的数据
    cout<<any_cast<int>(c1)<<endl;
    cout<<any_cast<double>(c2)<<endl;
    cout<<any_cast<const char *>(c3)<<endl;

    // 可以使用重置函数来重置any对象
    c1.reset();
    cout<<"c1.type() = "<<c1.type().name()<<endl;// c1.type() = void
    cout<<"c1.has_value() = "<<c1.has_value()<<endl;// c1.has_value() = 0

    c1.emplace<string>("hello");
    cout<<"c1.type() = "<<c1.type().name()<<endl;// c1.type() = string
    cout<<"c1.has_value() = "<<c1.has_value()<<endl;// c1.has_value() = 1
    return 0;
}