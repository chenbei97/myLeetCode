#ifndef characterStringDecodeStringIteration_
#define characterStringDecodeStringIteration_
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class characterStringDecodeStringIteration{
    public:
        string decodeString(string s){
            vector<int> headIdx,tailIdx;
            int n = s.length();
            for(int i =0;i<n;i++){
                if (s[i] == '[') headIdx.push_back(i);
                if (s[i] == ']') tailIdx.push_back(i);
            }
            string k(s); // 必须创建新的
            for(int i =0;i<headIdx.size();i++){
                string substr;
                int x = s[headIdx[i]-1] -'0'; // s第1次插入以后会影响这个x的值,s不是原来的s
                for(int j =0;j<x-1;j++)
                    for(int k =headIdx[i]+1;k<tailIdx[i];k++)
                        substr.push_back(s[k]);
                // cout<<"substr = "<<substr<<endl;
                for(int m = 0;m<substr.size();m++){
                    k.insert(k.begin()+tailIdx[i]+1+m,substr[m]);
                }
            }
            string ans;
            for (int i =0;i<k.size();i++){
                if (k[i] != '[' && k[i] != ']'&& ! isdigit(k[i])){
                    ans.push_back(k[i]);
                }
            }
            return ans;
        }
};
void _characterString_decodeString_iteration(){
    // 只适用于非多重嵌套的字符解码
    characterStringDecodeStringIteration solution;
    string s("2[abc]ddd3[cd]ef");
    string ans = solution.decodeString(s);
    cout<<"iteration => the decode string is "<<ans<<endl;
}
#endif // characterStringDecodeStringIteration_