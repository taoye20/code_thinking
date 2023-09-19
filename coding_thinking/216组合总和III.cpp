#include<iostream>
#include<vector>
using namespace std;

/*
�ҳ��������֮��Ϊ n �� k ��������ϡ������ֻ������ 1 - 9 ��������������ÿ������в������ظ������֡�

˵����

�������ֶ�����������
�⼯���ܰ����ظ�����ϡ�
ʾ�� 1: ����: k = 3, n = 7 ���: [[1,2,4]]

ʾ�� 2: ����: k = 3, n = 9 ���: [[1,2,6], [1,3,5], [2,3,4]]
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