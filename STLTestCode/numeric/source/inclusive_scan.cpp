/*** 
 * @Author: chenbei
 * @Date: 2022-04-25 08:41:39
 * @LastEditTime: 2022-04-25 08:45:19
 * @Description: test inclusive_scan.cpp
 * @FilePath: \myLeetCode\STLTestCode\numeric\source\inclusive_scan.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\inclusive_scan inclusive_scan.cpp
..\output\inclusive_scan.exe
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;
int main()
{
    // 这个函数非常像accumulate,但是不是直接计算累加和,而是把每个结果用数组存起来
    vector<int> src = {2,1,7,5,3};
    vector<int> dst;
    inclusive_scan(src.begin(), src.end(), back_inserter(dst));
    ostream_iterator<int> out(cout," ");
    copy(dst.begin(), dst.end(), out);
    cout << endl;// 2 3 10 15 18
    // 指定初始值也可以,但是事先提供一个累加器,这里是两数之和,也是默认使用的
    vector<int> dst2;
    inclusive_scan(src.begin(), src.end(), back_inserter(dst2),[](int x,int y){return x+y;}, 10);
    copy(dst2.begin(), dst2.end(), out);
    cout << endl;// 12 13 20 25 28
    return 0;
}