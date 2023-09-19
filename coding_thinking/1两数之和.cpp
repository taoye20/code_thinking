#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9

所以返回 [0, 1]
*/

class Solution {
public:
	//使用数组的方法实现，时间复杂度为O(nlog(n))
	vector<int> twoSum01(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size() - 1; i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) return vector<int>{i, j};
			}
		}
		return {};
	}

	//使用哈希表的方法，因为哈希表的find复杂度为O(1),因此总复杂度为O(n)。
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			unordered_map<int, int>::iterator iter = map.find(target - nums[i]);  //反向查找已经存入的key中有没有合适的值
			if (iter != map.end()) {
				return vector<int>{iter->second, i};  //return vector<int>{map[target - nums[i]]}
			}
			else {
				map.insert(pair<int, int>(nums[i], i));  //map中的key为要查找的值，map中的value为数组位置的编号
			}
		}
		return {};  //如果都没有
	}
}solution;

int main() {
	vector<int> nums = { 2, 7, 11, 16 };
	int target = 9;
	vector<int> tar = solution.twoSum(nums, target);
	for (vector<int>::iterator it = tar.begin(); it != tar.end(); it++) {
		cout << *it << "";
	}
	cout << endl;
}