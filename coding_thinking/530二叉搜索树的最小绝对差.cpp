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
}buildtree;

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
//private:
//	int res = INT_MAX;
//	TreeNode* pre = NULL;
//	void Traversor(TreeNode* cur) {
//		if (cur == NULL) return;
//		Traversor(cur->left);
//		if (pre != NULL) {
//			res = min(res, cur->val - pre->val);
//		}
//		pre = cur;
//		Traversor(cur->right);
//	}
//public:
//	int getMinimumDifference(TreeNode* root) {
//		Traversor(root);
//		return res;
//	}

public:
	int getMinimumDifference(TreeNode* root) {
		stack<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		int res = INT_MAX;
		while (!st.empty() || cur != NULL) {
			if (cur == NULL) {
				cur = st.top();
				st.pop();
				if (pre != NULL) {
					res = min(res, cur->val - pre->val);
				}
				pre = cur;
				cur = cur->right;
			}
			else {
				st.push(cur);
				cur = cur->left;
			}
		}
		return res;
	}
}solution;


int main() {
	TreeNode* root = buildtree.build();
	cout << solution.getMinimumDifference(root) << endl;
	return 0;
}