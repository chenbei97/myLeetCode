from typing import List
class linearArrayBestTimeToSellStocksGreedy:
    def profit(self,prices:List)->int:
        '''
        只要第2天相比于前1天买入的成本卖有的赚就可以卖,否则就不卖
        虽然直觉上这样做不一定就能最大化,但是这道题确实可以证明这种直觉是对的
        同时贪心算法只能用于计算最大利润,计算的过程并不是实际的交易过程
        '''
        ans = 0
        n = len(prices)
        for i in range(1,n):
            ans += max(0,prices[i]-prices[i-1])
        return ans

if __name__ == '__main__':
    a = [15,1,6,9,6,3,8,11,7]
    solution = linearArrayBestTimeToSellStocksGreedy()
    print("the best profit is ",solution.profit(a))