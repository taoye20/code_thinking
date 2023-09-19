#include<iostream>
#include<vector>
using namespace std;

/*
����һ�������� n������һ������ 1 �� n^2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���

ʾ��:

����: 3 ���: [ [ 1, 2, 3 ], 
			   [ 8, 9, 4 ], 
			   [ 7, 6, 5 ] ]
*/

//����˼·Ӧ����ѭѭ������ԭ��ÿ��ѭ��ʹ����ͬ���жϻ��㷨Ϊ�ѣ�������һ���ж�
//�ó���ȫ�������ṩ˼·
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));  //ע�����и�ֵ
		int startx = 0, starty = 0;  //ÿ�ο�ʼ��ֵ��
		int loop = n / 2; //ѭ����ֵ��Ȧ��������n=3���渳ֵ1Ȧ�������ĵ�����ֵ�м�
		int mid = n / 2;  //רΪnΪ����ʱ׼����
		int count = 1;  //��ֵ��
		int offset = 1;  //���ڿ���ÿȦ�к����ȵȵĳ��ȣ�Ҳ�������Ϊ���е���β֮��ľ���
		int i, j;
		while (loop--) {
			i = startx;
			j = starty;

			for (; j < n - offset; j++) {
				result[i][j] = count++;
			}
			for (; i < n - offset; i++) {
				result[i][j] = count++;
			}
			for (; j > starty; j--) {
				result[i][j] = count++;
			}
			for (; i > startx; i--) {
				result[i][j] = count++;
			}

			startx++;
			starty++;
			offset += 1;
		}

		if (n % 2 == 1) result[mid][mid] = count;
		return result;
	}
}solution;

int main() {
	int n = 3;
	vector<vector<int>> result = solution.generateMatrix(n);
	cout << "�����" << result[1][1] << endl;
	return 0;
}