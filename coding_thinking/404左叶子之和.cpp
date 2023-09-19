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
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;
		int v = 0;
		if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
			v = root->left->val;
		}
		int leftvalue = sumOfLeftLeaves(root->left);
		int rightvalue = sumOfLeftLeaves(root->right);
		return leftvalue + rightvalue + v;
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	int result = solution.sumOfLeftLeaves(root);
	cout << result << endl;
	return 0;
}


