#include<iostream>
using namespace std;

//��x��n�η��ĵݹ鷽��,��ʱ�临�Ӷ�ΪO(n)����ʾ�ݹ�n��
int back(int x, int n) {
	if (n == 0) {
		return 1;
	}
	return back(x, n - 1) * x;  //�ݹ鷵�ص�����һ�ֵĽ��
}

//��쳲���������
int fibonacci(int i) {
	if (i == 0) return 0;
	if (i == 1) return 1;
	return fibonacci(i - 1) + fibonacci(i - 2);
}

//쳲����������Ż����Ż���ʱ�临�Ӷ�
int fibonacci_3(int first, int second, int n) {
	if (n <= 0) {
		return 0;
	}
	if (n < 3) {
		return 1;
	}
	else if (n == 3) {
		return first + second;
	}
	else {
		return fibonacci_3(second, first + second, n - 1);  //��������Ǳ䶯�ģ�����һ��
	}
}

int main() {
	int x = 2, n = 10;
	int result = 0;
	//result = back(x, n);
	result = fibonacci_3(1, 1, 15);
	cout << result << endl;
	return 0;
}