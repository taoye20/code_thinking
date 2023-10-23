#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m_n = 20001;
    vector<int> father = vector<int>(m_n, 0);

    void init() {
        for (int i = 0; i < m_n; i++) {
            father[i] = i;
        }
    }

    int find(int u) {
        if (u == father[u]) return u;
        else return father[u] = find(father[u]);
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        m_n = n;
        init();
        for (vector<int> l : edges) {
            join(l[0], l[1]);
        }
        return isSame(source, destination);
    }
}solution;

int main() {
    vector<vector<int>> edges = { {0, 1}, {0, 2},{3, 5},{5, 4},{4, 3} };
    int n = 6;
    int source = 0;
    int destination = 5;
    cout << solution.validPath(n, edges, source, destination) << endl;
    return 0;
}