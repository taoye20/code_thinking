#include<iostream>
#include<vector>
using namespace std;

//使用回溯的方法，但是代码量大，而且容易超时
//class Solution {
//public:
//	vector<int> path;
//	vector<int> res;
//	int resValue = 0;
//	void traversal(int startIndex, int weight, int value, vector<int>& n_weight, vector<int>& n_value) {
//		for (int i = startIndex; i < n_weight.size(); i++) {
//			weight -= n_weight[i];
//			value += n_value[i];
//			if (weight < 0) {
//				weight += n_weight[i];
//				value -= n_value[i];
//				if (value > resValue) {
//					resValue = value;
//					res = path;
//				}
//				return;
//			}
//			tarversal(startIndex + 1, weight, value, n_weight, n_value);
//			weight += n_weight[i];
//			value -= n_value[i];
//		}
//	}
//
//	int back(int weight, vector<int>& n_weight, vector<int>& n_value) {
//		traversal(0, weight, 0, n_weight, n_value);
//		return resValue;
//	}
//}solution;

//背包问题为动态规划问题
//dp为二维数组i，j为行列数，行代表第i个物品，列表示占用的容积j，dp中的值代表价值
//那么递推公式可以写成.1,不放置物品i：dp[i][j] = dp[i-1][j]. 2,放置物品i；dp[i][j] = dp[i-1][j-weight[i]] + value[i];
//class Solution {
//public:
//	int bag(int bagWeight, vector<int> weight, vector<int> value) {
//		vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
//		for (int i = weight[0]; i <= bagWeight; i++) {
//			dp[0][i] = value[0];
//		}
//		for (int i = 1; i < weight.size(); i++) {
//			for (int j = 1; j <= bagWeight; j++) {
//				if (j < weight[i]) continue;
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//			}
//		}
//		return dp[weight.size() - 1][bagWeight];
//	}
//}solution;

//一维表达该动态规划，时刻记住dp的含义代表的东西是什么
class Solution {
public:
	int bag(int bagWeight, vector<int> weight, vector<int> value) {
		vector<int> dp(bagWeight + 1, 0);
		for (int i = 0; i < weight.size(); i++) {
			for (int j = bagWeight; j >= weight[i]; j--) {  //j--是因为在同一行进行操作，导致了覆盖上行的数据，以至于顺序赋值会出现错误
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);  //相当于扫描每一件物品去更新背包中的价值
			}
		}
		return dp[bagWeight];
	}
}solution;


int main() {
	vector<int> n_weight = { 1,3,4 };
	vector<int> n_value = { 15,20,30 };
	cout << solution.bag(4, n_weight, n_value) << endl;
	return 0;
}