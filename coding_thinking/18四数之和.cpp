#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
���⣺����һ������ n ������������ nums ��һ��Ŀ��ֵ target���ж� nums ���Ƿ�����ĸ�Ԫ�� a��b��c �� d ��ʹ�� a + b + c + d ��ֵ�� target ��ȣ��ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺

���в����԰����ظ�����Ԫ�顣

ʾ���� �������� nums = [1, 0, -1, 0, -2, 2]���� target = 0�� ����Ҫ�����Ԫ�鼯��Ϊ�� [ [-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2] ]

#�㷨������
*/

//����������У�whileҪ�ر�ע���ж����������������ѭ�����ͱ������while(nums[c] == nums[c+1] && c<d)����c<d����������ͻ�����ܳ����������
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int a = 0; a < nums.size(); a++) {
			//��֦
			if (nums[a] > target && nums[a] >= 0) break;

			//ȥ��
			if (a > 0 && nums[a] == nums[a - 1]) continue;  //ע��ȥ���е�continue��while

			for (int b = a + 1; b < nums.size(); b++) {
				if (nums[a] + nums[b] > target && nums[a] + nums[b] >= 0) break;
				if (b > a + 1 && nums[b] == nums[b - 1]) continue;

				int c = b + 1;
				int d = nums.size() - 1;

				while (c < d) {
					if (nums[a] + nums[b] + nums[c] + nums[d] > target) {
						d--;
					}
					else if (nums[a] + nums[b] + nums[c] + nums[d] < target) {
						c++;
					}
					else {
						res.push_back({ nums[a] , nums[b] , nums[c] , nums[d] });

						//ȥ��
						while (nums[c] == nums[c + 1] && c < d) c++;
						while (nums[d] == nums[d - 1] && c < d) d--;

						c++;
						d--;
					}
				}
			}
		}
		return res;
	}
}solution;

int main() {
	vector<int> nums = { 1, 0, -1, 0, -2, 2 };
	int target = 0;
	vector<vector<int>> res = solution.fourSum(nums, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}