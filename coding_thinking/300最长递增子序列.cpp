#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp表示在i为数列末端时最大的递增子序列数
        vector<int> dp(nums.size(), 1); //注意初始化应该所有为1，最少长度为自己
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > res) res = dp[i];  //这才是找到最长序列
        }
        //return dp[nums.size() - 1];  //这样是错误的，因为最后一个数字所在的序列不一定的最长的数列
        return res;
    }
}solution;

int main() {
    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    cout << solution.lengthOfLIS(nums) << endl;
    return 0;
}