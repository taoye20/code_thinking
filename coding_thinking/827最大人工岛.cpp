#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
	int count = 0;
	void dfs(vector<vector<int>>& grid, int mark, int x, int y) {
		if (grid[x][y] == 0 || grid[x][y] > 1) {
			return;
		}
		grid[x][y] = mark;
		count++;
		for (int i = 0; i < 4; i++) {
			int nextx = x + dir[i][0];
			int nexty = y + dir[i][1];
			if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) continue;
			dfs(grid, mark, nextx, nexty);
		}
	}

	int largestIsland(vector<vector<int>>& grid) {
		unordered_map<int, int> map;
		int m = grid.size();
		int n = grid[0].size();
		int mark = 2;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					dfs(grid, mark, i, j);
					if (count == m * n) return m * n;
					map[mark] = count;
					count = 0;
					mark++;
				}
			}
		}

		int res = 0;
		unordered_set<int> set;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] != 0) continue;
				set.clear();
				int num = 1;
				for (int d = 0; d < 4; d++) {
					int nextx = i + dir[d][0];
					int nexty = j + dir[d][1];
					if (nextx < 0 || nexty < 0 || nextx >= m || nexty >= n) continue;
					if (set.find(grid[nextx][nexty]) != set.end()) continue;
					set.insert(grid[nextx][nexty]);
					num += map[grid[nextx][nexty]];
				}
				res = max(res, num);
			}
		}
		return res;
	}
}solution;

int main() {
	vector<vector<int>> grid = { {1, 1}, {0, 1} };
	cout << solution.largestIsland(grid) << endl;
	return 0;
}