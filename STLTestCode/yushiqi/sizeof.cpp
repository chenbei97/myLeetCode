/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 08:23:21
 * @LastEditTime: 2022-04-24 08:29:26
 * @Description: sizeof.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\sizeof.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
using namespace std;
int main(){
    short i = 0;
    int j = 0; // [-2^31,2^31-1]
    long k = 0;
    long long m = 0;
    float n = 0.1f;//带上字面量f可避免隐式转换double->float
    double h = 0.2;
    unsigned int u = 0; // [0,2^32-1]
    cout<<"sizeof(short) = "<<sizeof(i)<<endl;
    cout<<"sizeof(int) = "<<sizeof(j)<<endl;
    cout<<"sizeof(unsigned int) = "<<sizeof(u)<<endl;
    cout<<"sizeof(long) = "<<sizeof(k)<<endl;
    cout<<"sizeof(long long) = "<<sizeof(m)<<endl;
    cout<<"sizeof(float) = "<<sizeof(n)<<endl;
    cout<<"sizeof(double) = "<<sizeof(h)<<endl;
    cout<<"sizeof(char) = "<<sizeof(char)<<endl;

    // bool 依然占据1个字节,而不是一个位
    cout<<"sizeof(bool) = "<<sizeof(bool)<<endl;
    cout<<"sizeof(void*) = "<<sizeof(void*)<<endl;

    // size_t是一个可自动依据系统32/64位自动适应的类型
    cout<<"sizeof(size_t) = "<<sizeof(size_t)<<endl;
    return 0;
    /*
        sizeof(short) = 2
        sizeof(int) = 4
        sizeof(unsigned int) = 4
        sizeof(long) = 4
        sizeof(long long) = 8
        sizeof(float) = 4
        sizeof(double) = 8
        sizeof(char) = 1
        sizeof(bool) = 1
        sizeof(void*) = 8
        sizeof(size_t) = 8
    */
}
