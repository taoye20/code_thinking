#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //dp[i][j]��ʾA��i-1λ��B��j-1λʱ��ͬ���еĳ���
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > res) res = dp[i][j];
            }
        }
        return res;
    }
}solution;

int main() {
    vector<int> nums1 = { 1,2,3,2,1 };
    vector<int> nums2 = { 3,2,1,4,7 };
    cout << solution.findLength(nums1, nums2) << endl;
    return 0;
}