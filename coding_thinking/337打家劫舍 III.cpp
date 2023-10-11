#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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
	//vector<vector<int>> levelOrder(TreeNode* root) {
	//	queue<TreeNode*> que;
	//	if (root != NULL) que.push(root);
	//	vector<vector<int>> res;
	//	while (!que.empty()) {
	//		vector<int> vec;
	//		int size = que.size();
	//		for (int i = 0; i < size; i++) {
	//			TreeNode* cur = que.front();
	//			vec.push_back(cur->val);
	//			if (cur->left) que.push(cur->left);
	//			if (cur->right) que.push(cur->right);
	//			que.pop();
	//		}
	//		res.push_back(vec);
	//	}
	//	return res;
	//}

	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		vector<vector<int>> res;
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
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
	//unordered_map<TreeNode*, int> umap;
 //   int rob(TreeNode* root) {
	//	if (root == NULL) return 0;
	//	if (umap[root]) return umap[root];
	//	//抢劫该节点
	//	int val1 = root->val;
	//	if (root->left) val1 += rob(root->left->left) + rob(root->left->right);
	//	if (root->right) val1 += rob(root->right->left) + rob(root->right->right);
	//	//不抢劫该节点
	//	int val2 = rob(root->left) + rob(root->right);
	//	umap[root] = max(val1, val2);
	//	return max(val1, val2);
 //   }
	vector<int> robTree(TreeNode* root) {
		if (root == NULL) return vector<int>(2, 0);
		if (root->left == NULL && root->right == NULL) return vector<int>{root->val, 0};
		vector<int> res(2, 0);
		vector<int> valLeft = robTree(root->left);
		vector<int> valRight = robTree(root->right);
		//抢劫该节点
		res[0] = valLeft[1] + valRight[1] + root->val;
		//不抢劫该节点
		res[1] = max(valLeft[0], valLeft[1]) + max(valRight[0], valRight[1]);
		return res;
	}

	int rob(TreeNode* root) {
		vector<int> res = robTree(root);
		return max(res[0], res[1]);
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	int res = solution.rob(root);
	cout << res << endl;
	return 0;
}

