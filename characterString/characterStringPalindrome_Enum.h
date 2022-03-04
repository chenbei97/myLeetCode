#ifndef characterStringPalindromeEnum_
#define characterStringPalindromeEnum_
#include <string>
#include <iostream>
using namespace std;
class characterStringPalindromeEnum{
    public:
        bool validPalindrome(string s) {    
            int defaultLoc = -1; // 缺省位置
            cout<<s.length()<<endl;
            int n = s.length(); // 必须强制转换,不然dedaultLoc<s.length()是false
            while (defaultLoc <n)
            {
                string t ;
                for(int i =0 ;i<n;i++){
                    if (i != defaultLoc)
                        t.push_back(s[i]);
                }
                // cout<<t<<endl;
                bool ret = checkPalindrome(t);
                if (ret) return true;
                defaultLoc ++;
            }
            return false;
        }
    protected:
        bool checkPalindrome(string s){
            int head=0,tail=s.length()-1;
            while (head < tail){
                if (s[head]!=s[tail]) return false;
                head++;
                tail--;
            }
            return true;
        }
};
void _characterString_palindrome_enum(){
    string s("abcdeffdcba");
    characterStringPalindromeEnum solution;
    bool ans = solution.validPalindrome(s);
    cout <<"enum => the string is palindrome? "<<(ans? "true":"false")<<endl;
}
#endif // !characterStringPalindromeEnum_