from typing import List
class linearArrayBestTimeToSellStocksDynamicProgramming:
    def profit(self,prices:List)->int:
        import numpy as np
        n = len(prices)
        dp = np.zeros((n,2)) # 动态转移方程,第1列记录当前没有股票的利润,第2列记录有1个股票的利润
        dp[0][0],dp[0][1] = 0,-prices[0] # 第0天没有股票说明啥也没干利润0,第0天有股票,说明买了,利润是成本
        for i in range(1,n): # 从第1天开始算
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]) # 今天没股票的原因是前一天没股票利润不变,也可能是今天卖了股票
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i])# 今天有1个股票可能是前一天就有股票不卖也可以是今天买了股票作为成本
        return int(dp[n-1][0])
    def profit_new(self,prices:List)->int:
        # 由于今天只和前一天有关系,更早状态无需存储,可以直接更新
        n = len(prices)
        dp0,dp1 = 0,-prices[0]
        for i in range(1,n):
            dp0 = max(dp0,dp1+prices[i]) # 只和前一天有关,今天卖了股票或者前一天没股票
            dp1 = max(dp1,dp0-prices[i]) # 今天买了股票或者前一天没卖股票
        return dp0 # 手上没有股票肯定比有大
if __name__ == '__main__':
    a = [15,1,6,9,6,3,8,11,7]
    solution = linearArrayBestTimeToSellStocksDynamicProgramming()
    print("the best profit is ",solution.profit(a))
    print("the best profit is ",solution.profit_new(a))