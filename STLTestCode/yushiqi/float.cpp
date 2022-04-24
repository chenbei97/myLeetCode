/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 08:45:03
 * @LastEditTime: 2022-04-24 08:56:04
 * @Description: float.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\float.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <iomanip> // include setprecision
using namespace std;
int main()
{
    float f1 = 1.2f;//f避免隐式转换double->float
    float f2 = f1 * 1000000000000000;
    cout<<"f1 = "<<std::fixed<<std::setprecision(15)<<f1<<endl;
    cout<<"f2 = "<<std::fixed<<std::setprecision(15)<<f2<<endl;
    /*
        可以看出是存在精度的,因为2^32/2^64个数字无法表示[0,1]内无穷多的数字
        只能选取具有代表性的采样点,这些采样点的数值是有限的,可以通过精度来控制
        靠近某个采样点就会返回这个采样点的数值,这样就可以控制精度
        f1 = 1.200000047683716
        f2 = 1200000038076416.000000000000000
    */
    float f3 = f2 + 10;
    cout<<std::boolalpha<<(f3 == f2)<<endl; // true
    // 故判断是否相等时,两个数之差小于某个阈值时就认为相等
    if (f3 == f2) cout<<"f3 == f2"<<endl; // bad f3 == f2
    if (abs(f3 - f2) < 0.0000001) cout<<"f3 == f2"<<endl; // good f3 == f2
    return 0;
}