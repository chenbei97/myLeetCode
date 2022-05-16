/*** 
 * @Author: chenbei
 * @Date: 2022-05-16 11:15:46
 * @LastEditTime: 2022-05-16 11:17:14
 * @Description: typedef.cpp
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\typedef.cpp
 * @Signature: A boy without dreams
 */
/*
cd STLTestCode\\yushiqi
g++ -o typedef typedef.cpp
./typedef
*/
#include <iostream>
using namespace std;
int main()
{
    typedef int myint;
    myint num = 32;

    typedef unsigned char vec3b[3];
    vec3b color = {1,2,3};

    typedef struct _rgb_struct{
        unsigned char r;
        unsigned char g;
        unsigned char b;
    }rgb_struct;
    rgb_struct rgb = {1,2,3};

    
    return 0;
}