#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int findMinSum(vector<int> n) {
		int res = INT16_MAX;
		int sum = 0;
		for(int right = 0; right < n.size(); right++){
			sum = 0;
			sum += n[right];
			res = min(res, sum);
			for (int left = 0; left < right; left++) {
				sum -= n[left];
				res = min(res, sum);
			}
		}
	}
}solution;

int main() {
	vector<int> n = { 7, -6, 5, -9, 4 };
	int res = solution.findMinSum(n);
	cout << res << endl;
	return 0;
}