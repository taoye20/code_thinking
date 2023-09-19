#include<iostream>
#include<vector>
using namespace std;

/*给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]
示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]*/

class Solution {
public:
	vector<int> squ(vector<int>& a) {
		vector<int> result(a.size(), 0);  //注意此处vector的赋值方式
		int right = a.size() - 1;
		int left = 0;
		int k = a.size() - 1;  //对新数组是一个反向赋值的过程
		while (left <= right) {
			if (a[left] * a[left] > a[right] * a[right]) {
				result[k--] = a[left] * a[left];
				left++;
			}
			else {
				result[k--] = a[right] * a[right];
				right--;
			}
		}
		return result;
	}
}solution;

int main() {
	vector<int> a = { -4,-1,0,3,10 };
	vector<int> result = solution.squ(a);
	cout << "找到：" << result[2] << endl;
	return 0;
}