#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1;
        int curDiff = 0;
        int preDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if ((preDiff >= 0 && curDiff < 0) || (preDiff <= 0 && curDiff > 0)) {
                res++;
                preDiff = curDiff;
            }
        }
        return res;
    }
}solution;

int main() {
    vector<int> nums = { 1,17,5,10,13,15,10,5,16,8 };
    int res = solution.wiggleMaxLength(nums);
    cout << res << endl;
    return 0;
}