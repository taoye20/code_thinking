#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 �������ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺ ���в����԰����ظ�����Ԫ�顣

ʾ����

�������� nums = [-1, 0, 1, 2, -1, -4]��

����Ҫ�����Ԫ�鼯��Ϊ�� [ [-1, 0, 1], [-1, -1, 2] ]
*/


//˼·��ԭ����ʹ�ù�ϣ����֮ͬǰ��������ӣ�����ȥ��̫�ѣ�����˫ָ��
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int i = 0; //��ʼλ��ָ�룬����a
		int left = 1;  //����b
		int right = nums.size() - 1;  //����c
		vector<vector<int>> res;

		//�ؼ���1��������
		sort(nums.begin(), nums.end());
		for (; i < nums.size() - 2; i++) {
			//�ؼ���2��ȥ��
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			left = i + 1;
			right = nums.size() - 1;
			while (left < right) {
				if (nums[i] + nums[left] + nums[right] == 0) {
					res.push_back({ nums[i], nums[left], nums[right] });
					//ȥ��
					while (right > left && nums[right] == nums[right - 1]) right--;
					while (right > left && nums[left] == nums[left + 1]) left++;
					//�ҵ���ͬʱ������Χ
					right--;
					left++;
				}
				else if (nums[i] + nums[left] + nums[right] > 0) {
					right--;
				}
				else {
					left++;
				}
			}
		}
		return res;
	}
}solution;

int main() {
	vector<int> nums = { 0, 0, 0, 0 };
	vector<vector<int>> res = solution.threeSum(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}