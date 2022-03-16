'''
Author: chenbei
Date: 2022-03-14 07:52:14
LastEditTime: 2022-03-16 08:13:41
Description: judge stone is jewel by iteration
FilePath: \myLeetCode\characterString\charaterStringJewelsStones_Iteration.py
A boy without dreams
'''
class charaterStringJewelsStonesIteration:
    def numJewelsInStones(self,jewels:str, stones:str)->int:
        n = 0
        for c in jewels:
            for k in stones:
                if k == c:
                    n += 1
        return n
if __name__ == '__main__':
    jewels = 'aAFs'
    stones = 'abcAABCDDefFsSa'
    soluton = charaterStringJewelsStonesIteration()
    print(soluton.numJewelsInStones(jewels,stones))