/*** 
 * @Author: chenbei
 * @Date: 2022-03-05 15:03:13
 * @LastEditTime: 2022-03-16 08:07:40
 * @Description: string decode by recursion
 * @FilePath: \myLeetCode\characterString\characterStringDecodeString_Recursion.h
 * @A boy without dreams
 */
#ifndef characterStringDecodeStringRecursion_
#define characterStringDecodeStringRecursion_
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class characterStringDecodeStringRecursion{
    public:
        string decodeString(string s) {
            src = s;
            ptr = 0;
            return getString();
        }
        int getDigits() {
            int ret = 0;
            while (ptr < src.size() && isdigit(src[ptr])) {
                ret = ret * 10 + src[ptr++] - '0';
            }
            return ret;
        }
        string getString() 
        {
            if (ptr == src.size() || src[ptr] == ']') {
                // String -> EPS
                return "";
            }

            char cur = src[ptr]; int repTime = 1;
            string ret;

            if (isdigit(cur)) {
                // String -> Digits [ String ] String
                // 解析 Digits
                repTime = getDigits(); 
                // 过滤左括号
                ++ptr;
                // 解析 String
                string str = getString(); 
                // 过滤右括号
                ++ptr;
                // 构造字符串
                while (repTime--) ret += str; 
            } else if (isalpha(cur)) {
                // String -> Char String
                // 解析 Char
                ret = string(1, src[ptr++]);
            }   
            return ret + getString();
        }

    protected:
        string src; 
        size_t ptr;
};
void _characterString_decodeString_recursion(){
    characterStringDecodeStringRecursion solution;
    string s("3[a2[c]]2[abc]ddd3[cd]ef");
    string ans = solution.decodeString(s);
    cout<<"recursion => the decode string is "<<ans<<endl;
}
#endif // characterStringDecodeStringRecursion_