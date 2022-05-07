/*
cd STLTestCode\\yushiqi
g++ -o strcpy strcpy.cpp
./strcpy
*/
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    // 函数原型是: char* strcpy(char* dst, const char* src);
    // 更安全的方法是使用strncpy,其原型为: char* strncpy(char* dst, const char* src, size_t n);
    // 其中n是字符串的长度
    char a1[] = {'a','b','c','d','e','f','\0'};
    char a2[10];
    strcpy(a2,a1); // 不安全的方法
    char a3[10];
    strncpy(a3,a1,sizeof(a1)-2); // 安全的方法,sizeof记住包含了\0
    cout<<"a2 = "<<a2<<endl; // abcdef
    cout<<"a3 = "<<a3<<endl; // abcde

    // 类似的函数拼接和比较
    // strcat的原型为: char* strcat(char* dst, const char* src);
    // strcmp的原型为: int strcmp(const char* s1, const char* s2);
    // strncmp的原型为: int strncmp(const char* s1, const char* s2, size_t n);
    // strcoll的原型为: int strcoll(const char* s1, const char* s2);
    // strncoll的原型为: int strncoll(const char* s1, const char* s2, size_t n);
    char a4[] = {'a','b','c','d','e','f','\0'};
    strcat(a4,a1); // 把a1拼接到a4后面
    cout<<"a4 = "<<a4<<endl; // abcdefabcdef

    // 字符串比较
    char a5[] = {'a','b','c','d','e','f','\0'};
    char a6[] = {'a','b','c','d','e','f','\0'};
    int cmp = strcmp(a5,a6); // 比较a5和a6的大小,返回值为0表示相等,大于0表示a5大于a6,小于0表示a5小于a6
    cout<<"cmp = "<<cmp<<endl; // 0
    // 更安全的方式
    int cmp2 = strncmp(a5,a6,sizeof(a5)-2); // 比较a5和a6的大小,返回值为0表示相等,大于0表示a5大于a6,小于0表示a5小于a6
    cout<<"cmp2 = "<<cmp2<<endl; // 0
    return 0;
}