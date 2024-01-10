#include<iostream>
#include<stack>
using namespace std;


//压入st操作的基类
template<class T>
class BaseType {
public:
	virtual void pushStack(stack<T>& st) = 0;
	virtual ~BaseType() {}
};


//压入st的具体对象
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


//选择创建哪种压入对象，选择器应当时常变动，因此最好设置多态
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


//检查是否合法功能的类
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
			//创建选择器选择加载的push功能的对象，这里也可以使用多态但是为方便不写了
			Selector_char selector(c);
			//如果是对称前项，则加入st
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
//			//else if (s[i] == st.top()) st.pop();  //这里如果st已经是空的了，那么top可能出现问题，要加入非空条件
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