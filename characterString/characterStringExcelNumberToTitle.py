'''
Author: chenbei
Date: 2022-03-04 15:41:26
LastEditTime: 2022-03-16 08:08:30
Description: excel number to str
FilePath: \myLeetCode\characterString\characterStringExcelNumberToTitle.py
A boy without dreams
'''
class characterStringExcelNumberToTitle:
    def numberTotitle(self,n:int)->str:
        ans = []
        while n > 0:
            a = (n - 1) % 26 + 1 #逢27进1
            ans.append(chr(a - 1 + ord("A")))
            n = (n - a) // 26
        return "".join(ans[::-1]) #翻转并转换为str类型
if __name__ == '__main__':
    solution = characterStringExcelNumberToTitle()
    n = 28
    print(solution.numberTotitle(n))