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
public:
	TreeNode* travelsor(vector<int>& nums, int left, int right) {
		if (left > right) return NULL;
		int mid = (left + right) / 2;
		TreeNode* node = new TreeNode(nums[mid]);
		node->left = travelsor(nums, left, mid - 1);
		node->right = travelsor(nums, mid + 1, right);
		return node;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) return NULL;
		return travelsor(nums, 0, nums.size() - 1);
	}
};


int main() {
	vector<int> nums = { -10,-3,0,5,9 };
	Solution solution;
	TreeNode* root = solution.sortedArrayToBST(nums);
	vector<vector<int>> res = order.levelOrder(root);
	for (vector<int> vec : res) {
		for (int i : vec) {
			cout << i << ' ';
		}
		cout << endl;
	}
}