#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int m_n = 10000;
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
		if (u == v) return true;
		else return false;
	}

	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		else father[v] = u;
	}

	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		m_n = edges.size() * 2;
		init();
		for (int i = 0; i < edges.size(); i++) {
			if (isSame(edges[i][0], edges[i][1])) return edges[i];
			join(edges[i][0], edges[i][1]);
		}
		return {};
	}
}solution;

int main() {
	vector<vector<int>> edges = { {1, 2}, {1, 3}, {2, 3} };
	vector<int> res = solution.findRedundantConnection(edges);
	for (int i : res) {
		cout << i << endl;
	}
	return 0;
}