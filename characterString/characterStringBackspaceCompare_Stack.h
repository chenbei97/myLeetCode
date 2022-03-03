#ifndef characterStringBackspaceCompareStack_
#define characterStringBackspaceCompareStack_
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class characterStringBackspaceCompareStack
{
    public:
        bool backspaceCompare(string s, string t){
            for(int i = 0 ; i<s.size();i++){
                if (s[i] == '#' && stk1.empty()) continue;
                if (s[i] == '#') stk1.pop();
                else stk1.push(s[i]);
            }
            for(int i = 0 ; i<t.size();i++){
                if (t[i] == '#' && stk2.empty()) continue;
                if (t[i] == '#') stk2.pop();
                else stk2.push(t[i]);
            }
            if (stk1.size()!=stk2.size()) return false;
            while (!stk1.empty()){
                if (stk1.top() != stk2.top()) return false;
                stk1.pop();
                stk2.pop();
            }
            return true;
        }
        // 2个函数是测试用的,现在调试好了函数没有用了
        // 因为比较的过程已经清空了2个栈
        void printStk1(){
            while (!stk1.empty()){
                cout<<stk1.top()<<" ";
                stk1.pop();
            }
            cout<<"\n";
        }
        void printStk2(){
            while (!stk2.empty()){
                cout<<stk2.top()<<" ";
                stk2.pop();
            }
            cout<<"\n";
        }
    protected:
        stack<char> stk1;
        stack<char> stk2;
        
};
void _characterString_backspaceCompare_stack(){
    characterStringBackspaceCompareStack solution;
    string s1("a##c");
    string s2("#a#c");
    bool ans = solution.backspaceCompare(s1,s2);
    cout<<"stack=> string1 == string2 ? "<<(ans?"true":"false")<<endl;
    // solution.printStk1();
    // solution.printStk2();

}
#endif // !characterStringBackspaceCompareStack_