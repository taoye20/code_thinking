#include<iostream>
using namespace std;

void main() {
	int n = 100;
	int* a = new int[n];  //ע��new�Ǵ��ݵĵ�ַ
	int* b = new int(10);
	for (int i = 0; i < n; i++) {
		a[i] = i;
		cout << a[i] << "\t";
		cout << (*b)++ << endl;
	}
	delete[] a;
	delete b;
}
