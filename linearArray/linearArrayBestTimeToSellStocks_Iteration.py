from cmath import inf
from typing import List
class linearArrayBestTimeToSellStocksIteration:
    def profit_violentIteration(self,prices:List)->int:
        maxProfit = 0
        for i in range(len(prices)-1):
            for j in range(i+1,len(prices)):
                # print(prices[i],prices[j])
                profit = prices[j]-prices[i]
                if profit>0 and  profit>maxProfit: # 其实大于0的判断可以省略
                    maxProfit = profit
        return maxProfit
    def profit_oneIteration(self,prices:List)->int:
        minPrice = inf
        maxProfit = 0
        for price in prices:
            minPrice = min(price,minPrice)
            maxProfit = max(price-minPrice,maxProfit)
        return maxProfit

if __name__ == '__main__':
    a = [15,1,6,9,6,3,8,11,7]
    solution = linearArrayBestTimeToSellStocksIteration()
    print("the best profit is ",solution.profit_violentIteration(a))
    print("the best profit is ",solution.profit_oneIteration(a))