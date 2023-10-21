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
//		//�ɴ�ʱ��Ҫ��չ����...
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
	AbstractCalculator* val = new AddCalculator; //һ���ǵô���һ�������ָ�룬ָ���������
	val->m_Num1 = 10;
	val->m_Num2 = 20;
	cout << val->m_Num1 << "+" << val->m_Num2 << "=" << val->getResult() << endl;
	delete val;   //�ǵ��Ƴ�����

	val = new SubCalculator; //һ���ǵô���һ�������ָ�룬ָ��������󣬶���һ�κ����ٶ���һ�����ͣ���ʹdelete��Ҳֻ���Ƴ��˶���û���޸�ջ��
	val->m_Num1 = 10;
	val->m_Num2 = 20;
	cout << val->m_Num1 << "-" << val->m_Num2 << "=" << val->getResult() << endl;
	delete val;
}

int main() {
	test01();
	return 0;
}