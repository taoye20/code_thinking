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
			//else if (s[i] == st.top()) st.pop();  //这里如果st已经是空的了，那么top可能出现问题，要加入非空条件
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