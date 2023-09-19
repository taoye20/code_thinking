#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
*/

//哈希表的关键就在于，无需自己解决重复项的问题，而且find比较方便
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {  //注意是引用
		unordered_set<int> res_set;
		unordered_set<int> nums_set(nums1.begin(), nums1.end());  //学习这里的初始化方法初始化可以赋值，也可以从vector引入数据
		//for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++) {
		//}
		//for (int num = 0; num < nums2.size(); num++)
		for (int num : nums2) {  //注意这里的循环方式
			if (nums_set.find(num) != nums_set.end()) {
				res_set.insert(num);
			}
		}
		return vector<int>(res_set.begin(), res_set.end());  //注意返回的时候也要转化类型
	}
}solution;

int main() {
	vector<int> v1 = { 1, 2, 2, 3, 4, 5 };
	vector<int> v2 = { 2, 3 };
	vector<int> v = solution.intersection(v1, v2);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}