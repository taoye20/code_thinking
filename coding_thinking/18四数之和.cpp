#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。 满足要求的四元组集合为： [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]

#算法公开课
*/

//在这个程序中，while要特别注意判断条件，避免进入死循环，就比如如果while(nums[c] == nums[c+1] && c<d)不加c<d这个条件，就会出现跑出索引的情况
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int a = 0; a < nums.size(); a++) {
			//剪枝
			if (nums[a] > target && nums[a] >= 0) break;

			//去重
			if (a > 0 && nums[a] == nums[a - 1]) continue;  //注意去重中的continue和while

			for (int b = a + 1; b < nums.size(); b++) {
				if (nums[a] + nums[b] > target && nums[a] + nums[b] >= 0) break;
				if (b > a + 1 && nums[b] == nums[b - 1]) continue;

				int c = b + 1;
				int d = nums.size() - 1;

				while (c < d) {
					if (nums[a] + nums[b] + nums[c] + nums[d] > target) {
						d--;
					}
					else if (nums[a] + nums[b] + nums[c] + nums[d] < target) {
						c++;
					}
					else {
						res.push_back({ nums[a] , nums[b] , nums[c] , nums[d] });

						//去重
						while (nums[c] == nums[c + 1] && c < d) c++;
						while (nums[d] == nums[d - 1] && c < d) d--;

						c++;
						d--;
					}
				}
			}
		}
		return res;
	}
}solution;

int main() {
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	int target = 0;
	vector<vector<int>> res = solution.fourSum(nums, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}