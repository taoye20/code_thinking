#include<iostream>
#include<vector>
#include<queue>
using namespace std;



class Solution {
public:
    ////深度搜索，使用递归标记完一个大陆
    //int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
    //void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {  //将这片大陆全部标记
    //    for (int i = 0; i < 4; i++) {
    //        int nextx = x + dir[i][0];
    //        int nexty = y + dir[i][1];
    //        if (nextx < 0 || nexty <0 || nextx > grid.size() - 1 || nexty > grid[0].size() - 1) continue;
    //        if (!visited[nextx][nexty] && grid[nextx][nexty] == '1') {
    //            visited[nextx][nexty] = true;
    //            dfs(grid, visited, nextx, nexty);
    //        }
    //    }
    //}

    int dir[4][2] = { 0,1,1,0,-1,0,0,-1 };
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int, int>> que;
        que.push({ x,y });
        while(!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nextx = cur.first + dir[i][0];
                int nexty = cur.second + dir[i][1];
                if (nextx < 0 || nexty <0 || nextx > grid.size() - 1 || nexty > grid[0].size() - 1) continue;
                if (!visited[nextx][nexty] && grid[nextx][nexty] == '1') {
                    visited[nextx][nexty] = true;
                    que.push({ nextx, nexty });
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {  //遇到了新大陆
                    visited[i][j] = true;
                    res++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return res;
    }
}solution;

int main() {

}