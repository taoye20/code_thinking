#include<iostream>
using namespace std;

//求x的n次方的递归方法,该时间复杂度为O(n)，表示递归n次
int back(int x, int n) {
	if (n == 0) {
		return 1;
	}
	return back(x, n - 1) * x;  //递归返回调用上一轮的结果
}

//求斐波那契数列
int fibonacci(int i) {
	if (i == 0) return 0;
	if (i == 1) return 1;
	return fibonacci(i - 1) + fibonacci(i - 2);
}

//斐波那契数列优化，优化了时间复杂度
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
		return fibonacci_3(second, first + second, n - 1);  //输入参数是变动的，由上一次
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