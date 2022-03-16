/*** 
 * @Author: chenbei
 * @Date: 2022-03-04 13:12:18
 * @LastEditTime: 2022-03-16 08:11:41
 * @Description: check string is palindrome by greedy
 * @FilePath: \myLeetCode\characterString\characterStringPalindrome_Greedy.h
 * @A boy without dreams
 */
#ifndef characterStringPalindromeGreedy_
#define characterStringPalindromeGreedy_
#include <string>
#include <iostream>
using namespace std;
class characterStringPalindromeGreedy{
    public :
        bool validPalindrome(string s) {  
            // 贪心算法不再枚举每个位置,而是考虑如果2个字符不相等的时候
            // 因为至多只能删除1个字符,所以2个字符之间必须删除1个
            // 那么删除其中1个以后有2种可能
            // [head,tail-1]的字符串或者[head+1,tail]的字符串取判断是否回文即可
            // 至少有1个是回文的说明可以,否则就不可以,因为至多删除1次
            // 如果2个字符相等,就head++,tail--即可直到遇见不相等的时候 
            int head=0,tail=s.length()-1;
            while (head < tail){
                if (s[head] != s[tail]) { // 删除head或者tail
                    bool ret1 = checkPalindrome(s,head,tail-1); //[head,tail-1]
                    bool ret2 = checkPalindrome(s,head+1,tail);
                    return ret1 || ret2; // 有1个成立就行
                }
                else{
                    head++;
                    tail--;
                }  
            } 
            return true;
        }
        bool checkPalindrome(string s,int head,int tail){
            while (head < tail){
                if (s[head] != s[tail]) return false;
                head++;
                tail--;
            }
            return true;
        }
};
void _characterString_palindrome_greedy(){
    characterStringPalindromeGreedy solution;
    string s("abcdeffdcba");
    bool ans = solution.validPalindrome(s);
    cout <<"greedy => the string is palindrome? "<<(ans? "true":"false")<<endl;
}
#endif // !characterStringPalindromeGreedy_