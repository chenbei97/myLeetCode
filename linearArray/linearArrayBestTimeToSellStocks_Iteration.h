#ifndef linearArrayBestTimeToSellStocksIteration_
#define linearArrayBestTimeToSellStocksIteration_
#include <vector>
#include <iostream>
using namespace std;
class linearArrayBestTimeToSellStocksIteration{
    public:
    // 这道题是股票买卖最佳时机I,只需要考虑某一天买入后面何时卖出利润最大即可
        int maxProfit_violentIteration(const vector<int>& prices){
            int maxProfit = 0;
            for(int i=0;i<prices.size()-1;i++){
                for(int j=i+1;j<prices.size();j++){
                    if ( prices[j]-prices[i]>maxProfit ) // 暴力迭代,每个价格都轮流和后面所有的价格都比1遍
                        maxProfit = prices[j]-prices[i];
                }
            }
            return maxProfit;
        }
        int maxProfit_oneIteration(const vector<int>& prices){
            int minPrice = INT_MAX;
            int maxProfit = 0;
            for(auto price:prices){//一次迭代,先更新历史最低点,比较后面某天和历史最低点的差值即可
                minPrice = min(price,minPrice); // 最低点必要的话会更新 
                maxProfit = max(price-minPrice,maxProfit);
            }
            return maxProfit;
        }
};
void _linearArray_bestTimeToSellStocks_iteration(){
    linearArrayBestTimeToSellStocksIteration solution;
    vector<int> prices={15,1,6,9,6,3,8,11,7};
    auto ans = solution.maxProfit_violentIteration(prices);
    cout<<"I:violent iteration=>the best profit is "<<ans<<endl;
    ans = solution.maxProfit_oneIteration(prices);
    cout<<"I:one iteration=>the best profit is "<<ans<<endl;
}
#endif // !linearArrayBestTimeToSellStocksIteration_