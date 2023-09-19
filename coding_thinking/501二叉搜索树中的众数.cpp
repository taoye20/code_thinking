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


//class Solution {
//public:
//	unordered_map<int, int> map;
//	void travelsor(TreeNode* root) {
//		if (root == NULL) return;
//		map[root->val]++;
//		travelsor(root->left);
//		travelsor(root->right);
//	}
//
//	vector<int> findMode(TreeNode* root) {
//		travelsor(root);
//		vector<pair<int, int>> vec(map.begin(), map.end());
//		sort(vec.begin(), vec.end(), [](pair<int, int>a, pair<int, int>b) {return a.second > b.second; });
//		vector<int> res;
//		res.push_back(vec[0].first);
//		for (int i = 1; i < vec.size(); i++) {
//			if (vec[i].second == vec[0].second) res.push_back(vec[i].first);
//			else break;
//		}
//		return res;
//	}
//}solution;

//对于搜索二叉树来说，这种方式更加高效
class Solution {
public:
	int count = 0;
	int maxNum = 0;
	vector<int> res;
	TreeNode* pre = NULL;
	void travelsor(TreeNode* root) {
		if (root == NULL) return;
		travelsor(root->left);
		if (pre == NULL) {
			count = 1;
		}
		else if (root->val == pre->val) {
			count += 1;
		}
		else count = 1;
		if (count >= maxNum) {
			if (count > maxNum) res.clear();  //不要忘记了清理原来里面的数字
			res.push_back(root->val);
			maxNum = count; //写着写着忘记最后要更新最大数目
		}
		pre = root;
		travelsor(root->right);
	}

	vector<int> findMode(TreeNode* root) {
		travelsor(root);
		return res;
	}
}solution;

int main() {
	BuildTree buildtree;
	TreeNode* root = buildtree.build();
	vector<int> res;
	res = solution.findMode(root);
	for (int n : res) cout << n << endl;
	return 0;
}


