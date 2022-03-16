'''
Author: chenbei
Date: 2022-03-04 14:56:08
LastEditTime: 2022-03-16 08:08:47
Description: excel str to number
FilePath: \myLeetCode\characterString\characterStringExcelTitleToNumber.py
A boy without dreams
'''
class characterStringExcelTitleToNumber:
    def titleToNumber(self,s:str)->int:
        ans = 0
        for i in reversed(range(len(s))):
            k = ord(s[i]) - ord("A") + 1
            m = pow(26,len(s)-i-1)
            ans += m * k
        return ans
if __name__ == '__main__':
    solution = characterStringExcelTitleToNumber()
    s = "AB"
    print(solution.titleToNumber(s))