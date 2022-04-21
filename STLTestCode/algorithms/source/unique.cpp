/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 11:33:54
 * @LastEditTime: 2022-04-21 11:37:25
 * @Description: test unique.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\unique.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\unique unique.cpp
..\output\unique.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 去重
    vector<int> src = {0,0,1,1,1,2,2,3,3,3,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,9};
    auto it = unique(src.begin(), src.end());
    for (auto i : src)
    {
        cout << i << " "; // 可以观察到只是把不重复的元素移动到前边,给定的it迭代器指向9罢了
    }
    cout << endl;
    copy(src.begin(), it, ostream_iterator<int>(cout, " "));
    cout << endl; // 0 1 2 3 4 5 6 7 8 9
    return 0;
}
