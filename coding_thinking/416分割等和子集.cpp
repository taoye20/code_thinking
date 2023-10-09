#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (sum % 2 == 1) return false;
        int weight = sum / 2;
        vector<int> dp(weight + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = weight; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[weight] == weight) return true;
        else return false;
    }
}solution;

int main() {
    vector<int> nums = { 1,5,11,5 };
    cout << solution.canPartition(nums) << endl;
    return 0;
}