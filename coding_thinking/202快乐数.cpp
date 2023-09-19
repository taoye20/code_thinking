#include<iostream>
#include<unordered_set>
using namespace std;

/*
��дһ���㷨���ж�һ���� n �ǲ��ǿ�������

��������������Ϊ������һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���ͣ�Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1����� ���Ա�Ϊ  1����ô��������ǿ�������

��� n �ǿ������ͷ��� True �����ǣ��򷵻� False ��

ʾ����

���룺19
�����true
���ͣ�
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

class Solution {
public:
	//ע��ֿ�����λ�����в����ķ���
	int getSum(int num) {
		int sum = 0;
		while (num) {
			sum += (num % 10) * (num % 10);
			num = num / 10;
		}
		return sum;
	}
	
	//����ʹ��set����Ϊ���������ѭ������ô�ͻ����ͬ������ֵ����set�з����ظ���ֵ���������Ѿ�������ѭ��
	//ʹ��unordered_set�Ĳ�ѯЧ����O(1)��ֻ�������˿ռ���ѣ����ʹ��vector��Ѱ�Ҵ洢ֵ����ΪO(N)
	//ʼ�ռǵ�һ���ϣ������ԣ����Ǳ�ǩ��ֵ�������ѯ������Ҫ�����Ƿ���ֹ���������һ����Ҫ�����ϣ��
	bool happyNum(int n) {
		unordered_set<int> num_set(n);
		while (1) {
			int sum = getSum(n);
			if (sum == 1) return true;
			if (num_set.find(sum) != num_set.end()) {
				return false;
			}
			else {
				num_set.insert(sum);
			}
			n = sum;
		}
	}
}solution;

int main() {
	int n = 20;
	bool res= solution.happyNum(n);
	cout << res << endl;
	return 0;
}