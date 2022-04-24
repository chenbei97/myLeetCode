/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 08:31:34
 * @LastEditTime: 2022-04-24 08:43:57
 * @Description: char.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\char.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
using namespace std;
int main()
{
    char c1 = 'C';//char本质就是int类型
    char c2 = 80;//隐式转换
    char c3 = 0x50;//自动隐式转换
    // c2 = c3

    // c++11
    char16_t c4 = u'陈';//char16_t是一个16位的Unicode字符,必须使用u字面量限定符
    char32_t c5 = U'陈';//char32_t是一个32位的Unicode字符,必须使用U字面量限定符
    
    cout<<"c1 = "<<c1<<endl;
    cout<<"c2 = "<<c2<<endl;
    cout<<"c3 = "<<c3<<endl;
    cout<<"+c1 = "<<+c1<<" +c2 = "<<+c2<<" +c3 = "<<+c3<<endl;
    cout<<"c4 = "<<c4<<endl;
    cout<<"c5 = "<<c5<<endl;
    /*
        c1 = C
        c2 = P
        c3 = P
        +c1 = 67 +c2 = 80 +c3 = 80
        c4 = 38472
        c5 = 38472
    */
    return 0;
}
