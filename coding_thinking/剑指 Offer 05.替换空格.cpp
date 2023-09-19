#include<iostream>
#include<vector>
using namespace std;

/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1： 输入：s = "We are happy."
输出："We%20are%20happy."
*/

//思想：先在原字符串上合适的增加长度，而后从后往前的双指针赋值
class Solution {
public:
	string replaceSpace(string s) {
		int count = 0;
		int oldSize = s.size() - 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') count++;
		}

		s.resize(s.size() + count * 2);
		int newSize = s.size() - 1;
		for (int i = oldSize, j = newSize; i < j; i--, j--) {
			if (s[i] == ' ') {
				s[j--] = '0';
				s[j--] = '2';
				s[j] = '%';
			}
			else {
				s[j] = s[i];
			}
		}
		return s;
	}
}solution;

int main() {
	string a = "hello world";
	string res = solution.replaceSpace(a);
	cout << res << endl;
}