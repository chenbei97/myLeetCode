/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 11:30:57
 * @LastEditTime: 2022-04-21 11:32:06
 * @Description: test remove_if.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\remove_if.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\remove_if remove_if.cpp
..\output\remove_if.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 移除符合条件的元素,例如小于10的元素
    vector<int> src = {0,1,11,5,13,-1,100,32,8,15};
    auto it = remove_if(src.begin(), src.end(), [](int x){return x<10;});
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), it, out); // it指向end
    cout << endl;
    return 0;
}
