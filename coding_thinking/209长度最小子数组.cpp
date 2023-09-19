#include<iostream>
#include<vector>
using namespace std;

/*
����һ������ n ���������������һ�������� s ���ҳ���������������� �� s �ĳ�����С�� ���� �����飬�������䳤�ȡ���������ڷ��������������飬���� 0��

ʾ����

���룺s = 7, nums = [2,3,1,2,4,3]
�����2
���ͣ������� [4,3] �Ǹ������µĳ�����С�������顣
��ʾ��

1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/

class Solution {
public:
	int squ(int s,  vector<int>& a) {
		int result = 0, tmp_len = 0, sum = 0;
		int begin = 0, end = 0;
		for (end; end < a.size(); end++) {
			sum += a[end];
				while (sum >= s) {
					tmp_len = end - begin + 1;
				if (result == 0 || result > tmp_len) result = tmp_len;
				sum -= a[begin++];
			}
		}
		return result;
	}
}solution;

int main() {
	vector<int> a = { 2,3,1,2,4,3 };
	int s = 7;
	int result = solution.squ(s, a);
	cout << "�����" << result << endl;
	return 0;
}