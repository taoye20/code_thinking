#include<iostream>
using namespace std;

class Person {
public:
	Person(int a, int b) {
		age = a;
		high = new int(b);
	}

	Person(const Person& p) {
		age = p.age;
		//high = p.high;  //�ᵼ�¿����Ķ����ָ��Ԫ��ָ��ͬһ��������ַ��������ʱ���ظ��ͷ�ͬһ����ַ���´�����Ȼ����������������
		high = new int(*p.high);  //�������ʹ�����Ķ���Ķ���ָ��Ԫ�ؿ���һ���µĴ洢�ռ�
	}

	~Person() {
		cout << "������������" << endl;
	}

public:
	int age;
	int* high;
};

void test01() {
	Person p(10, 180);
	Person p1(p);
}

int main() {
	test01();

	system("pause");

	return 0;
}