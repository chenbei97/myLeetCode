'''
Author: chenbei
Date: 2022-03-03 11:12:58
LastEditTime: 2022-03-16 08:04:49
Description: string backspace by double pointers
FilePath: \myLeetCode\characterString\characterStringBackspaceCompare_DoublePointers.py
A boy without dreams
'''
class characterStringBackspaceCompareDoublePointers:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s1,s2 = len(s)-1,len(t)-1
        skip1,skip2=0,0
        while s1>=0 and s2>=0:
            while s1>=0:
                if s[s1] == '#':
                    skip1 += 1
                    s1 -= 1
                else:
                    if skip1 != 0:
                        skip1 -= 1
                        s1 -= 1
                    else : break
            while s2>=0:
                if t[s2] == '#':
                    skip2 += 1
                    s2 -= 1
                else:
                    if skip2 != 0:
                        skip2 -= 1
                        s2 -= 1
                    else : break
            if s2>=0 and s1>=0:
                if s[s1]!=t[s2]:return False
            else: 
                if s2>=0 or s1>=0:
                    return False
            s1 -= 1
            s2 -= 1
        return True
if __name__ == '__main__':
    a = "a##c"
    b = "#a#c"
    solution = characterStringBackspaceCompareDoublePointers()
    ans = solution.backspaceCompare(a,b)
    print(True if ans else False)       
            
            