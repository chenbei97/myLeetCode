/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 08:45:57
 * @LastEditTime: 2022-04-26 09:49:09
 * @Description: test string_view.cpp
 * @FilePath: \myLeetCode\STLTestCode\other\source\string_view.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\string_view string_view.cpp
..\output\string_view.exe
cl /Fo"..\output\sv" /Fe"..\output\sv.exe" /std:c++latest ".\string_view.cpp"
..\output\sv.exe
*/
#include <iostream>
// #include <string_view>
#include <vector>
#include <iterator>
#include <string>
using namespace std;
void f_cref(const string&s){
    cout << s << endl;
}
void f_view(string_view s){
    cout << s << endl;
}
int main()
{
    // 可以不包含string_view头文件
    // 复制成本低,支持引用传递
    // 不为分配和释放内存负责,只是提供了一个视图
    // 可以用于查找字符串,比如查找字符串中的字符,不改变原有字符串,只读
    // 必须是连续的范围,const char*,vector<char>,string都可以
    const char* s1 = "hello world! hello c++!";
    string_view sv1(s1);
    ostream_iterator<char> out(cout," ");
    copy(sv1.begin(),sv1.end(),out);
    cout << endl;

    vector<char> v1 = {'h','e','l','l','o',' ','w','o','r','l','d','!',' ','h','e','l','l','o',' ','c','+','+','!'};
    string_view sv2(v1.data(),v1.size());
    copy(sv2.begin(),sv2.end(),out);
    cout << endl;

    string s2 = "hello world! hello c++!";
    string_view sv3(s2);
    copy(sv3.begin(),sv3.end(),out);
    cout << endl;

    // 拥有类似容器的方法,操作
    cout <<"sv1.size() = " << sv1.size() << endl;
    cout <<"sv1.length() = " << sv1.length() << endl;
    cout <<"sv1.empty() = " << sv1.empty() << endl;
    cout <<"sv1.data() = " << sv1.data() << endl;
    cout <<"sv1.front() = " << sv1.front() << endl;
    cout <<"sv1.back() = " << sv1.back() << endl;
    cout <<"sv1.substr(0,5) = " << sv1.substr(0,5) << endl;
    //cout<<boolalpha<<"sv1.contains(h)"<< sv1.contains("h") << endl; //c++23才有
    // cout<<boolalpha<<"sv1.start_with(hello) = "<< sv1.starts_with("hello") << endl; // 用cl.exe可以
    // cout<<boolalpha<<"sv1.end_with(world) = "<< sv1.ends_with("world") << endl; // 用cl.exe可以

    // 找到从前开始第一个匹配的字符
    cout <<"sv1.find('l') = " << sv1.find('l') << endl;
    cout <<"sv1.find('l',1) = " << sv1.find('l',1) << endl; //第2个参数要求找大于该索引的匹配字符
    // 从后开始找第一个匹配的字符
    cout <<"sv1.rfind('l') = " << sv1.rfind('l') << endl;
    cout <<"sv1.rfind('l',8) = " << sv1.rfind('l',8) << endl; //第2个参数要求找大于该索引的匹配字符
    // 没找到返回string::npos
    cout <<"sv1.find('k') = " << sv1.find('k') << endl; // 返回一个很大的数 18446744073709551615

    // 找到指定字符串内的字符第一次出现的位置
    cout <<"sv1.find_first_of('a!k') = " << sv1.find_first_of("a!k") << endl;
    // 找到指定字符串内的字符最后一次出现的位置
    cout <<"sv1.find_last_of('a!k') = " << sv1.find_last_of("a!k") << endl;

    // 还支持三向比较运算符
    cout<<"sv1.compare(hello world! hello c++!)"<< sv1.compare("hello world! hello c++!") << endl; // = 0
    cout<<"sv1.compare(hello world! hello c++)"<< sv1.compare("hello world! hello c++") << endl; // 1
    cout<<"sv1.compare(hello world! hello c++!!)"<< sv1.compare("hello world! hello c++!!") << endl;// -1

    // 移除字符串中的字符
    // 从后移除指定个数的字符
    sv1.remove_suffix(5); // hello world! hello
    cout <<"sv1.remove_suffix(5) = " << sv1 << endl;
    // 再移除钱边指定的字符6个
    sv1.remove_prefix(6); // world! hello
    cout <<"sv1.remove_prefix(6) = " << sv1 << endl;

    // 最主要的好处是视图无需临时变量复制,可以直接操作
    string a1 = "c++";
    const char* a2 = "b++";
    vector<char> a3 = {'d','+','+'};
    f_cref(a1);// no copy
    f_cref(a2);// temp copy
    f_cref({begin(a3),end(a3)});// temp copy
    f_cref("k++");// temp copy

    f_view(a1);// no copy
    f_view(a2);// no copy
    f_view({begin(a1),end(a1)});// no copy g++不能运行
    f_view("k++");// no copy

    // 很容易传递子序列不需要copy
    f_view({begin(a1)+1,end(a1)-1});// no copy g++不能运行

    // 支持字面量sv
    using namespace std::string_view_literals;
    auto literal_view = "hello world!"sv;
    cout <<"literal_view = " << literal_view << endl;

    // 要注意的是构造不分配内存,因为临时变量已经被销毁
    string_view sv4{string{"Text"}};
    cout <<"sv4 = " << sv4 << endl;// string对象已经被销毁,但是还能输出不知道啥原因😂,但是cl打印的是ext,g++是text
    return 0;
}