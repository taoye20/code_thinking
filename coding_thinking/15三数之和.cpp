#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意： 答案中不可以包含重复的三元组。

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为： [ [-1, 0, 1], [-1, -1, 2] ]
*/


//思路：原本想使用哈希表如同之前的四数相加，但是去重太难，考虑双指针
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int i = 0; //起始位置指针，代表a
		int left = 1;  //代表b
		int right = nums.size() - 1;  //代表c
		vector<vector<int>> res;

		//关键点1，先排序
		sort(nums.begin(), nums.end());
		for (; i < nums.size() - 2; i++) {
			//关键点2，去重
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			left = i + 1;
			right = nums.size() - 1;
			while (left < right) {
				if (nums[i] + nums[left] + nums[right] == 0) {
					res.push_back({ nums[i], nums[left], nums[right] });
					//去重
					while (right > left && nums[right] == nums[right - 1]) right--;
					while (right > left && nums[left] == nums[left + 1]) left++;
					//找到后，同时缩减范围
					right--;
					left++;
				}
				else if (nums[i] + nums[left] + nums[right] > 0) {
					right--;
				}
				else {
					left++;
				}
			}
		}
		return res;
	}
}solution;

int main() {
	vector<int> nums = { 0, 0, 0, 0 };
	vector<vector<int>> res = solution.threeSum(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}