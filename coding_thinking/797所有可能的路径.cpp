#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<vector<int>>& graph, int node) {
        if (node == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            path.push_back(graph[node][i]);
            backtracking(graph, graph[node][i]);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        backtracking(graph, 0);
        for (int i = 0; i < res.size(); i++) {
            res[i].insert(res[i].begin(), 0);
        }
        return res;
    }
}solution;

int main() {
    vector<vector<int>> graph = { {1,2},{3},{3},{} };
    vector<vector<int>> res = solution.allPathsSourceTarget(graph);
    for (vector<int> vec : res) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}