#include<iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "�����޲ι��캯��" << endl;
	}

	//Person(int a) {
	//	age = a;
	//	cout << "�����вι��캯��������Ϊ" << age << endl;
	//}

	//�б�ֵ��
	Person(int a) : age(a) { 
		cout << "�����вι��캯��������Ϊ" << age << endl; 
	}  

	Person(const Person& p) {   //ͨ�����캯���ǿ��Բ�д�ģ���ôĬ�����в���Ϊǳ������������Ҫ���ƶ���ָ��ʱ�����������ͻ��������
		age = p.age;
		cout << "���ÿ������캯��" << endl;  //�������캯�������캯������Ϊһ���ö���
	}

	//��������
	~Person() {
		cout << "��������" << endl;
	}

public:
	int age;
};

void test01() {
	Person person;
	Person p1(20);
	Person p2(p1);  //��ʽ������ ��������������

	//��ʽ���ݷ�
	//Person p1 = 20;
	//Person p2 = p1;  //�������к���һ��
}



void doWork(Person p) {}

Person doWork01() {
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}

//�������캯���ĵ���ʱ����
void test02() {
	Person p;
	doWork(p);  //���з��ֳ��˴������޲ι��캯�����⣬����һ���������캯����˵�����ݶ��������ʱ��࿽��һ���������
}

void test03() {
	Person p = doWork01();
	cout << (int*)&p << endl;  //����ˣ��������������ÿ������캯���ģ���ַӦ�ò�ͬ�Ŷ�
}



int main() {
	//test01();
	//test02();
	test03();

	system("pause");

	return 0;
}