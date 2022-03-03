class characterStringValidParenthesesStack:
    def isValid(self,s:str)->bool:
        if len(s)%2 == 1: return False
        d = dict()
        d.update({")":"("})
        d.update({"]":"["})
        d.update({"}":"{"})
        stk = []
        for c in s:
            if c in d.keys(): # 右括号才会在字典的键里
                if len(stk)==0 or stk[-1]!=d[c]: # 右括号没和栈顶元素的左括号匹配或者栈空
                    return False
                stk.pop() # 匹配则清除
            else:
                stk.append(c)
        return False if len(stk) else True
if __name__ == '__main__':
    string = '({[]})([]){}'
    solution = characterStringValidParenthesesStack()
    ans = solution.isValid(string)
    print("valid" if ans else "invalid")