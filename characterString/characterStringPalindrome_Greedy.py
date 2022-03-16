'''
Author: chenbei
Date: 2022-03-04 13:12:50
LastEditTime: 2022-03-16 08:11:55
Description: check string is palindrome by greedy
FilePath: \myLeetCode\characterString\characterStringPalindrome_Greedy.py
A boy without dreams
'''
class characterStringPalindromeGreedy:
    def validPalindrome(self,s:str)->bool:
        head,tail = 0,len(s)-1
        while head<tail:
            if s[head]!=s[tail]:
                return self.checkPalindrome(s,head,tail-1)\
                    or self.checkPalindrome(s,head+1,tail)
            else :
                head += 1
                tail -= 1
        return True
    def checkPalindrome(self,s:str,head:int,tail:int)->bool:
        while head<tail:
            if s[head]!=s[tail]:
                return False
            head += 1
            tail -= 1
        return True
if __name__ == '__main__':
    solution = characterStringPalindromeGreedy()
    s = 'abcdeffdcba'
    ans = solution.validPalindrome(s)
    print(True if ans else False)