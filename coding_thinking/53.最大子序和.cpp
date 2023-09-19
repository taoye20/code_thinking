#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /*int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (maxSum < sum) maxSum = sum;
            }
        }
        return maxSum;
    }*/

    //以下为贪心算法
    int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
            if (count > result) result = count;
            if (count < 0) count = 0;
        }
        return result;
    }
}solution;

int main() {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    int res = solution.maxSubArray(nums);
    cout << res << endl;
    return 0;
}