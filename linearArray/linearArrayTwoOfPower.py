class linearArrayTwoOfPower:
    def __init__(self) -> None:
        self.idx = -1
    def isPowerOfTwo_iteration(self,num:int)->bool:
        x = 0
        while 1:
            if pow(2,x) == num:
                self.idx = x
                return True
            if pow(2,x) <num:
                x += 1
            else:
                return False
    def isPowerOfTwo_recursion(self,num:int)->bool:
        def loop(x):
            if pow(2,x) == num :
                self.idx = x
                return True
            if pow(2,x)<num:
                loop(x+1)
            else: return False
        return loop(0)
    def isPowerOfTwo_bit1(self,num:int)->bool:
        if num<1:return False
        if not num&(num-1): 
            self.idx = len(bin(num))-3
            return True
        return False
    def isPowerOfTwo_bit2(self,num:int)->bool:
        if num<1:return False
        if int(num&(-num)) == num: 
            self.idx = len(bin(num))-3
            return True
        return False
    def printIdx(self)->int:
        return self.idx
if __name__ == '__main__':
    solution = linearArrayTwoOfPower()
    ans = solution.isPowerOfTwo_iteration(1024)
    print(solution.printIdx())
    ans = solution.isPowerOfTwo_recursion(4096)
    print(solution.printIdx())
    ans = solution.isPowerOfTwo_bit1(512)
    print(solution.printIdx())
    ans = solution.isPowerOfTwo_bit2(32)
    print(solution.printIdx())