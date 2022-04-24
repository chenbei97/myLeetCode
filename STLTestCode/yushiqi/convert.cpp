/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 08:58:22
 * @LastEditTime: 2022-04-24 09:06:45
 * @Description: convert.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\convert.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
using namespace std;
int main()
{
    unsigned char a = 255;
    unsigned char b = 1;
    int c1 = a + b ;
    unsigned int c2 = a + b ;
    unsigned char c3 = a + b ;
    cout<<"c1 = "<<c1<<endl; // 256
    cout<<"c2 = "<<c2<<endl; // 256
    cout<<"c3 = "<<c3<<endl; // 没有结果,直接溢出
    return 0;
}