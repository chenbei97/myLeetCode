/*** 
 * @Author: chenbei
 * @Date: 2022-04-29 13:20:50
 * @LastEditTime: 2022-04-29 13:32:49
 * @Description: test numeric_limits
 * @FilePath: \myLeetCode\STLTestCode\numeric\source\numeric_limits.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\numeric_limits_g++ numeric_limits.cpp
..\output\numeric_limits_g++.exe
cl /Fo"..\output\numeric_limits_cl" /Fe"..\output\numeric_limits_cl.exe" /std:c++latest ".\numeric_limits.cpp"
..\output\numeric_limits_cl.exe
*/
#include <iostream>
#include <limits> // 使用g++必须包含此头文件,使用cl不需要
using namespace std;
int main()
{   // numeric_limits<T>用于给出各种类型的最大值和最小值
    cout << "numeric_limits<bool>::max() = " << numeric_limits<bool>::max() << endl;
    cout << "numeric_limits<bool>::min() = " << numeric_limits<bool>::min() << endl;
    cout << "numeric_limits<bool>::digits = " << numeric_limits<bool>::digits << endl;
    cout << "numeric_limits<bool>::digits10 = " << numeric_limits<bool>::digits10 << endl;
    cout << "numeric_limits<bool>::is_signed = " << numeric_limits<bool>::is_signed << endl;
    cout << "numeric_limits<bool>::is_integer = " << numeric_limits<bool>::is_integer << endl;
    cout << "numeric_limits<bool>::is_exact = " << numeric_limits<bool>::is_exact << endl;
    cout << "numeric_limits<bool>::radix = " << numeric_limits<bool>::radix << endl;
    cout << "numeric_limits<bool>::epsilon() = " << numeric_limits<bool>::epsilon() << endl;
    cout << "numeric_limits<bool>::round_error() = " << numeric_limits<bool>::round_error() << endl;
    cout << "numeric_limits<bool>::infinity() = " << numeric_limits<bool>::infinity() << endl;
    cout << "numeric_limits<bool>::quiet_NaN() = " << numeric_limits<bool>::quiet_NaN() << endl;
    cout << "numeric_limits<bool>::signaling_NaN() = " << numeric_limits<bool>::signaling_NaN() << endl;
    cout << "numeric_limits<bool>::denorm_min() = " << numeric_limits<bool>::denorm_min() << endl;
    /*
        numeric_limits<bool>::max() = 1
        numeric_limits<bool>::min() = 0
        numeric_limits<bool>::digits = 1
        numeric_limits<bool>::digits10 = 0
        numeric_limits<bool>::is_signed = 0
        numeric_limits<bool>::is_integer = 1
        numeric_limits<bool>::is_exact = 1
        numeric_limits<bool>::radix = 2
        numeric_limits<bool>::epsilon() = 0
        numeric_limits<bool>::round_error() = 0
        numeric_limits<bool>::infinity() = 0
        numeric_limits<bool>::quiet_NaN() = 0
        numeric_limits<bool>::signaling_NaN() = 0
        numeric_limits<bool>::denorm_min() = 0
    */

    // 再给出整型(例如无符号整型)和浮点型的各类指标
    cout << "numeric_limits<unsigned int>::max() = " << numeric_limits<unsigned int>::max() << endl;
    cout << "numeric_limits<unsigned int>::min() = " << numeric_limits<unsigned int>::min() << endl;
    cout << "numeric_limits<unsigned int>::digits = " << numeric_limits<unsigned int>::digits << endl;
    cout << "numeric_limits<unsigned int>::digits10 = " << numeric_limits<unsigned int>::digits10 << endl;
    cout << "numeric_limits<unsigned int>::is_signed = " << numeric_limits<unsigned int>::is_signed << endl;
    cout << "numeric_limits<unsigned int>::is_integer = " << numeric_limits<unsigned int>::is_integer << endl;
    cout << "numeric_limits<unsigned int>::is_exact = " << numeric_limits<unsigned int>::is_exact << endl;
    cout << "numeric_limits<unsigned int>::radix = " << numeric_limits<unsigned int>::radix << endl;
    cout << "numeric_limits<unsigned int>::epsilon() = " << numeric_limits<unsigned int>::epsilon() << endl;
    cout << "numeric_limits<unsigned int>::round_error() = " << numeric_limits<unsigned int>::round_error() << endl;
    cout << "numeric_limits<unsigned int>::infinity() = " << numeric_limits<unsigned int>::infinity() << endl;
    cout << "numeric_limits<unsigned int>::quiet_NaN() = " << numeric_limits<unsigned int>::quiet_NaN() << endl;
    cout << "numeric_limits<unsigned int>::signaling_NaN() = " << numeric_limits<unsigned int>::signaling_NaN() << endl;
    cout << "numeric_limits<unsigned int>::denorm_min() = " << numeric_limits<unsigned int>::denorm_min() << endl;
    /*
        numeric_limits<unsigned int>::max() = 4294967295
        numeric_limits<unsigned int>::min() = 0
        numeric_limits<unsigned int>::digits = 32
        numeric_limits<unsigned int>::digits10 = 9
        numeric_limits<unsigned int>::is_signed = 0
        numeric_limits<unsigned int>::is_integer = 1
        numeric_limits<unsigned int>::is_exact = 1
        numeric_limits<unsigned int>::radix = 2
        numeric_limits<unsigned int>::epsilon() = 0
        numeric_limits<unsigned int>::round_error() = 0
        numeric_limits<unsigned int>::infinity() = 0
        numeric_limits<unsigned int>::quiet_NaN() = 0
        numeric_limits<unsigned int>::signaling_NaN() = 0
        numeric_limits<unsigned int>::denorm_min() = 0
    */

    cout << "numeric_limits<double>::max() = " << numeric_limits<double>::max() << endl;
    cout << "numeric_limits<double>::min() = " << numeric_limits<double>::min() << endl;
    cout << "numeric_limits<double>::digits = " << numeric_limits<double>::digits << endl;
    cout << "numeric_limits<double>::digits10 = " << numeric_limits<double>::digits10 << endl;
    cout << "numeric_limits<double>::is_signed = " << numeric_limits<double>::is_signed << endl;
    cout << "numeric_limits<double>::is_integer = " << numeric_limits<double>::is_integer << endl;
    cout << "numeric_limits<double>::is_exact = " << numeric_limits<double>::is_exact << endl;
    cout << "numeric_limits<double>::radix = " << numeric_limits<double>::radix << endl;
    cout << "numeric_limits<double>::epsilon() = " << numeric_limits<double>::epsilon() << endl;
    cout << "numeric_limits<double>::round_error() = " << numeric_limits<double>::round_error() << endl;
    cout << "numeric_limits<double>::infinity() = " << numeric_limits<double>::infinity() << endl;
    cout << "numeric_limits<double>::quiet_NaN() = " << numeric_limits<double>::quiet_NaN() << endl;
    cout << "numeric_limits<double>::signaling_NaN() = " << numeric_limits<double>::signaling_NaN() << endl;
    cout << "numeric_limits<double>::denorm_min() = " << numeric_limits<double>::denorm_min() << endl;
    /*
        numeric_limits<double>::min() = 2.22507e-308
        numeric_limits<double>::digits = 53
        numeric_limits<double>::digits10 = 15
        numeric_limits<double>::is_signed = 1
        numeric_limits<double>::is_integer = 0
        numeric_limits<double>::is_exact = 0
        numeric_limits<double>::radix = 2
        numeric_limits<double>::epsilon() = 2.22045e-16
        numeric_limits<double>::round_error() = 0.5
        numeric_limits<double>::infinity() = inf
        numeric_limits<double>::quiet_NaN() = nan
        numeric_limits<double>::signaling_NaN() = nan(snan)
        numeric_limits<double>::denorm_min() = 4.94066e-324
    */

    
    return 0;
}