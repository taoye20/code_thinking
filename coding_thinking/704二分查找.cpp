#include<iostream>
#include<vector>
using namespace std;

//二分法在数组中寻找target
class Solution {
public:
	//递归的二分法
	int no = -1;
	int* no_num = &no;
	int* search(int* begin, int* end, int target) {  //使用函数重载
		if (begin > end) return no_num;
		int* middle = begin + (end - begin) / 2;
		if (*middle == target) return middle;
		else if (*middle > target) return search(begin, middle - 1, target);
		else return search(middle + 1, end, target);
	}

	//二分法，在数组中间取一个值观测大小，不是左边替换中间就是右边替换中间
	int search(int* a, int target, int n){
		int left = 0;
		int right = n - 1;
		int* result;
		while (left <= right) {  
			int middle = left + (right - left) / 2;
			if (target < a[middle]) {
				right = middle - 1;  //注意这的标签是越过中间的，可以考虑极限最后只剩两个数时，就明白为什么一定是写超过了
			}
			else if (target > a[middle]) {
				left = middle + 1;
			}
			else {
				return middle;
			}
		}
		return -1;
	}
}solution;

int main() {
	int a[] = { -1, 0, 6, 9, 10, 15};
	int target = 2;
	int n = sizeof(a) / sizeof(a[0]);
	//int result = solution.search(a, target, n);
	int* result = solution.search(a, a+sizeof(a)/sizeof(a[0])-1, target);
	cout << "找到：" << * result << endl;
	return 0;
}