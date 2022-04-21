/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 10:45:08
 * @LastEditTime: 2022-04-21 10:46:55
 * @Description: test merge.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\merge.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o merge merge.cpp
.\merge.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 归并排序,要求归并的序列已经有序
    vector<int> src1 = {1,3,5,7,9};
    vector<int> src2 = {2,4,6,8,10};
    vector<int> dst;
    // 使用back_inserter指示尾插提高效率,也无需事先指定dst的size
    merge(src1.begin(), src1.end(), src2.begin(), src2.end(), back_inserter(dst));
    ostream_iterator<int> out(cout," ");
    copy(dst.begin(), dst.end(), out);
    cout <<endl;
    return 0;
}