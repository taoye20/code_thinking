#include<iostream>
using namespace std;

void main() {
	int n = 100;
	int* a = new int[n];  //注意new是传递的地址
	int* b = new int(10);
	for (int i = 0; i < n; i++) {
		a[i] = i;
		cout << a[i] << "\t";
		cout << (*b)++ << endl;
	}
	delete[] a;
	delete b;
}
