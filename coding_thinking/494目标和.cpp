#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (target > sum) return 0;
        if ((sum + target) % 2) return 0;
        int bagSize = (sum + target) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
}solution;

int main() {
    vector<int> nums(5, 1);
    cout << solution.findTargetSumWays(nums, 3) << endl;
    return 0;
}