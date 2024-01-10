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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0) return NULL;

		int rootval = postorder[postorder.size() - 1];
		TreeNode* root = new TreeNode(rootval);
		
		if (postorder.size() == 1) return root;

		int delimiterIndex;
		for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
			if (inorder[delimiterIndex] == rootval) break;
		}

		vector<int> leftinorder(inorder.begin(), inorder.begin() + delimiterIndex);
		vector<int> rightinorder(inorder.begin() + delimiterIndex + 1, inorder.end());

		vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftinorder.size());
		vector<int> rightpostorder(postorder.begin() + leftinorder.size(), postorder.end() - 1);

		root->left = buildTree(leftinorder, leftpostorder);
		root->right = buildTree(rightinorder, rightpostorder);

		return root;
	}
}solution;


int main() {
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> postorder = { 9,15,7,20,3 };
	TreeNode* root = solution.buildTree(inorder, postorder);
	vector<vector<int>> res = order.levelOrder(root);
	for (vector<int> v : res) {
		for (int i : v) {
			cout << i << ' ';
		}
		cout << endl;
	}
	return 0;
}