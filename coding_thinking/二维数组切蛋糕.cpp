#include<iostream>
#include <algorithm>
using namespace std;
/*
	��ά����Ҫ���зֵ��⣬����Ԫ�ر�ʾ�������ζ�ȣ�Ҫ��һ���з�
*/

int main() {
	int a[][3] = { {1, 1, 4}, 
				{5, 1, 4}};   
	int sum = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			sum += a[i][j];
		}
	}
	int sum1 = 0;
	int sum2 = 0;
	int dfs = INT_MAX;
	//����
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			sum1 += a[i][j];
		}
		sum2 = sum - sum1;
		dfs = min(dfs, abs(sum1 - sum2));
	}

	sum1 = 0;
	sum2 = 0;

	//����
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 2; i++) {
			sum1 += a[i][j];
		}
		sum2 = sum - sum1;
		dfs = min(dfs, abs(sum1 - sum2));
	}
	cout << dfs << endl;
	return 0;  
}
