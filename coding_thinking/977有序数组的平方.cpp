#include<iostream>
#include<vector>
using namespace std;

/*����һ���� �ǵݼ�˳�� ������������� nums������ ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ�� �ǵݼ�˳�� ����

ʾ�� 1��

���룺nums = [-4,-1,0,3,10]
�����[0,1,9,16,100]
���ͣ�ƽ���������Ϊ [16,1,0,9,100]������������Ϊ [0,1,9,16,100]
ʾ�� 2��

���룺nums = [-7,-3,2,3,11]
�����[4,9,9,49,121]*/

class Solution {
public:
	vector<int> squ(vector<int>& a) {
		vector<int> result(a.size(), 0);  //ע��˴�vector�ĸ�ֵ��ʽ
		int right = a.size() - 1;
		int left = 0;
		int k = a.size() - 1;  //����������һ������ֵ�Ĺ���
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
	cout << "�ҵ���" << result[2] << endl;
	return 0;
}