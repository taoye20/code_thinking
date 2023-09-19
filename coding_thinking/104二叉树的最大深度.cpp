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
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int leftdep = maxDepth(root->left);
		int rightdep = maxDepth(root->right);
		int depth = 1 + max(leftdep, rightdep);
		return depth;
	}

	//节点数量
	int maxNum(TreeNode* root) {
		if (root == NULL) return 0;
		int leftnum = maxNum(root->left);
		int rightnum = maxNum(root->right);
		int num = leftnum + rightnum + 1;
		return num;
	}

	int Num(TreeNode* root) {
		if (root == NULL) return 0;
		TreeNode* lnode = root->left;
		TreeNode* rnode = root->right;
		int ldepth = 1, rdepth = 1;
		while (lnode) {
			lnode = lnode->left;
			ldepth++;
		}
		while (rnode) {
			rnode = rnode->right;
			rdepth++;
		}
		if (ldepth == rdepth) {
			return pow(2, ldepth) - 1; //2的k次方减一
		}
		return Num(root->left) + Num(root->right) + 1;
	}


	//平衡二叉树判断的函数
	int getHigh(TreeNode* root) {
		if (root == NULL) return 0;

		int lhigh = getHigh(root->left);
		int rhigh = getHigh(root->right);
		if (lhigh == -1 || rhigh == -1) return -1;

		if (abs(lhigh - rhigh) > 1) return -1;
		else return max(lhigh, rhigh) + 1;
	}

	bool isBalanced(TreeNode* root) {
		return getHigh(root) == -1 ? false : true;
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	int result = solution.isBalanced(root);
	cout << result << endl;
	return 0;
}
