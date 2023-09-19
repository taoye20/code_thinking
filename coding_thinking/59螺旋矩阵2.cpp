#include<iostream>
#include<vector>
using namespace std;

/*
给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3 输出: [ [ 1, 2, 3 ], 
			   [ 8, 9, 4 ], 
			   [ 7, 6, 5 ] ]
*/

//本题思路应当遵循循环不变原则，每次循环使用相同的判断或算法为佳，而不是一堆判断
//该程序全靠别人提供思路
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n, 0));  //注意这行赋值
		int startx = 0, starty = 0;  //每次开始赋值点
		int loop = n / 2; //循环赋值的圈数，比如n=3外面赋值1圈，奇数的单独赋值中间
		int mid = n / 2;  //专为n为奇数时准备的
		int count = 1;  //赋值用
		int offset = 1;  //用于控制每圈中横竖等等的长度，也可以理解为上行到结尾之间的距离
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
	cout << "结果：" << result[1][1] << endl;
	return 0;
}