#include<iostream>
using namespace std;
#include<set>

//STL��������������������������㷨
// set�ǹ�ϣ��ľ���������һ�ֵ��͵Ĺ�ϣ��Ϊ���飬���ص�Ϊ�����ϣ��unordered_set�ص�Ϊ����ɢ�б�
//set��������͸�ֵ
void printSet(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test() {
	set<int> s;  //��������

	//�������ݣ�ֻ��insert
	s.insert(10);
	s.insert(30);
	s.insert(20);  //������Թ۲쵽������ֵ���Զ���С���������˵�
	s.insert(20);  //�Զ�ȥ��

	//�������
	printSet(s);

	//��������
	set<int> s1(s);

	//��ֵ����
	set<int> s2;
	s2 = s;

	//������С
	if (s.empty()) cout << "empty" << endl;   //�ж��Ƿ��
	cout << s.size() << endl;

	//����
	s1.insert(400);
	s.swap(s1);
	printSet(s);

	//ɾ��
	cout << "ɾ��������" << endl;
	s.erase(s.begin());
	printSet(s);
	s.erase(30);
	printSet(s);
	s.erase(s.begin(), s.end()); //s.clear();
	printSet(s);

	//����
	set<int>::iterator pos = s1.find(30);  //����Ϊ����������
	if (pos != s1.end()) {
		cout << "�ҵ���Ԫ��" << *pos << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}

	//����
	multiset<int> m_s = { 10, 30, 30, 20, 40 };
	cout << "��mutiset�еļ����ض�Ԫ��������" << m_s.count(30) << endl;

	//����pair
	pair<string, int> p = make_pair("jerry", 20);  //����һ��ֵ��
	cout << "name:" << p.second << "age:" << p.first << endl;

}

void test01() {
	set<int> s;  //��������

	//�������ݣ�ֻ��insert
	s.insert(10);
	s.insert(40);
	s.insert(20);  
	s.insert(50);  
	s.insert(30);

	printSet(s);

	//ָ������Ϊ�Ӵ�С����

}

class Person {
public:
	Person(string name, int age) : name(name), age(age) {}

	string name;
	int age;
};

class comparePerson {
public:
	bool operator()(const Person& p1, const Person& p2) const{   //ʹ�����÷�ֹ��������ĳ��֣�ע�������const�����ӻᱨ���Ժ����׷��ԭ��
		//ϣ���Խ�������ķ�ʽ��������
		return p1.age > p2.age;
	}
};

//�Զ���Ԫ�����͵�set
void test02() {
	//set<Person> s;  //���ֱ��ʹ����䣬set����֪��ʹ��ʲô���������������Իᱨ��
	set<Person, comparePerson> s;

	//�ȴ������󣬳�ʼ��
	Person p1("����", 24);
	Person p2("����", 22);
	Person p3("�ŷ�", 20);
	Person p4("����", 24);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++) {
		cout << it->name << " " << it->age << endl;
	}
}

int main() {
	test02();
	return 0;
}