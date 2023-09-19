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
	//bool travelsor(TreeNode* root, int count) {
	//	if (root == NULL && count == 0) return true;
	//	else if (root == NULL) return false;
	//	bool is_left = travelsor(root->left, count - root->val);
	//	bool is_right = travelsor(root->right, count - root->val);
	//	return is_left || is_right;
	//}

	//以上做法会导致一个问题，即如果一个节点只有右枝或左枝，而此时刚好count为0，那么就会返回错误，因为该节点不是叶子节点
	bool travelsor(TreeNode* root, int count) {
		if (root == NULL) return false;
		if (!root->left && !root->right && count - root->val == 0) return true;
		return travelsor(root->left, count - root->val) || travelsor(root->right, count - root->val);
	}

	//113路径总和2
	void travelsor2(TreeNode* root, vector<int>& road, vector<vector<int>>& res, int count) {
		if (root == NULL) return;
		if (!root->left && !root->right && count - root->val == 0) {
			road.push_back(root->val);
			res.push_back(road);
			road.pop_back();
			return;
		}
		road.push_back(root->val);
		travelsor2(root->left, road, res, count - root->val);
		travelsor2(root->right, road, res, count - root->val);
		road.pop_back();
	}

	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL) return false;
		return travelsor(root, sum);
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	vector<vector<int>> res;
	vector<int> road;
	bool result = solution.hasPathSum(root, 8);
	solution.travelsor2(root, road, res, 8);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << result << endl;
	return 0;
}


