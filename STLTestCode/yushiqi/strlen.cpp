/*
cd STLTestCode\\yushiqi
g++ -o strlen strlen.cpp
./strlen
*/
#include <iostream>
#include <string.h> // include strlen
using namespace std;
int main()
{
    // strlen的输入是const char*,返回是size_t
    // sizeof不是函数会把\0也算进去
    // strlen是函数,会排除\0
    char a1[] = {'a','b','c','d','e','f','\0'};
    cout<<"sizeof(a1) = "<<sizeof(a1)<<endl; // 7
    cout<<"strlen(a1) = "<<strlen(a1)<<endl; // 6
    cout<<"sizeof(a1)/sizeof(a1[0]) = "<<sizeof(a1)/sizeof(a1[0])<<endl; // 7

    // 再看看宽字符类型
    wchar_t a2[] = {L'a',L'b',L'c',L'd',L'e',L'f',L'\0'};
    cout<<"sizeof(a2) = "<<sizeof(a2)<<endl; // 14,2个字节
    // cout<<"strlen(a2) = "<<strlen(a2)<<endl; // 宽字符不能用strlen
    cout<<"wcslen(a2) = "<<wcslen(a2)<<endl; // 6,这个计算的是宽字符的长度
    cout<<"sizeof(a2)/sizeof(a2[0]) = "<<sizeof(a2)/sizeof(a2[0])<<endl; // 7，会把\0也算进去

    // 16位的字符类型
    char16_t a3[] = {u'a',u'b',u'c',u'd',u'e',u'f',u'\0'};
    cout<<"sizeof(a3) = "<<sizeof(a3)<<endl; // 14 ,2个字节
    // cout<<"strlen(a3) = "<<strlen(a3)<<endl; // 16位的字符类型不能用strlen
    cout<<"sizeof(a3)/sizeof(a3[0]) = "<<sizeof(a3)/sizeof(a3[0])<<endl; // 7，会把\0也算进去

    // 32位的字符类型
    char32_t a4[] = {U'a',U'b',U'c',U'd',U'e',U'f',U'\0'};
    cout<<"sizeof(a4) = "<<sizeof(a4)<<endl; // 16,4个字节
    // cout<<"strlen(a4) = "<<strlen(a4)<<endl; // 32位的字符类型不能用strlen
    cout<<"sizeof(a4)/sizeof(a4[0]) = "<<sizeof(a4)/sizeof(a4[0])<<endl; // 7，会把\0也算进去
    return 0;
}