#include<iostream>
#include<vector>
using namespace std;

/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。
示例 1: 输入: k = 3, n = 7 输出: [[1,2,4]]

示例 2: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void backtracking(int n, int k, int startIndex) {
		if (n == 0 && path.size() == k) {
			res.push_back(path);
			return;
		}
		else if (path.size() == k) return;

		for (int i = startIndex; i <= 9; i++) {
			n -= i;
			if (n < 0) {
				n += i;
				return;
			}
			path.push_back(i);
			backtracking(n, k, i + 1);
			n += i;
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum3(int k, int n) {
		backtracking(n, k, 1);
		return res;
	}
}solution;

int main() {
	int n = 45;
	int k = 9;
	vector<vector<int>> res = solution.combinationSum3(k, n);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}