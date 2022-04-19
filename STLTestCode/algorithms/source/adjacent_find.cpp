/*** 
 * @Author: chenbei
 * @Date: 2022-04-19 11:29:20
 * @LastEditTime: 2022-04-19 11:37:55
 * @Description: 
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\adjacent_find.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o adjacent_find adjacent_find.cpp
.\adjacent_find.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> src1 = {1,2,3,4,5};
    auto it1 = adjacent_find(src1.begin(),src1.end());
    if (it1 == src1.end())
        cout << "not found" << endl;
    else
        cout << *it1 << endl;
    
    vector<int> src2 = {1,2,100,100,3,4,5,200,200};
    auto it2 = adjacent_find(src2.begin(),src2.end());
    if (it2 == src2.end())
        cout << "not found" << endl;
    else
        cout << *it2 << endl;

    // 这里可以说明默认的函数对象就是比较2个数是否相等
    auto it3 = adjacent_find(src2.begin(),src2.end(),[](int i,int j){return i==j;});
    if (it3 == src2.end())
        cout << "not found" << endl;
    else
        cout << *it3 << endl;
    
    // 这里可以定义比较前后是否有差值为5的数
    vector<int> src3 = {1,3,5,4,32,37};
    auto f = [](int i,int j){return i==j-5;};
    auto it4 = adjacent_find(src3.begin(),src3.end(),f);
    if (it4 == src3.end())
        cout << "not found" << endl;
    else
        cout << *it4 << endl;
    return 0;
}
