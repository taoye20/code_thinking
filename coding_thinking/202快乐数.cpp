#include<iostream>
#include<unordered_set>
using namespace std;

/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

示例：

输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

class Solution {
public:
	//注意分开数字位数进行操作的方法
	int getSum(int num) {
		int sum = 0;
		while (num) {
			sum += (num % 10) * (num % 10);
			num = num / 10;
		}
		return sum;
	}
	
	//考虑使用set是因为，如果进入循环，那么就会出现同样的数值，在set中发现重复数值代表了它已经进入了循环
	//使用unordered_set的查询效率是O(1)，只是牺牲了空间而已，如果使用vector来寻找存储值，则为O(N)
	//始终记得一点哈希表的特性，就是标签对值，方便查询，对需要对照是否出现过这种问题一般需要想起哈希表
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