#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(const vector<int>& nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
}solution;

int main() {
    vector<int> nums = { 1,2,3 };
    vector<vector<int>> res = solution.permute(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

