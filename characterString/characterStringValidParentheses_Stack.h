/*** 
 * @Author: chenbei
 * @Date: 2022-03-03 14:32:00
 * @LastEditTime: 2022-03-16 08:12:00
 * @Description: check string is parentheses by stack
 * @FilePath: \myLeetCode\characterString\characterStringValidParentheses_Stack.h
 * @A boy without dreams
 */
#ifndef characterStringValidParenthesesStack_
#define characterStringValidParenthesesStack_
#include <string>
#include <unordered_map>
#include <stack>
#include <iostream>
using namespace std;
class characterStringValidParenthesesStack{
    public:
        bool isValid(string s){
            // 此题的前提是字符串只由括号类型字符组成
        if (s.size() % 2 == 1) return false; //奇数一定不匹配
        
        unordered_map<char,char> m = { // 字典便于查找
            {')','('}, // 左括号作为值,右括号为键
            {']','['},
            {'}','{'}
        };
        stack<char> stk;
        for(char c : s){ // 对每个字符遍历
            if (m.count(c)){ // 因为传入的字符可能不是右括号,而是左括号
                // 如果是右括号,它一定只能和最近的字符匹配,也就是栈顶元素
                // 这个右括号类型的c对应的左括号是m[c],如果两者不相等
                // 或者已经栈空
                if(stk.empty() || stk.top()!= m[c])
                    return false; // 不匹配
                stk.pop(); // 如果匹配就清除这个匹配的左括号
            }
            else{
                // 只会让左括号直接入栈
                stk.push(c);
            }
        }
        // 遍历结束后栈空说明匹配否则不匹配
        return stk.empty(); 
    }

};
void _characterStringValidParenthesesStack(){
    characterStringValidParenthesesStack solution;
    string s("({[]})([]){}");
    bool ans = solution.isValid(s);
    cout<<"the parentheses is valid? "<<(ans?"true":"false")<<endl;
}
#endif //!characterStringValidParenthesesStack_