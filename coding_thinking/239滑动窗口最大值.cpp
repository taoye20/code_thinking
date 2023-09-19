#include<iostream>
#include<vector>
#include<deque>
using namespace std;

/*
����һ���ǿյ��������飬�������г���Ƶ��ǰ k �ߵ�Ԫ�ء�

ʾ�� 1:

����: nums = [1,1,1,2,2,3], k = 2
���: [1,2]
ʾ�� 2:

����: nums = [1], k = 1
���: [1]
*/

class Solution {
public:
	//�ȴ���һ����������
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