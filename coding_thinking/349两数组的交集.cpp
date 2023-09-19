#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

/*
������������ nums1 �� nums2 ������ ���ǵĽ��� ���������е�ÿ��Ԫ��һ���� Ψһ �ġ����ǿ��� ��������������˳�� ��
ʾ�� 1��

���룺nums1 = [1,2,2,1], nums2 = [2,2]
�����[2]
ʾ�� 2��

���룺nums1 = [4,9,5], nums2 = [9,4,9,8,4]
�����[9,4]
���ͣ�[4,9] Ҳ�ǿ�ͨ����
*/

//��ϣ��Ĺؼ������ڣ������Լ�����ظ�������⣬����find�ȽϷ���
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {  //ע��������
		unordered_set<int> res_set;
		unordered_set<int> nums_set(nums1.begin(), nums1.end());  //ѧϰ����ĳ�ʼ��������ʼ�����Ը�ֵ��Ҳ���Դ�vector��������
		//for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++) {
		//}
		//for (int num = 0; num < nums2.size(); num++)
		for (int num : nums2) {  //ע�������ѭ����ʽ
			if (nums_set.find(num) != nums_set.end()) {
				res_set.insert(num);
			}
		}
		return vector<int>(res_set.begin(), res_set.end());  //ע�ⷵ�ص�ʱ��ҲҪת������
	}
}solution;

int main() {
	vector<int> v1 = { 1, 2, 2, 3, 4, 5 };
	vector<int> v2 = { 2, 3 };
	vector<int> v = solution.intersection(v1, v2);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}