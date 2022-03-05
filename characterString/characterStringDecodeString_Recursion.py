class characterStringDecodeStringRecursion:
    def __init__(self) -> None:
        self.src = None or str
        self.ptr = None or int
    def decodeString(self,s:str)->str:
        self.src = s
        self.ptr = 0
        return self.getString()
    def getDigits(self)->int:
        ret = 0
        while self.ptr < len(self.src) and self.src[self.ptr].isdigit():
            ret = ret * 10 + ord(self.src[self.ptr]) - ord('0')
            self.ptr += 1
        return ret
    def getString(self) ->str:
        if  self.ptr == len(self.src) or self.src[self.ptr] == ']':
            return ""
        cur,repTime = self.src[self.ptr], 1
        ret = ''
        if cur.isdigit():
            # String -> Digits [ String ] String
            # 解析 Digits
            repTime = self.getDigits()
            # 过滤左括号
            self.ptr += 1
            # 解析 String
            string = self.getString()
            # 过滤右括号
            self.ptr += 1
            # 构造字符串
            while repTime>0:
                ret += string
                repTime -= 1
        elif cur.isalpha():
            # String -> Char String
            # 解析 Char
            ret = self.src[self.ptr]
            self.ptr += 1
        return ret + self.getString()
if __name__ == '__main__':
    solution = characterStringDecodeStringRecursion()
    ans = solution.decodeString("3[a2[c]]2[abc]ddd3[cd]ef") 
    print(ans)