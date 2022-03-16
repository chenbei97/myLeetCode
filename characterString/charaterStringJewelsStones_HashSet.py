'''
Author: chenbei
Date: 2022-03-14 07:52:14
LastEditTime: 2022-03-16 08:13:17
Description: judge stone is jewel by hashSet
FilePath: \myLeetCode\characterString\charaterStringJewelsStones_HashSet.py
A boy without dreams
'''
class charaterStringJewelsStonesHashSet:
    def numJewelsInStones(self,jewels:str, stones:str)->int:
        s = set()
        for c in jewels:
            s.add(c)
        n = 0
        for c in stones:
            if c in s:
                n += 1
        return n
if __name__ == '__main__':
    jewels = 'aAFs'
    stones = 'abcAABCDDefFsSa'
    soluton = charaterStringJewelsStonesHashSet()
    print(soluton.numJewelsInStones(jewels,stones))