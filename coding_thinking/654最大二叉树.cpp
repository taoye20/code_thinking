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
	TreeNode* Traversor(vector<int>& nums, int left, int right) {
		if (left >= right) return NULL;

		int maxNumIndex = left;
		for (int i = left; i < right; i++) {
			if (nums[i] > nums[maxNumIndex]) maxNumIndex = i;
		}

		TreeNode* root = new TreeNode(nums[maxNumIndex]);
		root->left = Traversor(nums, left, maxNumIndex);
		root->right = Traversor(nums, maxNumIndex + 1, right);

		return root;
	}

	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return Traversor(nums, 0, nums.size());
	}
}solution;


int main() {
	vector<int> nums = { 3,2,1,6,0,5 };
	TreeNode* root = solution.constructMaximumBinaryTree(nums);
	vector<vector<int>> res = order.levelOrder(root);
	for (vector<int> v : res) {
		for (int i : v) {
			cout << i << ' ';
		}
		cout << endl;
	}
	return 0;
}