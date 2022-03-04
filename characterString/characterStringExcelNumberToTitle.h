#ifndef characterStringExcelNumberToTitle_
#define characterStringExcelNumberToTitle_
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class characterStringExcelNumberToTitle{
    public:
        string numberTotitle(int n){
            string ans;
            while (n > 0) {
            int a = (n - 1) % 26 + 1; // 依次计算的是a0,a1,a2...
            // a∈[1,26] 逢27进1,n=26时还可以用z表示
            ans += a - 1 + 'A';// n=27时,a=1,ans='A'
            n = (n - a) / 26; // 新的number总是当前的number减去上一次计算出的系数对26取整
        }
        // ans是从低位往高位添加字母的
        reverse(ans.begin(), ans.end());
        return ans;//还需要反转
    }
};
void _characterString_excelNumberToTitle(){
    characterStringExcelNumberToTitle solution;
    int number = 28;
    string ans = solution.numberTotitle(number);
    cout<<"28 is converted to string is "<<ans<<endl;
}
#endif // !characterStringExcelNumberToTitle_