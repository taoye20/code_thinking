#include<iostream>
#include<stack>
using namespace std;


//ѹ��st�����Ļ���
template<class T>
class BaseType {
public:
	virtual void pushStack(stack<T>& st) = 0;
	virtual ~BaseType() {}
};


//ѹ��st�ľ������
class Type1 : public BaseType<char> {
public:
	void pushStack(stack<char>& st) {
		st.push(')');
	}
};

class Type2 : public BaseType<char> {
public:
	void pushStack(stack<char>& st) {
		st.push(']');
	}
};

class Type3 : public BaseType<char> {
public:
	void pushStack(stack<char>& st) {
		st.push('}');
	}
};


//ѡ�񴴽�����ѹ�����ѡ����Ӧ��ʱ���䶯�����������ö�̬
class Selector_char {
private:
	char type;

public:
	Selector_char() {}
	Selector_char(const char& type) {
		this->type = type;
	}

	bool isKnownType() {
		return (type == '(' || type == '[' || type == '{');
	}

	BaseType<char>* selec() {
		if (type == '(') return new Type1();
		if (type == '[') return new Type2();
		if (type == '{') return new Type3();
	}
};


//����Ƿ�Ϸ����ܵ���
template<class T>
class Solution {
private:
	BaseType<T>* pushOperator;
	stack<T> st;

public:
	//Solution() {}
	//Solution(BaseType<T>* push) : pushOperator(push) {}

	//~Solution() {}

	bool chackIsOK_char(string s) {

		for (char c : s) {
			//����ѡ����ѡ����ص�push���ܵĶ�������Ҳ����ʹ�ö�̬����Ϊ���㲻д��
			Selector_char selector(c);
			//����ǶԳ�ǰ������st
			if (selector.isKnownType()) {
				pushOperator = selector.selec();
				pushOperator->pushStack(st);
				delete pushOperator;
			}
			else if (st.empty() || c != st.top()) {
				return false;
			}
			else {
				st.pop();
			}
		}
		return st.empty();
	}
};


//test
int main() {
	string s = "{{[]}}";
	Solution<char> solution;
	bool res = solution.chackIsOK_char(s);
	cout << res << endl;
	return 0;
}



//class Solution {
//public:
//	bool isValid(string s) {
//		if (s.length() % 2 != 0) return false;
//		stack<char> st;
//		for (int i = 0; i < s.length(); i++) {
//			if (s[i] == '[') st.push(']');
//			else if (s[i] == '{') st.push('}');
//			else if (s[i] == '(') st.push(')');
//			//else if (s[i] == st.top()) st.pop();  //�������st�Ѿ��ǿյ��ˣ���ôtop���ܳ������⣬Ҫ����ǿ�����
//			//else return false;
//			else if (s.empty() || s[i] != st.top()) return false;
//			else st.pop();
//		}
//		return st.empty();
//	}
//}solution;

//int main() {
//	string s = "{{[]}}";
//	cout << solution.isValid(s) << endl;
//	return 0;
//}