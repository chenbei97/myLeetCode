/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 10:29:31
 * @LastEditTime: 2022-04-21 10:36:31
 * @Description: test shuffle.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\shuffle.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o shuffle shuffle.cpp
.\shuffle.exe
*/
#include <algorithm>
#include <iostream>
#include <random> //  include default_random_engine
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    shuffle(src.begin(), src.end(), default_random_engine(time(0)));
    ostream_iterator<int> out(cout," ");// 随时间变化的随机数
    copy(src.begin(), src.end(), out);
    cout <<endl;

    vector<int> src2 = {1,2,3,4,5,6,7,8,9,10};
    default_random_engine rngl; // 使用默认的随机数种子
    shuffle(src2.begin(), src2.end(), rngl);
    copy(src2.begin(), src2.end(), out); // 每次都不会变
    cout <<endl;
    
    vector<int> src3 = {1,2,3,4,5,6,7,8,9,10};
    default_random_engine rng2{10}; // 使用指定的随机数种子
    shuffle(src3.begin(), src3.end(), rng2);
    copy(src3.begin(), src3.end(), out); // 每次都不会变
    cout <<endl;
    return 0;
}