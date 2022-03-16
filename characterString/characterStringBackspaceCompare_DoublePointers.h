/*** 
 * @Author: chenbei
 * @Date: 2022-03-03 10:15:18
 * @LastEditTime: 2022-03-16 08:04:47
 * @Description: string backspace by double pointers
 * @FilePath: \myLeetCode\characterString\characterStringBackspaceCompare_DoublePointers.h
 * @A boy without dreams
 */
#ifndef characterStringBackspaceCompareDoublePointers_
#define characterStringBackspaceCompareDoublePointers_
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class characterStringBackspaceCompareDoublePointers{
    public:
        bool backspaceCompare(string s, string t){
            int s1=s.length()-1,s2=t.length()-1; // 逆序遍历字符串
            int skip1=0,skip2=0; // 2个字符串待删除的字符数量
            while (s1>=0 || s2>=0){ // 字符串长度可以不等,退格后也可以不等,但是最终都会遍历完
                while (s1>=0) { // 只要s1没遍历完就遍历
                    if (s[s1] == '#'){
                        skip1++;//说明前边的字符要跳过(不是真删除),待删增1
                        s1--; // 因为遇见的是#,所以要多跳过1次
                    }
                    else { // 是普通字符
                        if (skip1!=0){ // 不为0说明上次遇见的必定是#
                            s1--; // 跳过它
                            skip1--; // 跳过的少1个
                        }
                        else break; // 例如可能遇见连续普通字符'abcd#'的情况
                        // '#'在skip1=1时,skip1--等于0,且s1--已经跳过了d
                        // 再次判断时,直接break,当前s1停在'c'位置
                    }
                }
                // s2的情况同理,没遍历完就遍历
                while(s2>=0){
                    if (t[s2] == '#'){
                        skip2++;
                        s2--;
                    }
                    else{
                        if(skip2!=0){
                            skip2--;
                            s2--;
                        }
                        else break;
                    }
                }

                // 现在s1,s2跳过前边的#字符后,都停留在某个字符位置,或者s1,s2已经小于0
                // 所以先检验s1,s2的情况,可能都>=0,这样的可以比较2个字符,不相等就返回false
                // 也可能只有1个>=0,这时说明2个字符串退格后长度是不相等的了,直接返回false即可
                if (s1>=0 && s2>=0){
                    if (s[s1] != t[s2]) return false; 
                }
                else if (s1>=0 || s2>=0) return false;

                // 如果s1,s2的位置不是上述的2个情况就可以继续逆序安全的进入下一轮大循环
                // s1,s2可能都为0,下次大循环不会执行了,说明遍历都结束还没有找到false的情况,返回true即可
                // 如果s1,s2都＞0,那就继续下一轮大循环
                s1--; // 正常的逆序遍历,控制变量-1
                s2--; // 上边的-1是skip不为0时跳过的
            }
            return true;
    }
};
void _characterString_backspaceCompare_doublePointers(){
    characterStringBackspaceCompareDoublePointers solution;
    string s1("a##c");
    string s2("#a#c");
    bool ans = solution.backspaceCompare(s1,s2);
    cout<<"doublePointers=> string1 == string2 ? "<<(ans?"true":"false")<<endl;
}
#endif // !characterStringBackspaceCompareDoublePointers_