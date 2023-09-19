#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出: [ [2], [1], [1,2,2], [2,2], [1,2], [] ]
*/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(const vector<int>& nums, int startIndex, vector<bool> used) {
        res.push_back(path);
        //if (startIndex >= nums.size()) return;
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);
        return res;
    }
}solution;

int main() {
    vector<int> nums = { 1,2,2 };
    vector<vector<int>> res = solution.subsetsWithDup(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//491.递增子序列
//class Solution {
//public:
//    vector<vector<int>> res;
//    vector<int> path;
//    void backtracking(const vector<int>& nums, int startIndex) {
//        if (path.size() >= 2) res.push_back(path);
//        unordered_set<int> set;
//        for (int i = startIndex; i < nums.size(); i++) {
//            if (path.size() != 0 && path.back() > nums[i] || set.find(nums[i]) != set.end()) {
//                continue;
//            }
//            set.insert(nums[i]);
//            path.push_back(nums[i]);
//            backtracking(nums, i + 1);
//            path.pop_back();
//        }
//    }
//    vector<vector<int>> findSubsequences(vector<int>& nums) {
//        backtracking(nums, 0);
//        return res;
//    }
//};
