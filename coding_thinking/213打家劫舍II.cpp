#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> n1(nums.begin(), nums.end() - 1);
        vector<int> n2(nums.begin() + 1, nums.end());
        int value1 = robRange(n1);
        int value2 = robRange(n2);
        return max(value1, value2);
    }

    int robRange(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
}solution;

int main() {
    vector<int> nums = { 2,3,2 };
    cout << solution.rob(nums) << endl;
    return 0;
}