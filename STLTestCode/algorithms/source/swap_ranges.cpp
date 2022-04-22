/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 16:11:12
 * @LastEditTime: 2022-04-22 16:16:02
 * @Description: test swap_ranges.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\swap_ranges.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\swap_ranges swap_ranges.cpp
..\output\swap_ranges.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 交换2个数组的某些范围元素,把3,4,5和10,11,12交换
    vector<int> src1 = {1,2,3,4,5,6};
    vector<int> src2 = {7,8,9,10,11,12};
    swap_ranges(src1.begin()+2,src1.end()-1,src2.begin()+3);
    ostream_iterator<int> out(cout," ");
    cout<<"src1:\n";
    copy(src1.begin(),src1.end(),out); // 1 2 10 11 12 6
    cout<<endl;
    cout<<"src2:\n";
    copy(src2.begin(),src2.end(),out); // 7 8 9 3 4 5
    cout<<endl;
    return 0;
}