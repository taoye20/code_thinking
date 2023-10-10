#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//价值问题
	int test_CompletePack(vector<int>& weight, vector<int>& value, int bagSize) {
		vector<int> dp(bagSize + 1, 0);
		for (int i = 0; i < weight.size(); i++) {
			for (int j = weight[i]; j <= bagSize; j++) {
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
		return dp[bagSize];
	}

	//路径数问题
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < coins.size(); i++) {
			for (int j = coins[i]; j <= amount; j++) {
				dp[j] += dp[j - coins[i]];
			}
		}
		return dp[amount];
	}
}solution;



int main() {
	vector<int> weight = { 1,3,4 };
	vector<int> value = { 15,20,30 };
	int bagSize = 4;
	cout << solution.test_CompletePack(weight, value, bagSize) << endl;
	return 0;
}