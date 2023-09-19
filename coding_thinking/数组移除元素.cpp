#include<iostream>
#include<vector>
using namespace std;

//����ɾ���м�ָ����Ԫ��
class Solution {
public:
	//��ͳ������ɾ��һ��������ȫ����ǰ�ƶ�һλ��ʱ�临�Ӷ�ΪO(n*n)
	int rm1(vector<int>& nums, int val) {
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			if (nums[i] == val) {
				for (int j = i + 1; j < size; j++) {
					nums[j - 1] = nums[j];  
				}
				i--;
				size--;
			}
		}
		return size;
	}

	//˫ָ�뷨���Լ�д���߼���������
	int rm2(vector<int>& nums, int val) {
		int size = nums.size();
		int slow = 0;
		for (int fast = 0; fast < size; fast++) {
			nums[slow] = nums[fast];
			if (nums[slow] != val) slow++;  //�����ָ�뷢����ͬ�ľ�ԭ�صȴ���ֵ
		}
		return slow;
	}

	//˫ָ�뷨�����˵�д����slow���Կ�����ԭ����������дһ���µ����飬fast����������val��ͬ�������ݸ�slow
	int rm3(vector<int>& nums, int val) {
		int slow = 0;
		for (int fast = 0; fast < nums.size(); fast++) {
			if (nums[fast] != val) {
				nums[slow++] = nums[fast];  //�ȴ�ֵ���ָ��
			}
		}
		return slow;
	}

	//26˫ָ�뷨ɾ�������е��ظ���
	int removeDuplicates(vector<int>& nums) {
		int j = 1; 
		if (nums.size() == 1) return 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i-1] != nums[i]) {  //ע�������-1��ǰ������j��ʼΪ1����Ϊ�˲��ᳬ�����鷶Χ
				nums[j++] = nums[i];
			}
		}
		return j;
	}
}solution;

//���ò���ӡ
int main() {
	vector<int> nums = { 1, 6, 3, 2, 2, 9, 5 };
	int size = solution.rm3(nums, 2);
	for (int i = 0; i < size; i++) {
		cout << nums[i] << endl;
	}
	return 0;
}