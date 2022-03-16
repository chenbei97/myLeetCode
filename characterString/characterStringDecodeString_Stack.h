/*** 
 * @Author: chenbei
 * @Date: 2022-03-05 13:30:19
 * @LastEditTime: 2022-03-16 08:07:55
 * @Description: string decode by stack
 * @FilePath: \myLeetCode\characterString\characterStringDecodeString_Stack.h
 * @A boy without dreams
 */
#ifndef characterStringDecodeStringStack_
#define characterStringDecodeStringStack_
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class characterStringDecodeStringStack{
    public:
    string decodeString(string s) {
        vector <string> stk;
        size_t ptr = 0;
        while (ptr < s.size()) 
        {
            char cur = s[ptr];
            if (isdigit(cur)) 
            {
                // 获取一个数字并进栈
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } 
            else if (isalpha(cur) || cur == '[') 
            {
                // 获取一个字母并进栈
                stk.push_back(string(1, s[ptr++])); 
            } 
            else 
            {
                ++ptr;
                vector <string> sub;
                while (stk.back() != "[") 
                {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                // 左括号出栈
                stk.pop_back();
                // 此时栈顶为当前 sub 对应的字符串应该出现的次数
                int repTime = stoi(stk.back()); 
                stk.pop_back();
                string t, o = getString(sub);
                // 构造字符串
                while (repTime--) t += o; 
                // 将构造好的字符串入栈
                stk.push_back(t);
            }
        }

        return getString(stk);
    }
    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }
    string getString(vector <string> &v) {
        string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }
};
void _characterString_decodeString_stack(){
    characterStringDecodeStringStack solution;
    string s("3[a2[c]]2[abc]ddd3[cd]ef");
    string ans = solution.decodeString(s);
    cout<<"stack => the decode string is "<<ans<<endl;
}
#endif // characterStringDecodeStringStack_