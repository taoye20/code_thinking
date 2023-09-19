#include<iostream>
#include<vector>
using namespace std;

/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
提示：

1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/

class Solution {
public:
	int squ(int s,  vector<int>& a) {
		int result = 0, tmp_len = 0, sum = 0;
		int begin = 0, end = 0;
		for (end; end < a.size(); end++) {
			sum += a[end];
				while (sum >= s) {
					tmp_len = end - begin + 1;
				if (result == 0 || result > tmp_len) result = tmp_len;
				sum -= a[begin++];
			}
		}
		return result;
	}
}solution;

int main() {
	vector<int> a = { 2,3,1,2,4,3 };
	int s = 7;
	int result = solution.squ(s, a);
	cout << "结果：" << result << endl;
	return 0;
}