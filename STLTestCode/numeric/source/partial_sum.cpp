/*** 
 * @Author: chenbei
 * @Date: 2022-04-25 08:52:39
 * @LastEditTime: 2022-04-25 08:54:09
 * @Description: test partial_sum.cpp
 * @FilePath: \myLeetCode\STLTestCode\numeric\source\partial_sum.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\partial_sum partial_sum.cpp
..\output\partial_sum.exe
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;
int main()
{
    // 求部分和
    vector<int> src = {1,1,2,2,1,1};
    vector<int> dst;
    partial_sum(src.begin(),src.end(),back_inserter(dst));
    ostream_iterator<int> out(cout," ");
    copy(dst.begin(),dst.end(),out);
    cout<<"\n"; // 1 2 4 6 7 8
    return 0;
}