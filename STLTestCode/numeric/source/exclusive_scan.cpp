/*** 
 * @Author: chenbei
 * @Date: 2022-04-25 08:48:19
 * @LastEditTime: 2022-04-25 08:51:33
 * @Description: test exclusive_scan.cpp
 * @FilePath: \myLeetCode\STLTestCode\numeric\source\exclusive_scan.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\exclusive_scan exclusive_scan.cpp
..\output\exclusive_scan.exe
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;
int main()
{
    // 同样是2,1,7,5,3,初始值10,inclusive_scan的结果是12 13 20 25 28,因为10+2
    // 但是这里10直接作为初始值,exclusive_scan的结果是10 12 13 20 25,恰好错了1位
    // 还要注意初始值变成了第三个参数
    vector<int> src = {2,1,7,5,3};
    vector<int> dst;
    exclusive_scan(src.begin(), src.end(), back_inserter(dst),10,[](int x,int y){return x+y;});
    ostream_iterator<int> out(cout," ");
    copy(dst.begin(), dst.end(), out);
    cout << endl;// 10 12 13 20 25
    return 0;
}