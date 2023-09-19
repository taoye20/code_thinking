#include<iostream>
using namespace std;

/*
给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"

示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/

class Solution {
public:
	//反转函数
	void reverse(string& s,int begin,int end) {
		while (begin < end) {
			swap(s[begin], s[end]);
			begin++;
			end--;
		}
	}

	//去除多余空格的函数
	void removeSpace(string& s) {
		int slow = 0, fast = 0;
		for (; fast < s.size(); fast++) {
			if (s[fast] != ' ') {
				if (slow != 0) s[slow++] = ' ';
				while (s[fast] != ' ' && fast < s.size()) {  //注意每次while时要多个心眼
					s[slow++] = s[fast++];
				}
			}
		}
		s.resize(slow);  //记得裁剪大小，否则调用时会出现问题
	}

	//功能的函数
	string reverseWords(string s) {
		//先去除多余空格
		removeSpace(s);
		//再整体反转
		reverse(s, 0, s.size() - 1);
		//最后逐词反转
		for (int i = 0; i < s.size(); i++) {
			int j = i;
			while (s[j] != ' ' && j < s.size()) {
				j++;
			}
			reverse(s, i, j - 1);
			i = j;
		}
		return s;
	}
}solution;

int main() {
	string s = "a good   example";
	string res = solution.reverseWords(s);
	cout << res << endl;
	return 0;
}