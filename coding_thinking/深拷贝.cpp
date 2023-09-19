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
		//high = p.high;  //会导致拷贝的对象该指针元素指向同一个堆区地址，在析构时会重复释放同一个地址导致错误，虽然编译器帮我体面了
		high = new int(*p.high);  //深拷贝，即使拷贝的对象的堆区指针元素开辟一个新的存储空间
	}

	~Person() {
		cout << "调用析构函数" << endl;
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