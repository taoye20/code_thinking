#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // �����޸��˺�̨�������ݣ���Ҫ��longlong
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            }
            else {
                st.push(stoll(tokens[i]));
            }
        }

        int result = st.top();
        st.pop(); // ��ջ�����һ��Ԫ�ص�������ʵ������Ҳû�£�
        return result;
    }
}solution;

int main() {
    string str[] = { "2", "1", "+", "3", "*" };
	vector<string> tokens(str, str+5);
	int res = solution.evalRPN(tokens);
	cout << res << endl;
	return 0;
}