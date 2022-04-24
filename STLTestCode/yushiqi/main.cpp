/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 07:56:39
 * @LastEditTime: 2022-04-24 08:01:55
 * @Description: yushiqi's main.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\main.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include "mul.hpp" // 只包含了函数声明,会自动寻找其定义在mul.cpp中
using namespace std;
int main(){
    int a=5,b=4,result=0;
    result = mul(a,b);
    cout<<"the result is "<<result<<endl;
    return 0;
}
