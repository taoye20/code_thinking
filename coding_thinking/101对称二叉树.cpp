#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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

//±éÀúÊ÷
class Order {
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
}order;


class Solution {
public:
	//bool compare(TreeNode* left, TreeNode* right) {
	//	if (left == NULL && right == NULL) return true;
	//	else if (left == NULL || right == NULL) return false;
	//	else if (left->val != right->val) return false;
	//	
	//	bool cp1 = compare(left->left, right->right);
	//	bool cp2 = compare(left->right, right->left);
	//	bool res = cp1 && cp2;
	//	return res;
	//}

	//bool isSymmetric(TreeNode* root) {
	//	if (root == NULL) return true;
	//	return compare(root->left, root->right);
	//}

	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		queue<TreeNode*> que;
		que.push(root->left);
		que.push(root->right);

		while (!que.empty()) {
			TreeNode* leftnode = que.front();
			que.pop();
			TreeNode* rightnode = que.front();
			que.pop();
			if (!leftnode && !rightnode) continue;
			if (!leftnode || !rightnode || leftnode->val != rightnode->val) return false;

			que.push(leftnode->left);
			que.push(rightnode->right);
			que.push(leftnode->right);
			que.push(rightnode->left);
		}
		return true;
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	bool result = solution.isSymmetric(root);
	cout << result << endl;
	return 0;
}
