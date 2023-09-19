#include<iostream>
#include<vector>
using namespace std;

/*
��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��

ʾ�� 1�� ���룺s = "We are happy."
�����"We%20are%20happy."
*/

//˼�룺����ԭ�ַ����Ϻ��ʵ����ӳ��ȣ�����Ӻ���ǰ��˫ָ�븳ֵ
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