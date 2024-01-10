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
	//但是如果数值是两位数，那么pop一次显然就不合理了，下面推荐第二种方式
	void traversal_1(TreeNode* cur, vector<int>& vec, vector<string>& res) {
		vec.push_back(cur->val);  //注意这里的逻辑，要先push中间的再判断
		if (cur->left == NULL && cur->right == NULL) {
			string s;
			for (int i = 0; i < vec.size() - 1; i++) {
				s += to_string(vec[i]);
				s += "->";
			}
			s += to_string(vec[vec.size() - 1]);
			res.push_back(s);
			return;
		}
		if (cur->left) {
			traversal_1(cur->left, vec, res);
			vec.pop_back();  //回溯跟着递归走！
		}
		if (cur->right) {
			traversal_1(cur->right, vec, res);
			vec.pop_back();
		}
	}

	//void traversal(TreeNode* cur, string s, vector<string>& res) {
	//	s += to_string(cur->val);
	//	if (cur->left == NULL && cur->right == NULL) {
	//		res.push_back(s);
	//		return;
	//	}
	//	if (cur->left) traversal(cur->left, s + "->", res);
	//}

	//vector<string> binaryTreePaths(TreeNode* root) {
	//	vector<string> res;
	//	string s;
	//	traversal(root, s, res);
	//	return res;
	//}

	void traversal(TreeNode* cur, string s, vector<string>& res) {
		s += to_string(cur->val);
		if (cur->left == NULL && cur->right == NULL) {
			res.push_back(s);
			return;
		}
		if (cur->left) traversal(cur->left, s + "->", res);
		if (cur->right) traversal(cur->right, s + "->", res);
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		string s;
		if (root == NULL) return res;
		traversal(root, s, res);
		return res;
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	vector<string> result = solution.binaryTreePaths(root);
	for (string s : result) {
		cout << s << endl;
	}
	return 0;
}


