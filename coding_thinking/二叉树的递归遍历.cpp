#include<iostream>
#include<vector>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//������
class BuildTree {
public:
	TreeNode* build() {
		TreeNode* root = new TreeNode(1);

		TreeNode* leftnode = new TreeNode(2);
		TreeNode* rightnode = new TreeNode(3);
		root->left = leftnode;
		root->right = rightnode;

		return root;
	}
};


class Solution {
public:
	//ǰ��������ڵ㣬�ݹ鷨
	void traversal(TreeNode* cur, vector<int>& vec) {
		if (cur == NULL) return;
		vec.push_back(cur->val);
		traversal(cur->left, vec);
		traversal(cur->right, vec);
	}

	//�������
	void traversal_mid(TreeNode* cur, vector<int>& vec) {
		if (cur == NULL) return;
		traversal_mid(cur->left, vec);
		vec.push_back(cur->val);
		traversal_mid(cur->right, vec);
	}

	//�������
	void traversal_back(TreeNode* cur, vector<int>& vec) {
		if (cur == NULL) return;
		traversal_back(cur->left, vec);
		traversal_back(cur->right, vec);
		vec.push_back(cur->val);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		//traversal(root, res);
		//traversal_mid(root, res);
		traversal_back(root, res);
		return res;
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	vector<int> res = solution.preorderTraversal(root);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}