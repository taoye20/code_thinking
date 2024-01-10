#include<iostream>
#include<vector>
using namespace std;

//void backtracking(参数) {
//    if (终止条件) {
//        存放结果;
//        return;
//    }
//
//    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
//        处理节点;
//        backtracking(路径，选择列表); // 递归
//        回溯，撤销处理结果
//    }
//}

class Solution {
public:
	//vector<int> path;
	//vector<vector<int>> res;
	//void backtracking(int n, int k, int startIndex) {
	//	if (path.size() == k) {
	//		res.push_back(path);
	//		return;
	//	}
	//	for (int i = startIndex; i <= n; i++) {
	//		path.push_back(i);
	//		backtracking(n, k, i + 1);
	//		path.pop_back();
	//	}
	//}

	vector<vector<int>> res;
	vector<int> path;
	void backtracking(int n, int k, int startIndex) {
		if (path.size() == k) {
			res.push_back(path);
			return;
		}

		for (int i = startIndex; i <= n; i++) {
			path.push_back(i);
			backtracking(n, k, i + 1);
			path.pop_back();
		}
	}

	vector<vector<int>> combine(int n, int k) {
		backtracking(n, k, 1);
		return res;
	}
}solution;

int main() {
	int n = 4;
	int k = 2;
	vector<vector<int>> res = solution.combine(n, k);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}