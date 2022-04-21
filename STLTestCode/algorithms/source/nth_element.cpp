/*** 
 * @Author: chenbei
 * @Date: 2022-04-21 09:32:05
 * @LastEditTime: 2022-04-21 09:40:42
 * @Description: test nth_element.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\nth_element.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o nth_element nth_element.cpp
.\nth_element.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 不返回任何东西,但是指定的位置前边的元素都比它小,后边的元素都比它大
    int n = 5;
    vector<int> src = {9,3,5,1,7,8,2,6,4,0};
    sort(src.begin(), src.end()); // 事先要求升序
    nth_element(src.begin(), src.begin()+n, src.end());
    ostream_iterator<int> out(cout," ");
    copy(src.begin(), src.end(), out);
    cout <<endl; // 1 0 4 3 2 5 6 7 8 9 

    nth_element(src.begin(), src.begin()+n, src.end(), greater<int>());
    copy(src.begin(), src.end(), out);
    cout <<endl; // 5 9 7 6 8 4 3 1 2 0
    
    return 0;
}