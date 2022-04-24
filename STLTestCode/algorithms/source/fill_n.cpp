/*** 
 * @Author: chenbei
 * @Date: 2022-04-24 14:37:23
 * @LastEditTime: 2022-04-24 14:43:53
 * @Description: test fill_n.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\fill_n.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\fill_n fill_n.cpp
..\output\fill_n.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 从指定的位置开始填充n个值
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    fill_n(src.begin()+3, 5, 0);
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout << endl;
    return 0;
}