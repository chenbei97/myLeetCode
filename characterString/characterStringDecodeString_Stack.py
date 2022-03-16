'''
Author: chenbei
Date: 2022-03-05 13:30:46
LastEditTime: 2022-03-16 08:08:05
Description: string decode by stack
FilePath: \myLeetCode\characterString\characterStringDecodeString_Stack.py
A boy without dreams
'''
from typing import List
class characterStringDecodeStringStack:
    def __init__(self) -> None:
        self.ptr = None or int
    def decodeString(self,s:str)->str:
        stk = []
        self.ptr = 0
        while self.ptr<len(s):
            cur = s[self.ptr]
            if cur.isdigit():
                # 获取一个数字并进栈
                digtis = self.getDigits(s)
                stk.append(digtis)
            elif cur.isalpha() or cur == '[':
                # 获取一个字母并进栈
                stk.append(s[self.ptr])
                self.ptr += 1
            else:
                self.ptr += 1
                sub = []
                while stk[-1] != '[':
                    sub.append(stk[-1])
                    stk.pop(-1)
                sub.reverse()
                # 左括号出栈
                stk.pop(-1)
                # 此时栈顶为当前 sub 对应的字符串应该出现的次数
                repTime = int(stk[-1])
                stk.pop(-1)
                t,o = '',self.getString(sub)
                # 构造字符串
                while repTime>0:
                    t += o
                    repTime -= 1
                # 将构造好的字符串入栈
                stk.append(t)
        return self.getString(stk)
    def getDigits(self,s:str)->str:
        ret = ''
        while s[self.ptr].isdigit() :
            ret += s[self.ptr]
            self.ptr += 1
        return ret
    def getString(self,vec:List[str])->str:
        ret = ''
        for c in vec :
            ret += c
        return ret 
if __name__ == '__main__':
    solution = characterStringDecodeStringStack()
    ans = solution.decodeString("3[a2[c]]2[abc]ddd3[cd]ef") 
    print(ans)