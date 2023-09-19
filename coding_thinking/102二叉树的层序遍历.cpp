#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//´´½¨Ê÷
class BuildTree {
public:
	TreeNode* build() {
		TreeNode* root = new TreeNode(1);

		TreeNode* leftnode = new TreeNode(2);
		TreeNode* rightnode = new TreeNode(3);
		root->left = leftnode;
		root->right = rightnode;

		TreeNode* cur = root->left;
		cur->left = new TreeNode(4);
		cur->right = new TreeNode(5);

		return root;
	}
};


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> res;
		while (!que.empty()) {
			vector<int> vec;
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				vec.push_back(cur->val);
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
				que.pop();
			}
			res.push_back(vec);
		}
		return res;
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	vector<vector<int>> res = solution.levelOrder(root);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << endl;
		}
	}
	return 0;
}
