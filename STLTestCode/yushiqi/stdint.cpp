/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 09:08:56
 * @LastEditTime: 2022-04-24 09:23:35
 * @Description: stdint.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\stdint.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
    int8_t s1 = 0;
    cout<<"sizeof(int8_t) = "<<sizeof(s1)<<endl;
    cout<<"sizeof(int8_t) = "<<sizeof(int8_t)<<endl;
    cout<<"INT8_MIN = "<<INT8_MIN<<endl;
    cout<<"INT8_MAX = "<<INT8_MAX<<endl;

    int16_t s2 = 0;
    cout<<"sizeof(int16_t) = "<<sizeof(s2)<<endl;
    cout<<"sizeof(int16_t) = "<<sizeof(int16_t)<<endl;
    cout<<"INT16_MIN = "<<INT16_MIN<<endl;
    cout<<"INT16_MAX = "<<INT16_MAX<<endl;

    int32_t s3 = 0;
    cout<<"sizeof(int32_t) = "<<sizeof(s3)<<endl;
    cout<<"sizeof(int32_t) = "<<sizeof(int32_t)<<endl;
    cout<<"INT32_MIN = "<<INT32_MIN<<endl;
    cout<<"INT32_MAX = "<<INT32_MAX<<endl;

    int64_t s4 = 0;
    cout<<"sizeof(int64_t) = "<<sizeof(s4)<<endl;
    cout<<"sizeof(int64_t) = "<<sizeof(int64_t)<<endl;
    cout<<"INT64_MIN = "<<INT64_MIN<<endl;
    cout<<"INT64_MAX = "<<INT64_MAX<<endl;

    uint8_t u1 = 0;
    cout<<"sizeof(uint8_t) = "<<sizeof(u1)<<endl;
    cout<<"sizeof(uint8_t) = "<<sizeof(uint8_t)<<endl;
    cout<<"UINT8_MAX = "<<UINT8_MAX<<endl;

    uint16_t u2 = 0;
    cout<<"sizeof(uint16_t) = "<<sizeof(u2)<<endl;
    cout<<"sizeof(uint16_t) = "<<sizeof(uint16_t)<<endl;
    cout<<"UINT16_MAX = "<<UINT16_MAX<<endl;

    uint32_t u3 = 0;
    cout<<"sizeof(uint32_t) = "<<sizeof(u3)<<endl;
    cout<<"sizeof(uint32_t) = "<<sizeof(uint32_t)<<endl;
    cout<<"UINT32_MAX = "<<UINT32_MAX<<endl;

    uint64_t u4 = 0;
    cout<<"sizeof(uint64_t) = "<<sizeof(u4)<<endl;
    cout<<"sizeof(uint64_t) = "<<sizeof(uint64_t)<<endl;
    cout<<"UINT64_MAX = "<<UINT64_MAX<<endl;

    /*
        sizeof(int8_t) = 1
        sizeof(int8_t) = 1
        INT8_MIN = -128
        INT8_MAX = 127
        sizeof(int16_t) = 2
        sizeof(int16_t) = 2
        INT16_MIN = -32768
        INT16_MAX = 32767
        sizeof(int32_t) = 4
        sizeof(int32_t) = 4
        INT32_MIN = -2147483648
        INT32_MAX = 2147483647
        sizeof(int64_t) = 8
        sizeof(int64_t) = 8
        INT64_MIN = -9223372036854775808
        INT64_MAX = 9223372036854775807
        sizeof(uint8_t) = 1
        sizeof(uint8_t) = 1
        UINT8_MAX = 255
        sizeof(uint16_t) = 2
        sizeof(uint16_t) = 2
        UINT16_MAX = 65535
        sizeof(uint32_t) = 4
        sizeof(uint32_t) = 4
        UINT32_MAX = 4294967295
        sizeof(uint64_t) = 8
        sizeof(uint64_t) = 8
        UINT64_MAX = 18446744073709551615
    */
    return 0;
}