#include<iostream>
using namespace std;

int main() {
	//定义数组的方式
	int a[][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	
	//数组大小判断
	int n = sizeof(a) / sizeof(a[0]);  //输出行数
	int k = sizeof(a[0]) / sizeof(a[0][0]);  //输出列数
	cout << n << endl;
	cout << k << endl;

	//数组地址，可以看到为顺序排列，且间隔为4字节
	cout << "地址（0，0）：" << (int)&a[0][0] << "/t" << "地址（0，1）：" << (int)&a[0][1] << "/t" << "地址（0，2）：" << (int)&a[0][2] << endl;
	cout << "地址（1，0）：" << (int)&a[1][0] << "/t" << "地址（1，1）：" << (int)&a[1][1] << "/t" << "地址（1，2）：" << (int)&a[1][2] << endl;
	return 0;
}