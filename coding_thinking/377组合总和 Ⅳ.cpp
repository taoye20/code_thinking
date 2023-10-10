#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;

        //组合和排列的for循环顺序是不同的，需要用心体会，该题为排列
        //可以想象成，当包容量为多少时，挑选不同的物品尝试放入
        //而如果是组合，(1,3)和(3,1)是不允许同时存在的，那么就按照物品遍历，先尝试物品1放入各种大小的包的路径数，再考虑下一个物品
        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (j >= nums[i]) dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
}solution;

int main() {
    vector<int> nums = { 1,2,3 };
    int target = 4;
    cout << solution.combinationSum4(nums, target) << endl;
    return 0;
}