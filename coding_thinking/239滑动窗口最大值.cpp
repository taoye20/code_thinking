#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
*/

class Solution {
public:
	//先创造一个单调队列
	class Myque {
	public:
		deque<int> que;
		void pop(int value) {
			if (!que.empty() && value == que.front()) {
				que.pop_front();
			}
		}

		void push(int value) {
			while (!que.empty() && value > que.back()) {
				que.pop_back();
			}
			que.push_back(value);
		}

		int front() {
			return que.front();
		}
	};


	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		Myque que;
		vector<int> res;
		for (int i = 0; i < k; i++) {
			que.push(nums[i]);
		}
		res.push_back(que.front());
		for (int i = k; i < nums.size(); i++) {
			que.pop(nums[i - k]);
			que.push(nums[i]);
			res.push_back(que.front());
		}
		return res;
	}
}solution;

int main() {
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> res;
	res = solution.maxSlidingWindow(nums, 3);
	for (int r : res) {
		cout << r << endl;
	}
	return 0;
}