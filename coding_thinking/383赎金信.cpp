#include<iostream>
using namespace std;


/*
����һ������� (ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ��� ransom �ܲ����ɵڶ����ַ��� magazines ������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��

(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼����־�ַ����е�ÿ���ַ�ֻ����������ַ�����ʹ��һ�Ρ�)

ע�⣺

����Լ��������ַ�����ֻ����Сд��ĸ��

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int count[26] = { 0 };
		if (ransomNote.length() > magazine.length()) return false;
		for (int i = 0; i < magazine.length(); i++) {
			count[magazine[i] - 'a']++;
		}
		for (int i = 0; i < ransomNote.length(); i++) {
			count[ransomNote[i] - 'a']--;
			if (count[ransomNote[i] - 'a'] < 0) return false;
		}
		return true;
	}
}solution;

int main() {
	bool res = solution.canConstruct("aa", "aab");
	cout << res << endl;
	return 0;
}