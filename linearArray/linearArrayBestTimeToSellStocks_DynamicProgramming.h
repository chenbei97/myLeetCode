#ifndef linearArrayBestTimeToSellStocksDynamicProgramming_
#define linearArrayBestTimeToSellStocksDynamicProgramming_
#include <vector>
#include <iostream>
using namespace std;
class linearArrayBestTimeToSellStocksDynamicProgramming{
    public:
    // 这道题是股票买卖最佳时机II,可以进行买卖，但是买之前手上不能有股票,找到最大利润
        int maxProfit(const vector<int>& prices){
           const int n = prices.size();
           int dp[n][2]; // 动态转移方程,第1列记录当前没有股票的利润,第2列记录有1个股票的利润
           dp[0][0]=0;dp[0][1]=-prices[0];//第0天没有股票说明啥也没干利润0,第0天有股票,说明买了,利润是成本
           for(int i=1;i<n;i++){ // 从第1天开始算
               dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);//今天没股票的原因是前一天没股票利润不变,也可能是今天卖了股票
               dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);// 今天有1个股票可能是前一天就有股票不卖也可以是今天买了股票作为成本
           }
           return dp[n-1][0];
        }
        int maxProfit_new(const vector<int>&prices){
            int n = prices.size();
            int dp0=0,dp1=-prices[0];
            for(int i=1;i<n;i++){
                dp0 = max(dp0,dp1+prices[i]);
                dp1 = max(dp1,dp0-prices[i]);
            }
            return dp0;
        }

};
void _linearArray_bestTimeToSellStocks_dynamicProgramming(){
    linearArrayBestTimeToSellStocksDynamicProgramming solution;
    vector<int> prices={15,1,6,9,6,3,8,11,7};
    auto ans = solution.maxProfit(prices);
    cout<<"II:dynamicProgramming=>the best profit is "<<ans<<endl;
    ans = solution.maxProfit_new(prices);
    cout<<"II:dynamicProgramming=>the best profit is "<<ans<<endl;
}
#endif // !linearArrayBestTimeToSellStocksDynamicProgramming_