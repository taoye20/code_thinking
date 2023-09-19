#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
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
	//int result;
	//int max_depth = INT_MIN;
	//void travelsal(TreeNode* root, int depth) {
	//	if (root == NULL) return;
	//	if (root->left == NULL && root->right == NULL) {
	//		if (depth > max_depth) {
	//			max_depth = depth;
	//			result = root->val;
	//		}
	//	}
	//	travelsal(root->left, depth + 1);
	//	travelsal(root->right, depth + 1);
	//}

	//int findBottomLeftValue(TreeNode* root) {
	//	if (root == NULL) return root->val;
	//	travelsal(root, 0);
	//	return result;
	//}

	//层序遍历法
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		int res;
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				if (i == 0) res = cur->val;
				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
		}
		return res;
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	int result = solution.findBottomLeftValue(root);
	cout << result << endl;
	return 0;
}


