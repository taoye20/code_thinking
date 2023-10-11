#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //与之前的贪心算法不同，这里使用动态规划
    int maxProfit(vector<int>& prices) {
        //解释一下这里的dp，dp[0][j]代表持有股票时，在第j天我的钱数（现实股票中的仓位）。dp[1][j]代表不持有股票时我的钱数，只要使持有股票和不持股票时我的钱数最多，那结果就是最大收益
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            //保持前一天仓位和用钱买入今天股票中选一个操作
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i]);

            //保持前一天钱和卖出股票选一个操作
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]);

            //那么问题来了，我会不会出现，在买入股票以后，又连续虚空的卖出了两次股票，或者在卖出股票以前，又多买了股票呢？
            //初始化时，买股票使得我钱数为负值，在卖出它以前，我再买股票会使得钱数更低，不符合持股时的max原则，因此一定会在卖出后再买入
            //卖出股票使得我真实的钱数，即到手的（未持股）的钱数为正数，在新买入股票并卖出股票以前，该钱数不会比之前的更高，因此不会出现连续两次卖出的情况
        }
        return dp[1][prices.size() - 1];
    }
}solution;

int main() {
    vector<int> prices = { 7,1,5,3,6,4 };
    cout << solution.maxProfit(prices) << endl;
    return 0;
}