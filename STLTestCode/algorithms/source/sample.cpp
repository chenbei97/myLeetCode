/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 15:23:59
 * @LastEditTime: 2022-04-22 15:33:35
 * @Description: test sample.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\sample.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\sample sample.cpp
..\output\sample.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <random> // default_random_engine
#include <iterator>
using namespace std;
int main()
{
    // 随机采样n个数
    vector<int> src = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    vector<int> dst;
    int n = 5;
    // std::mt19937{std::random_device{}()}可以,default_random_engine{}也可以
    sample(src.begin(), src.end(), back_inserter(dst),n,std::mt19937{std::random_device{}()});
    ostream_iterator<int> out(cout," ");
    copy(dst.begin(),dst.end(),out);
    cout<<endl;
    return 0;
}