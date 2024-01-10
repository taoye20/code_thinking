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

//创建树
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

//遍历树
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
	////第一思想，递归法
	//TreeNode* invertTree(TreeNode* root) {
	//	if (root == NULL) return root;
	//	swap(root->left, root->right);
	//	invertTree(root->left);
	//	invertTree(root->right);
	//	return root;
	//}

	//TreeNode* invertTree(TreeNode* root) {
	//	if (root == NULL) return root;
	//	swap(root->left, root->right);
	//	invertTree(root->left);
	//	invertTree(root->right);
	//	return root;
	//}

	//第二思想，遍历，前序遍历
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return root;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			TreeNode* cur = st.top();
			st.pop();
			swap(cur->left, cur->right);
			if (cur->right) st.push(cur->right);
			if (cur->left) st.push(cur->left);
		}
		return root;
	}

	//TreeNode* invertTree(TreeNode* root) {
	//	stack<TreeNode*> st;
	//	st.push(root);
	//	while (!st.empty()) {
	//		TreeNode* cur = st.top();
	//		st.pop();
	//		swap(cur->left, cur->right);
	//		if()
	//	}
	//	return root;
	//}

	////第三，层序遍历
	//TreeNode* invertTree(TreeNode* root) {
	//	queue<TreeNode*> que;
	//	if (root != NULL) que.push(root);
	//	while (!que.empty()) {
	//		int size = que.size();
	//		for (int i = 0; i < size; i++) {
	//			TreeNode* node = que.front();
	//			que.pop();
	//			swap(node->left, node->right); // 节点处理
	//			if (node->left) que.push(node->left);
	//			if (node->right) que.push(node->right);
	//		}
	//	}
	//	return root;
	//}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	TreeNode* result = solution.invertTree(root);
	vector<vector<int>> res = order.levelOrder(result);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
