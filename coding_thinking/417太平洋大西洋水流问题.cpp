#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y) {
        if (visited[x][y]) return;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nextx >= heights.size() || nexty < 0 || nexty >= heights[0].size()) continue;
            if (heights[nextx][nexty] < heights[x][y]) continue;
            dfs(heights, visited, nextx, nexty);
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int n = heights.size();
        int m = heights[0].size();

        // 记录从太平洋边出发，可以遍历的节点
        vector<vector<bool>> pacific = vector<vector<bool>>(n, vector<bool>(m, false));

        // 记录从大西洋出发，可以遍历的节点
        vector<vector<bool>> atlantic = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, n - 1, i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) result.push_back({ i, j });
            }
        }
        return result;
    }
}solution;

int main() {
    vector<vector<int>> heights = { {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4} };
    vector<vector<int>> res = solution.pacificAtlantic(heights);
    for (vector<int> vec : res) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}