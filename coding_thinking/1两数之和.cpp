#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*
����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9

���Է��� [0, 1]
*/

class Solution {
public:
	//ʹ������ķ���ʵ�֣�ʱ�临�Ӷ�ΪO(nlog(n))
	vector<int> twoSum01(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size() - 1; i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) return vector<int>{i, j};
			}
		}
		return {};
	}

	//ʹ�ù�ϣ��ķ�������Ϊ��ϣ���find���Ӷ�ΪO(1),����ܸ��Ӷ�ΪO(n)��
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			unordered_map<int, int>::iterator iter = map.find(target - nums[i]);  //��������Ѿ������key����û�к��ʵ�ֵ
			if (iter != map.end()) {
				return vector<int>{iter->second, i};  //return vector<int>{map[target - nums[i]]}
			}
			else {
				map.insert(pair<int, int>(nums[i], i));  //map�е�keyΪҪ���ҵ�ֵ��map�е�valueΪ����λ�õı��
			}
		}
		return {};  //�����û��
	}
}solution;

int main() {
	vector<int> nums = { 2, 7, 11, 16 };
	int target = 9;
	vector<int> tar = solution.twoSum(nums, target);
	for (vector<int>::iterator it = tar.begin(); it != tar.end(); it++) {
		cout << *it << "";
	}
	cout << endl;
}