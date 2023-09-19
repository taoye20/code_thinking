#include<iostream>
using namespace std;

/*
�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��

ʾ�� 1��
����: s = "abcdefg", k = 2
���: "cdefgab"

ʾ�� 2��
����: s = "lrloseumgh", k = 6
���: "umghlrlose"

���ƣ�
1 <= k < s.length <= 10000
*/

class Solution {
public:
	string reverseLeftWords(string s, int n) {
		reverse(s.begin(), s.begin() + n);
		reverse(s.begin() + n, s.end());
		reverse(s.begin(), s.end());
		return s;
	}
}solution;

int main() {
	string s = "abcdefg";
	string res = solution.reverseLeftWords(s, 2);
	cout << res << endl;
	return 0;
}