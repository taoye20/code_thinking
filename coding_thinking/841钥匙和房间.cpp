#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int key) {
        if (visited[key]) {
            return;
        }
        visited[key] = true;
        for (int i = 0; i < rooms[key].size(); i++) {
            dfs(rooms, visited, rooms[key][i]);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        for (bool b : visited) {
            if (!b) return false;
        }
        return true;
    }
}solution;

int main() {
    vector<vector<int>> rooms = { {1, 3}, {3, 0, 1}, {2}, {0} };
    cout << solution.canVisitAllRooms(rooms) << endl;
    return 0;
}