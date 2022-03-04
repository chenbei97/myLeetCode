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