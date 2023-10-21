#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& count) {
        bool isIsland = true;
        for (int i = 0; i < 4; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nexty <0 || nextx > grid.size() - 1 || nexty > grid[0].size() - 1) {
                isIsland = false;
                count = 0;
                continue;
            }
            if (!visited[nextx][nexty] && grid[nextx][nexty]) {
                visited[nextx][nexty] = true;
                count++;
                isIsland = (isIsland && dfs(grid, visited, nextx, nexty, count));
            }
        }
        if (!isIsland) count = 0;
        return isIsland;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), 0));
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j]) {
                    visited[i][j] = true;
                    int count = 1;
                    if (dfs(grid, visited, i, j, count)) {
                        res += count;
                    }
                }
            }
        }
        return res;
    }
}solution;

int main() {
    vector<vector<int>> grid = { {0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0} };
    cout << solution.numEnclaves(grid) << endl;
    return 0;
}
