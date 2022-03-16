/*** 
 * @Author: chenbei
 * @Date: 2022-03-04 14:56:04
 * @LastEditTime: 2022-03-16 08:08:36
 * @Description: excel str to number
 * @FilePath: \myLeetCode\characterString\characterStringExcelTitleToNumber.h
 * @A boy without dreams
 */
#ifndef characterStringExcelTitleToNumber_
#define characterStringExcelTitleToNumber_
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
class characterStringExcelTitleToNumber{
    public :
        int titleToNumber(string s){
            int ans = 0;
            int n = s.length()-1;
            for(int i = n; i>=0;i--){ // 从右往左遍历
                int k = s[i]-'A'+1; // 转换成26进制的数
                long m = pow(26,n-i);
                ans += m * k;
            }
            return ans;
        }
        // 更高效的写法
        int titleToNumbe1(string columnTitle){
            int number = 0;
            long multiple = 1;
            for (int i = columnTitle.size() - 1; i >= 0; i--) {
                int k = columnTitle[i] - 'A' + 1;
                number += k * multiple;
                multiple *= 26;
            }
            return number;
        }
};
void _characterString_excelTitleToNumber(){
    characterStringExcelTitleToNumber solution;
    string s("AB");
    int number = solution.titleToNumber(s);
    cout<<"AB to number is "<< number<<endl;

}
#endif // !characterStringExcelTitleToNumber_