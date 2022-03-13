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