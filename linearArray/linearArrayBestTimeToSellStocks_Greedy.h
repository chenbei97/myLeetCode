#ifndef linearArrayBestTimeToSellStocksGreedy_
#define linearArrayBestTimeToSellStocksGreedy_
#include <vector>
#include <iostream>
using namespace std;
class linearArrayBestTimeToSellStocksGreedy{
    public:
    // 这道题是股票买卖最佳时机II,可以进行买卖，但是买之前手上不能有股票,找到最大利润
        int maxProfit(const vector<int>& prices){
            /*
            只要第2天相比于前1天买入的成本卖有的赚就可以卖,否则就不卖
            虽然直觉上这样做不一定就能最大化,但是这道题确实可以证明这种直觉是对的
            同时贪心算法只能用于计算最大利润,计算的过程并不是实际的交易过程
            */
            int ans = 0;
            int n = prices.size();
            for (int i = 1; i < n; ++i) {
                ans += max(0, prices[i] - prices[i - 1]);
            }
            return ans;
        }

};
void _linearArray_bestTimeToSellStocks_greedy(){
    linearArrayBestTimeToSellStocksGreedy solution;
    vector<int> prices={15,1,6,9,6,3,8,11,7};
    auto ans = solution.maxProfit(prices);
    cout<<"II:greedy=>the best profit is "<<ans<<endl;
}
#endif // !linearArrayBestTimeToSellStocksGreedy_