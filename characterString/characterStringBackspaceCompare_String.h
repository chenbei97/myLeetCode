#ifndef characterStringBackspaceCompareString_
#define characterStringBackspaceCompareString_
#include <string>
#include <iostream>
using namespace std;
class characterStringBackspaceCompareString{
    public:
        bool backspaceCompare(string s, string t){
            return rebuild(s) == rebuild(t);
    }
    protected:
        string rebuild(string s){
            string ans;
            for (char c : s){
                if (c != '#')ans.push_back(c);
                else if (!ans.empty()) ans.pop_back();
            }
            return ans;
        }
};
void _characterString_backspaceCompare_string(){
    characterStringBackspaceCompareString solution;
    string s1("a##c");
    string s2("#a#c");
    bool ans = solution.backspaceCompare(s1,s2);
    cout<<"string=> string1 == string2 ? "<<(ans?"true":"false")<<endl;
}
#endif // !characterStringBackspaceCompareString_