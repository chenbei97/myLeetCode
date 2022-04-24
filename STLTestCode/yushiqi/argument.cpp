/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 08:17:07
 * @LastEditTime: 2022-04-24 08:19:32
 * @Description: argument.cpp 主函数可带参数
 * @FilePath: \myLeetCode\STLTestCode\yushiqi\argument.cpp
 * @Signature: A boy without dreams
 */
#include <iostream>
using namespace std;
int main(int argc,char** argv)
{
    for(int i = 0;i<argc;++i)
    {
        cout<<"param "<<i<<": "<<argv[i]<<endl;
    }
}
