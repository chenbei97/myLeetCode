class characterStringPalindromeEnum:
    def validPalindrome(self,s:str)->bool:
        defaultLoc = -1 # 缺省位置,从-1开始
        while defaultLoc < len(s):
            t = ''
            for i in range(len(s)):
                if i != defaultLoc:
                    t += s[i]
            print(t)
            ret = self.checkPalindrome(t)
            if ret : return True
            defaultLoc += 1
        return False

    def checkPalindrome(self,s:str)->bool:
        head,tail = 0,len(s)-1
        while head <tail: # 长度奇数时中间的一定相等不需要比
            if s[head] != s[tail]:
                return False
            head += 1
            tail -= 1
        return True


if __name__ == '__main__':
    solution = characterStringPalindromeEnum()
    s = 'abcdeffdcba' # abba
    ans = solution.validPalindrome(s)
    print(True if ans else False)
