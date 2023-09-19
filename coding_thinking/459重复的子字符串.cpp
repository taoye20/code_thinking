#include<iostream>
using namespace std;

/*
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:

输入: "abab"
输出: True
解释: 可由子字符串 "ab" 重复两次构成。
示例 2:

输入: "aba"
输出: False
示例 3:

输入: "abcabcabcabc"
输出: True
解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。
*/



class Solution {
public:
	//思路1,暴力法
	bool repeatedSubstringPattern1(string s) {
		int n = s.length();
		for (int i = 0; i < n / 2; i++) {    //循环超过一半没找到就是没有
			int flag = 0;
			int compare_tail = i * 2 + 1;
			while (compare_tail < n) {
				for (int j = 0; j <= i; j++) {
					if (s[j] != s[compare_tail - i + j]) {
						flag = 1;
						break;
					}
				}
				if (flag == 1) break;
				else {
					compare_tail += i + 1;
				}
			}
			if (compare_tail == n + i) return true;
		}
		return false;
	}

	//思路2，如果一个字符串可以由某个部分重复得到，那么两个字符串拼接起来，掐头去尾，中间也一定会出现原字符串
	bool repeatedSubstringPattern(string s) {
		string t = s + s;
		t.erase(t.begin());
		t.erase(t.end() - 1);
		if (t.find(s) != string::npos) return true;
		else return false;
	}
}solution;

int main() {
	string s = "ababba";
	bool res = solution.repeatedSubstringPattern(s);
	cout << res << endl;
	return 0;
}