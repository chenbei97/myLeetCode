'''
Author: chenbei
Date: 2022-03-05 11:27:58
LastEditTime: 2022-03-16 08:07:24
Description: string decode by iteration
FilePath: \myLeetCode\characterString\characterStringDecodeString_Iteration.py
A boy without dreams
'''
class characterStringDecodeStringIteration:
    def decodeString(self,s:str)->str:
        headIdx,tailIdx=[],[]
        for i in range(len(s)):
            if (s[i]=='['):
                headIdx.append(i)
            if (s[i] == ']'):
                tailIdx.append(i)
        # print(headIdx,tailIdx)
        k = list(s)
        for head,tail in zip(headIdx,tailIdx):
            substr = (int(s[head-1])-1)*s[head+1:tail]
            for j in range(len(substr)):
                k.insert(tail+1+j,substr[j])
        ans = []
        for c in k:
            if not c.isdigit() and c  not in '[]':
                ans.append(c)
        return ''.join(ans)
if __name__ == '__main__':
    solution = characterStringDecodeStringIteration()
    ans = solution.decodeString("2[abc]ddd3[cd]ef") # 不适用于多嵌套 "3[a2[c]]"
    print(ans)