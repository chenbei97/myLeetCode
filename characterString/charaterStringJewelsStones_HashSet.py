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