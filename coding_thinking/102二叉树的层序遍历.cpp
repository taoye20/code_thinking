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


//class TreeNode {
//public:
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};


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


//层序方式创建树
class BuildTreeNum {
public:
	TreeNode* build(vector<int> vec) {
		int size = vec.size();
		vector<TreeNode*> node_vec;
		for (int i = 0; i < size; i++) {
			TreeNode* node = new TreeNode(vec[i]);
			node_vec.push_back(node);
		}

		queue<TreeNode*> que;
		if(node_vec.size() != 0) que.push(node_vec[0]);
		int index = 1;
		while (!que.empty()) {
			int quesize = que.size();
			for (int i = 0; i < quesize; i++) {
				TreeNode* cur = que.front();
				if (index < size) {
					que.push(node_vec[index]);
					cur->left = node_vec[index];
					index++;
					if (index < size) {
						que.push(node_vec[index]);
						cur->right = node_vec[index];
						index++;
					}
				}
				que.pop();
			}
		}
		return node_vec[0];
	}
};



class Solution {
public:
	//层序遍历
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			vector<int> vec;
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* cur = que.front();
				que.pop();
				vec.push_back(cur->val);

				if (cur->left) que.push(cur->left);
				if (cur->right) que.push(cur->right);
			}
			res.push_back(vec);
		}
		return res;
	}


	//前序遍历递归法
	void Traversal1(TreeNode* cur, vector<int>& vec) {
		if (cur == NULL) return;
		vec.push_back(cur->val);
		Traversal1(cur->left, vec);
		Traversal1(cur->right, vec);
	}

	//中序遍历递归
	void Travaersal2(TreeNode* cur, vector<int>& vec) {
		if (cur == NULL) return;
		Travaersal2(cur->left, vec);
		vec.push_back(cur->val);
		Travaersal2(cur->right, vec);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		Traversal1(root, res);
		return res;
	}

	//迭代遍历树
	//前序
	vector<int> perorder(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			TreeNode* cur = st.top();
			st.pop();
			res.push_back(cur->val);
			if (cur->right) st.push(cur->right);
			if (cur->left) st.push(cur->left);
		}
		return res;
	}

	//中序
	vector<int> midorder(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		while (cur != NULL || !st.empty()) {
			if (cur != NULL) {
				st.push(cur);
				cur = cur->left;
			}
			else {
				cur = st.top();
				res.push_back(cur->val);
				st.pop();
				cur = cur->right;
			}
		}
		return res;
	}

	//后序
	vector<int> perorder(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			TreeNode* cur = st.top();
			st.pop();
			res.push_back(cur->val);
			if (cur->left) st.push(cur->left);
			if (cur->right) st.push(cur->right);
		}
		reverse(res.begin(), res.end());
		return res;
	}
}solution;


//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		queue<TreeNode*> que;
//		if (root != NULL) que.push(root);
//		vector<vector<int>> res;
//		while (!que.empty()) {
//			vector<int> vec;
//			int size = que.size();
//			for (int i = 0; i < size; i++) {
//				TreeNode* cur = que.front();
//				vec.push_back(cur->val);
//				if (cur->left) que.push(cur->left);
//				if (cur->right) que.push(cur->right);
//				que.pop();
//			}
//			res.push_back(vec);
//		}
//		return res;
//	}
//}solution;


int main() {
	BuildTreeNum buildtree;
	vector<int> vec = { 1, 2, 3, 4, 5 };
	TreeNode* root = buildtree.build(vec);
	vector<vector<int>> res = solution.levelOrder(root);
	for (vector<int> i : res) {
		for (int j : i) {
			cout << j;
		}
		cout << endl;
	}
	return 0;
}
