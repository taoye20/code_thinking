#include<iostream>
#include<vector>
using namespace std;

//class Calculator {
//public:
//	int m_num1;
//	int m_num2;
//	int getResult(string oper) {
//		if (oper == "+") return m_num1 + m_num2;
//		if (oper == "-") return m_num1 - m_num2;
//		if (oper == "*") return m_num1 * m_num2;
//		
//		//可此时想要扩展程序...
//};
//
//void test01() {
//	Calculator c;
//	c.m_num1 = 10;
//	c.m_num2 = 20;
//	string oper = "+";
//	cout << c.m_num1 << oper << c.m_num2 << "=" << c.getResult(oper) << endl;
//}

class AbstractCalculator {
public:
	//AbstractCalculator(int a, int b) : m_Num1(a), m_Num2(b) {};
	virtual int getResult() {
		return 0;
	}
	int m_Num1;
	int m_Num2;
};

class AddCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 + m_Num2;
	}
};

class SubCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 - m_Num2;
	}
};

class MutiCalculator : public AbstractCalculator {
public:
	int getResult() {
		return m_Num1 * m_Num2;
	}
};


void test01() {
	AbstractCalculator* val = new AddCalculator; //一定记得创建一个父类的指针，指向子类对象
	val->m_Num1 = 10;
	val->m_Num2 = 20;
	cout << val->m_Num1 << "+" << val->m_Num2 << "=" << val->getResult() << endl;
	delete val;   //记得移除堆区

	val = new SubCalculator; //一定记得创建一个父类的指针，指向子类对象，定义一次后不用再定义一次类型，即使delete了也只是移除了堆区没有修改栈区
	val->m_Num1 = 10;
	val->m_Num2 = 20;
	cout << val->m_Num1 << "-" << val->m_Num2 << "=" << val->getResult() << endl;
	delete val;
}

int main() {
	test01();
	return 0;
}