class characterStringBackspaceCompareString:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def rebuild(s):
            ans = []
            for c in s :
                if c != '#':
                    ans.append(c)
                elif len(ans):
                    ans.pop()
            return ans
        return rebuild(s) == rebuild(t)
if __name__ == '__main__':
    a = "a##c"
    b = "#a#c"
    solution = characterStringBackspaceCompareString()
    ans = solution.backspaceCompare(a,b)
    print(True if ans else False)