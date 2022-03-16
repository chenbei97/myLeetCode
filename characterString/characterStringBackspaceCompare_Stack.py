'''
Author: chenbei
Date: 2022-03-03 08:12:09
LastEditTime: 2022-03-16 08:05:16
Description: string backspace by double stack
FilePath: \myLeetCode\characterString\characterStringBackspaceCompare_Stack.py
A boy without dreams
'''
class characterStringBackspaceCompareStack:
    def backspaceCompare(self, s: str, t: str) -> bool:
        stk1,stk2 = [],[]
        for c in s:
            if c == '#' and len(stk1)==0 : continue
            if c == '#' : stk1.pop()
            else : stk1.append(c)
        for c in t :
            if c == '#' and len(stk2) == 0 :continue
            if c == '#': stk2.pop()
            else : stk2.append(c)
        if stk1 == stk2 : return True
        return False
if __name__ == '__main__':
    a = "a##c"
    b = "#a#c"
    solution = characterStringBackspaceCompareStack()
    ans = solution.backspaceCompare(a,b)
    print(True if ans else False)
