#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.length() % 2 != 0) return false;
		stack<char> st;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '[') st.push(']');
			else if (s[i] == '{') st.push('}');
			else if (s[i] == '(') st.push(')');
			//else if (s[i] == st.top()) st.pop();  //�������st�Ѿ��ǿյ��ˣ���ôtop���ܳ������⣬Ҫ����ǿ�����
			//else return false;
			else if (s.empty() || s[i] != st.top()) return false;
			else st.pop();
		}
		return st.empty();
	}
}solution;

int main() {
	string s = "{{[]}}";
	cout << solution.isValid(s) << endl;
	return 0;
}