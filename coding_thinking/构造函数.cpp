#include<iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "调用无参构造函数" << endl;
	}

	//Person(int a) {
	//	age = a;
	//	cout << "调用有参构造函数，参数为" << age << endl;
	//}

	//列表赋值法
	Person(int a) : age(a) { 
		cout << "调用有参构造函数，参数为" << age << endl; 
	}  

	Person(const Person& p) {   //通常构造函数是可以不写的，那么默认所有参数为浅拷贝。但是需要复制堆区指针时，析构函数就会出现问题
		age = p.age;
		cout << "调用拷贝构造函数" << endl;  //拷贝构造函数即构造函数输入为一个该对象
	}

	//析构函数
	~Person() {
		cout << "析构函数" << endl;
	}

public:
	int age;
};

void test01() {
	Person person;
	Person p1(20);
	Person p2(p1);  //格式：类名 对象名（参数）

	//隐式传递法
	//Person p1 = 20;
	//Person p2 = p1;  //与上两行含义一致
}



void doWork(Person p) {}

Person doWork01() {
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}

//拷贝构造函数的调用时机：
void test02() {
	Person p;
	doWork(p);  //运行发现除了创建了无参构造函数以外，还有一个拷贝构造函数，说明传递对象给函数时会多拷贝一个对象出来
}

void test03() {
	Person p = doWork01();
	cout << (int*)&p << endl;  //奇怪了，按道理这里会调用拷贝构造函数的，地址应该不同才对
}



int main() {
	//test01();
	//test02();
	test03();

	system("pause");

	return 0;
}