/*** 
 * @Author: chenbei
 * @Date: 2022-04-19 08:03:52
 * @LastEditTime: 2022-04-19 11:16:57
 * @Description: test find.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\find.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o find find.cpp
.\find.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main(){
    vector<int> src = {-1,-2,-3,-4,0,1,2,3,4};
    vector<int>::iterator it = find(src.begin(),src.end(),0);
    cout << *it << endl;
    vector<int>::iterator it2 = find(src.begin(),src.end(),5);
    if (it2 == src.end())
        cout << "not found" << endl;
    else
        cout << *it2 << endl;
    
    vector<int> ::iterator it3 = find_if(src.begin(),src.end(),[](int i){return i>0;});
    cout << *it3 << endl;
    return 0;
}