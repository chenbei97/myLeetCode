/*** 
 * @Author: chenbei
 * @Date: 2022-04-26 16:46:54
 * @LastEditTime: 2022-04-28 09:00:05
 * @Description: test string
 * @FilePath: \myLeetCode\STLTestCode\containers\source\string.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\string_g++ string.cpp
..\output\string_g++.exe
cl /Fo"..\output\string_cl" /Fe"..\output\string_cl.exe" /std:c++latest ".\string.cpp"
..\output\string_cl.exe
*/
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;
int main()
{
    string s1 = "hello"; // 直接初始化
    string s2 = s1;      // 拷贝初始化
    string s3(10, 'c'); // 初始化为10个c
    cout<<"s3: "<<s3<<endl;
    string s4(s3);      // 拷贝初始化
    string s5{};        // 空初始化
    string s6{10};      // 默认初始化为10个空格
    cout<<"s6:"<<s6<<endl;
    string s7{10, 'c'}; // 初始化为1个c
    cout<<"s7:"<<s7<<endl;
    string s8{'a','b','c'}; // 初始化为3个a,b,c
    cout<<"s8:"<<s8<<endl; // abc
    //string s9('a','b','c'); //小括号不支持这样初始化,只能是(int,char)
    // 使用迭代器初始化也可以
    string s10(s8.begin(), s8.end());
    cout<<"s10:"<<s10<<endl; // s10:abc
    // string有一系列的方法
    string s = "I am sorry for you,hello world!";
    cout<<"s.size(): "<<s.size()<<endl; // s.size(): 32
    cout<<"s.length(): "<<s.length()<<endl; // s.length(): 32
    cout<<"s.capacity(): "<<s.capacity()<<endl; // s.capacity(): 32
    cout<<"s.max_size(): "<<s.max_size()<<endl; // s.max_size(): 2147483647
    cout<<"s.empty(): "<<s.empty()<<endl; // s.empty(): 0
    cout<<"s.data(): "<<s.data()<<endl; // s.data(): I am sorry for you,hello world!

    // 可以[]和at访问字符
    cout<<"s[0] = "<<s[0]<<endl; // 'I'
    cout<<"s.at(0) = "<<s.at(0)<<endl; // 'I'
    // find()返回第一个匹配的字符的位置
    cout<<"s.find('o') = "<<s.find('o')<<endl; // 6
    // 从指定位置之后寻找
    cout<<"s.find('o',6) = "<<s.find('o',7)<<endl; // 12
    // rfind()返回最后一个匹配的字符的位置
    cout<<"s.rfind('o') = "<<s.rfind('o')<<endl; // 26
    // find找不到会返回npos
    cout<<"s.find('z') = "<<s.find('z')<<endl; // npos

    // find_first_of()返回第一个匹配的字符/字符串的位置
    cout<<"s.find_first_of('or') = "<<s.find_first_of("or")<<endl; // 6,字符串也可以

    // find_last_of()返回最后一个匹配的字符/字符串的位置
    cout<<"s.find_last_of('or') = "<<s.find_last_of("or")<<endl; // 27,字符串也可以

    // 找到第1个不是的字符位置
    cout<<"s.find_first_not_of('I') = "<<s.find_first_not_of('I')<<endl; // 1

    // 找到最后一个不是的字符位置
    cout<<"s.find_last_not_of('I') = "<<s.find_last_not_of('I')<<endl; // 30

    // 寻找指定位置开始连续的子串
    cout<<"s.substr(5,5) = "<<s.substr(5,5)<<endl; // "sorry"

    const char* ps = s.c_str(); // 返回一个指向字符串的指针,不能用stirng*接受
    cout<<"c_str: ps = "<<ps<<endl; // I am sorry for you,hello world!

    // 支持复制操作
    string k1 = "c++";
    string k2 = "python";
    // k1.copy(k2.c_str(),3,k2.begin()); // 不支持string,第1个参数必须是char*
    char k3[4] = {};
    size_t st1 = k2.copy(k3,4,2); // 支持string,第1个参数必须是char*(复制目标对象),也不能是const char*,从第2个位置复制4个字符thon给k3
    cout<<"st1 = "<<st1<<endl; // st1 = 4,复制的字符数目
    cout<<"k3 = "<<k3<<endl; // thon€鮛W

    // 检查是否包含指定的字符/字符串
    // cout<<boolalpha<<"s.contains('or') = "<<s.contains("or")<<endl; // true,目前移除了该成员函数
    
    // 是否以指定的字符/字符串开头
    //cout<<boolalpha<<"s.starts_with('I') = "<<s.starts_with("I")<<endl; // true,g++版本没有,cl有

    // 是否以指定的字符/字符串结尾
    //cout<<boolalpha<<"s.ends_with(world!) = "<<s.ends_with("world!")<<endl; // true,g++版本没有,cl有

    // 支持三相比较,取值0,1,-1,默认以长度比较,然后以字符在ASCII表中的位置比较
    cout<<"s.compare(\"I am sorry for you,hello world!\") = "<<s.compare("I am sorry for you,hello world!")<<endl; // 0
    cout<<"s.compare(\"I am sorry for you,hello world!!\") = "<<s.compare("I am sorry for you,hello world!!")<<endl; // -1
    cout<<"s.compare(\"I am sorry for you,hello world\") = "<<s.compare("I am sorry for you,hello world")<<endl; // 1

    // 支持直接+=拼接字符串
    s += " here!";
    cout<<"+= here: "<<s<<endl; // += here: I am sorry for you,hello world! here!
    // 也可以使用append
    s.append(" here!");
    cout<<"append here: "<<s<<endl; // append here: I am sorry for you,hello world! here! here!

    s.clear();// 清空字符串
    s.resize(10);// 设置字符串长度
    s[0] = 'H'; // 可以使用[]访问字符和设置字符
    s[1] = 'e';
    s[2] = 'l';
    s[3] = 'l';
    s[4] = 'o';
    s[5] = '!';
    cout<<"s.size() = "<<s.size()<<endl; // 10

    // 使用reserve()函数可以预留字符串的空间,但是不会改变字符串的长度
    s.reserve(100);
    cout<<"reserve : s.capacity() = "<<s.capacity()<<endl; // 124
    cout<<"reserve : s.size() = "<<s.size()<<endl; // 10
    cout<<"reserve : s.length() = "<<s.length()<<endl; // 10

    // 可以使用shrink_to_fit()减少内存占用,清除的是reserve()预留的空间而不是resize
    s.shrink_to_fit();
    cout<<"shrink_to_fit : s.size() = "<<s.size()<<endl; // 10
    cout<<"shrink_to_fit : s.capacity() = "<<s.capacity()<<endl; // 15
    cout<<"shrink_to_fit : s.length() = "<<s.length()<<endl; // 10

    // 长度和size是不同的
    cout<<"s.length() = "<<s.length()<<endl; // 6

    // 容量和size,length是不同的
    cout<<"s.capacity() = "<<s.capacity()<<endl; //62,capacity()返回的是容量,不是长度也不是size

    // 也可以插入字符串
    s.insert(0, "Hello "); // 插入到指定位置
    cout<<"insert: "<<s<<endl; // insert: Hello Hello!
    // s.insert(s.begin()+5, "world!"); // insert不支持迭代器插入

    // 指定的位置替换字符串
    s.replace(6, 5, "World"); // 替换指定位置的字符串,在第6个位置后替换5个字符
    cout<<"replace: "<<s<<endl; // replace: Hello World!
    
    // resize也可以,只是以指定字符填充多余的位置
    s.resize(20, '!');
    cout<<"size: "<<s.size()<<endl; // size: 20
    cout<<"resize: "<<s<<endl; // Hello World!!!!!

    // 可以擦除指定位置连续的n个字符
    s.erase(6, 5); // 使用参数
    cout<<"erase: "<<s<<endl; // erase: Hello !!!!!
    s.erase(s.begin()+5,s.end()); // 使用迭代器也可以
    cout<<"erase: "<<s<<endl; // erase: Hello,没有空格,左闭右开

    // 还可以进行交换操作
    string h1 = "Hello";
    string h2 = "World";
    h1.swap(h2);
    cout<<"swap: "<<h1<<" "<<h2<<endl; // swap: World Hello

    // 现在来看看字符串的迭代方式
    // 可以基于begin、end、cbegin、cend、rbegin、rend、crbegin、crend这些迭代器进行遍历
    cout<<"begin,end: ";
    string::iterator it = s.begin();
    while(it != s.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl; // H e l l o
    string::const_iterator cit = s.cbegin();
    cout<<"cbegin,cend: ";
    while(cit != s.cend())
    {
        cout<<*cit<<" ";
        ++cit;
    }
    cout<<endl; // H e l l o
    cout<<"rbegin,rend: ";
    string::reverse_iterator rit = s.rbegin();
    while(rit != s.rend())
    {
        cout<<*rit<<" ";
        ++rit;
    }
    cout<<endl; // o l l e h
    // 可以使用for循环进行遍历
    cout<<"for: ";
    for(auto c : s)
    {
        cout<<c<<" ";
    }
    cout<<endl; // H e l l o 
    // 使用for_each进行遍历
    cout<<"for_each: ";
    for_each(s.begin(), s.end(), [](char c){cout<<c<<" ";}); 
    cout<<endl; // H e l l o

    // 现在再说明string和数字类型的转换
    // 可以使用stoi,stol,stoll,stoul,stoull,stof,stod,stold
    // 这些string->number的函数统一都是3个参数
    // 第一个参数是const string&,第二个参数是返回值的类型size_t*p=nullptr,第三个参数是指定的base,int
    int i1 = stoi("123"); // 123,默认base=10
    int i2 = stoi("123", nullptr, 8); // 83,8进制
    int i3 = stoi("123", nullptr, 16); // 291,16进制
    int i4 = stoi("123", nullptr, 2); // 1,2进制
    int i5 = stoi("123", nullptr, 0); // 123,0进制
    cout<<"stoi: "<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<endl; // stoi: 123 83 291 1 123
    long l1 = stol("123"); // 123,默认base=10
    long l2 = stol("123", nullptr, 8); // 83,8进制
    long l3 = stol("123", nullptr, 16); // 291,16进制
    long l4 = stol("123", nullptr, 2); // 1,2进制
    long l5 = stol("123", nullptr, 0); // 123,0进制
    cout<<"stol: "<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<l5<<endl; // stol: 123 83 291 1 123

    long long ll1 = stoll("123"); // 123,默认base=10,同理
    unsigned long ul1 = stoul("123"); // 123,默认base=10,同理
    unsigned long long ull1 = stoull("123"); // 123,默认base=10,同理
    float f1 = stof("123.456"); // 123.456,默认base=10
    double d1 = stod("123.456"); // 123.456,默认base=10
    long double ld1 = stold("123.456"); // 123.456,默认base=10
    cout<<"ll1 = "<<ll1<<" ul1 = "<<ul1<<" ull1 = "
            <<ull1<<" f1 = "<<f1<<" d1 = "<<d1<<" ld1 = "<<ld1<<endl; 
    // ll1 = 123 ul1 = 123 ull1 = 123 f1 = 123.456 d1 = 123.456 ld1 = 123.456

    // 数字也可以转换成字符串
    // to_string,to_wstring
    string s11 = to_string(123); // 123
    string s12 = to_string(123.456); // 123.456
    string s13 = to_string(123.456f); // 123.456
    string s14 = to_string(123.456l); // 123.456
    // string s15 = to_string(123.456ll); // 不支持
    // string s16 = to_string(123.456ul); // 不支持
    // string s17 = to_string(123.456ull); // 不支持
    // string s18 = to_string(123.456u); // 不支持
    string s19 = to_string(123.456L); // 123.456

    // 字节不同,wstring是宽字符,占用2个字节的大小,即16bit,string是窄字符,占用1个字节的大小,即8bit
    // 编码方式不同,wstring是utf-16,string是utf-8
    // 使用不同,使用中文汉字时使用wstring来定义变量进行赋值,使用英文时使用string来定义变量赋值
    wstring s20 = to_wstring(123); // 123

    return 0;
}