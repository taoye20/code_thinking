#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<unordered_map>
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == p || root == q || root == NULL) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left != NULL && right != NULL) return root;
		else if (left != NULL && right == NULL) return left;
		else if (left == NULL && right != NULL) return right;
		else return NULL;
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	TreeNode* res;
	res = solution.lowestCommonAncestor(root, root->left, root->left->left);
	cout << res->val << endl;
	return 0;
}


