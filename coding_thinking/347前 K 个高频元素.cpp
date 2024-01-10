#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue>
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
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		for (int n : nums) {
			map[n]++;
		}
		vector<pair<int, int>> vec(map.begin(), map.end());
		sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {a.second < b.second; });
		vector<int> res;
		for (int i = 0; i < k; i++) {
			res.push_back(vec[i].first);
		}
		return res;
	}
}solution;

//class Solution {
//public:
//	class mycomparison {
//	public:
//		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
//			return lhs.second > rhs.second;
//		}
//	};
//
//	vector<int> topKFrequent(vector<int>& nums, int k) {
//		//map�洢���ִ���
//		unordered_map<int, int> map;
//		for (int n : nums) {
//			map[n]++;
//		}
//
//		////��vector�н��бȽϲ����
//		//vector<pair<int, int>> s(map.begin(), map.end());
//		//sort(s.begin(), s.end(), [](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second; });
//		vector<pair<int, int>> vec(map.begin(), map.end());
//		sort(vec.begin(), vec.end(), [](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second; });
//		//vector<int> res;
//		//for (int i = 0; i < k; i++) {
//		//	res.push_back(s[i].first);
//		//}
//		//return res;
//
//		//ʹ��С�Ѷ��ķ�ʽ�����ȶ���
//		//priority_queue < pair<int, int>, vector<pair<int, int>>, [](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second; } > pri_que;
//		priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
//		for (pair<int, int> m : map) {
//			pri_que.push(m);
//			if (pri_que.size() > k) {
//				pri_que.pop();
//			}
//		}
//		vector<int> res(k);
//		for (int i = k-1; i >= 0; i--) {
//			res[i] = pri_que.top().first;
//			//res.push_back(pri_que.top().first);
//			pri_que.pop();
//		}
//		return res;
//	}
//}solution;

int main() {
	vector<int> nums = { 1,1,1,2,2,3 };
	vector<int> res = solution.topKFrequent(nums, 2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}