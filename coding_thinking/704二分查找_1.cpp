#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int middle = left + (right - left)/2;
			if (nums[middle] == target) return middle;
			else if (nums[middle] < target) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		return -1;
	}
}solution;

int main() {
	vector<int> nums = { -1, 0, 3, 5, 9, 12 };
	cout << solution.search(nums, 9) << endl;
	return 0;
}