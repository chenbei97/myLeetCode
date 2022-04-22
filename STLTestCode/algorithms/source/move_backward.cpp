/*** 
 * @Author: chenbei
 * @Date: 2022-04-22 15:58:02
 * @LastEditTime: 2022-04-22 16:01:47
 * @Description: test move_backward.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\move_backward.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o ..\output\move_backward move_backward.cpp
..\output\move_backward.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src = {1,2,3,4,5,6,7,8,9,10};
    vector<int> dst(src.size());
    auto it = move_backward(src.begin(),src.end(),dst.end());
    if (it == dst.begin())
    {
        cout<<"move_backward success\n"; // 返回的是begin迭代器,如果是move返回的是end迭代器
    }
    ostream_iterator<int> out(cout," ");
    cout<<"dst:\n";
    copy(dst.begin(),dst.end(),out);
    cout<<endl;
    return 0;
}