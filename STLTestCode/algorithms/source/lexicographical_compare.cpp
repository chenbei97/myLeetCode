/*** 
 * @Author: chenbei
 * @Date: 2022-04-20 10:39:44
 * @LastEditTime: 2022-04-20 10:57:55
 * @Description: test lexicographical_compare.cpp
 * @FilePath: \myLeetCode\STLTestCode\algorithms\source\lexicographical_compare.cpp
 * @Signature: A boy without dreams
 */
/*
g++ -o lexicographical_compare lexicographical_compare.cpp
.\lexicographical_compare.exe
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    // 默认按照<来逐个比较字母元素
    vector<char> s1 = {'a', 'b', 'c'};
    vector<char> s2 = {'b','b','c'};
    bool s12 = lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
    if (s12) cout<<"{a,b,c} less than {b,b,c}"<<endl;
    else cout<<"{b,b,c} less than {a,b,c}"<<endl;

    vector<char> s3 = {'a', 'b', 'c'};
    vector<char> s4 = {'a', 'd', 'c'};
    bool s34 = lexicographical_compare(begin(s3),end(s3),begin(s4),end(s4));;
    if (s34) cout<<"{a,b,c} less than {a,d,c}"<<endl;
    else cout<<"{a,d,c} less than {a,b,c}"<<endl;

    vector<char> s5 = {'a', 'b', 'c'};
    vector<char> s6 = {'a', 'b', 'a'};
    bool s56 = lexicographical_compare(begin(s5),end(s5),begin(s6),end(s6));;
    if (s56) cout<<"{a,b,c} less than {a,b,a}"<<endl;
    else cout<<"{a,b,a} less than {a,b,c}"<<endl;

    // 比较字符串也是默认使用<
    vector<string> v1 = {"abc", "abd", "abe"};
    vector<string> v2 = {"abd", "abd", "abe"};
    bool v12 = lexicographical_compare(begin(v1),end(v1),begin(v2),end(v2));
    if (v12) cout<<"{abc,abd,abe} less than {abd,abd,abe}"<<endl;
    else cout<<"{abd,abd,abe} less than {abc,abd,abe}"<<endl;

    vector<string> v3 = {"abc", "abd", "abe"};
    vector<string> v4 = {"abc", "abd", "aba"};
    bool v34 = lexicographical_compare(begin(v3),end(v3),begin(v4),end(v4));
    if (v34) cout<<"{abc,abd,abe} less than {abc,abd,aba}"<<endl;
    else cout<<"{abc,abd,aba} less than {abc,abd,abe}"<<endl;

    // 也可以指定比较的规则,例如按照长度比较
    vector<string> v5 = {"abc", "abd"};
    vector<string> v6 = {"abd", "abe"};
    bool v56 = lexicographical_compare(begin(v5),end(v5),begin(v6),end(v6),[](const string& s1, const string& s2){return s1.size() == s2.size();});
    if (v56) cout<<"{abc,abd}.length == {abd,abe}.length"<<endl;
    else cout<<"{abd,abe}.length != {abc,abd}.length"<<endl;
    return 0;
}