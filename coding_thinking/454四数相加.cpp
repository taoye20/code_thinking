#include<iostream>
#include<unordered_map>
using namespace std;

/*
�����ĸ����������������б� A , B , C , D ,�����ж��ٸ�Ԫ�� (i, j, k, l) ��ʹ�� A[i] + B[j] + C[k] + D[l] = 0��
Ϊ��ʹ����򵥻������е� A, B, C, D ������ͬ�ĳ��� N���� 0 �� N �� 500 �����������ķ�Χ�� -2^28 �� 2^28 - 1 ֮�䣬���ս�����ᳬ�� 2^31 - 1 ��

����:

����:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
���:
2

����:
����Ԫ������:
(0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
(1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int count = 0;  //���

		//�Ȼ��A,B�͵�ֵ�Ŀ����Լ����ִ���������ʹ�ù�ϣ�������
		unordered_map<int, int> a_and_b;
		for (int a : A) {   //���ֱ��ʽ������д
			for (int b : B) {
				//if (a_and_b.find(a + b) != a_and_b.end()) {
				//	a_and_b[a + b]++;
				//}
				//else {
				//	a_and_b.insert(pair<int, int>(a + b, 1));
				//}
				a_and_b[a + b]++;  //����д���У�a+bΪ��Ҫ���ҵ�ֵ��++��ʾ��ֵ���ֵĴ��������и�ǰ�����һ��ʼvalueΪ0. 
			}
		}

		//ѭ��C,D����ʹ�����������ı�ֵ�����۴���
		for (int c : C) {
			for (int d : D) {
				if (a_and_b.find(0 - c - d) != a_and_b.end()) {
					count += a_and_b[0 - c - d];
				}
			}
		}
		return count;
	}
}solution;

int main() {
	vector<int> A = { 1, 2 };
	vector<int> B = { -1, -2 };
	vector<int> C = { -1, 2 };
	vector<int> D = { 0, 2 };
	int n = solution.fourSumCount(A, B, C, D);
	cout << n << endl;
	return 0;
}