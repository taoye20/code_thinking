#include<iostream>
#include<unordered_map>
using namespace std;

/*
给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。

例如:

输入:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
输出:
2

解释:
两个元组如下:
(0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
(1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int count = 0;  //结果

		//先获得A,B和的值的可能以及出现次数，考虑使用哈希表方便查找
		unordered_map<int, int> a_and_b;
		for (int a : A) {   //这种表达式方便书写
			for (int b : B) {
				//if (a_and_b.find(a + b) != a_and_b.end()) {
				//	a_and_b[a + b]++;
				//}
				//else {
				//	a_and_b.insert(pair<int, int>(a + b, 1));
				//}
				a_and_b[a + b]++;  //这种写法中，a+b为需要查找的值，++表示该值出现的次数，这有个前提就是一开始value为0. 
			}
		}

		//循环C,D查找使得满足条件的表值，积累次数
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