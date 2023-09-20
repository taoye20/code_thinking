#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> nums(ratings.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (ratings[i] < ratings[i + 1]) nums[i + 1] = nums[i] + 1;
        }
        for (int j = nums.size() - 1; j > 0; j--) {
            if (ratings[j] < ratings[j - 1]) nums[j - 1] = max(nums[j] + 1, nums[j - 1]);
        }
        for (int n : nums) res += n;
        return res;
    }
}solution;

int main() {
    vector<int> nums = { 1,0,2 };
    int res = solution.candy(nums);
    cout << res << endl;
    return 0;
}
