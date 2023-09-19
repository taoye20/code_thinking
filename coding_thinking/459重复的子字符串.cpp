#include<iostream>
using namespace std;

/*
����һ���ǿյ��ַ������ж����Ƿ����������һ���Ӵ��ظ���ι��ɡ��������ַ���ֻ����СдӢ����ĸ�����ҳ��Ȳ�����10000��

ʾ�� 1:

����: "abab"
���: True
����: �������ַ��� "ab" �ظ����ι��ɡ�
ʾ�� 2:

����: "aba"
���: False
ʾ�� 3:

����: "abcabcabcabc"
���: True
����: �������ַ��� "abc" �ظ��Ĵι��ɡ� (�������ַ��� "abcabc" �ظ����ι��ɡ�
*/



class Solution {
public:
	//˼·1,������
	bool repeatedSubstringPattern1(string s) {
		int n = s.length();
		for (int i = 0; i < n / 2; i++) {    //ѭ������һ��û�ҵ�����û��
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

	//˼·2�����һ���ַ���������ĳ�������ظ��õ�����ô�����ַ���ƴ����������ͷȥβ���м�Ҳһ�������ԭ�ַ���
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