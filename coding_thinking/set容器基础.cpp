#include<iostream>
using namespace std;
#include<set>

//STL的三大组件：容器，迭代器，算法
// set是哈希表的经典容器，一种典型的哈希表为数组，其特点为有序哈希表，unordered_set特点为无序散列表
//set容器构造和赋值
void printSet(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test() {
	set<int> s;  //创建容器

	//插入数据，只有insert
	s.insert(10);
	s.insert(30);
	s.insert(20);  //输出可以观察到容器数值是自动从小到大排序了的
	s.insert(20);  //自动去重

	//遍历输出
	printSet(s);

	//拷贝构造
	set<int> s1(s);

	//赋值操作
	set<int> s2;
	s2 = s;

	//容器大小
	if (s.empty()) cout << "empty" << endl;   //判断是否空
	cout << s.size() << endl;

	//交换
	s1.insert(400);
	s.swap(s1);
	printSet(s);

	//删除
	cout << "删除操作：" << endl;
	s.erase(s.begin());
	printSet(s);
	s.erase(30);
	printSet(s);
	s.erase(s.begin(), s.end()); //s.clear();
	printSet(s);

	//查找
	set<int>::iterator pos = s1.find(30);  //返回为迭代器类型
	if (pos != s1.end()) {
		cout << "找到了元素" << *pos << endl;
	}
	else {
		cout << "未找到" << endl;
	}

	//数量
	multiset<int> m_s = { 10, 30, 30, 20, 40 };
	cout << "在mutiset中的计算特定元素数量：" << m_s.count(30) << endl;

	//关于pair
	pair<string, int> p = make_pair("jerry", 20);  //创建一个值对
	cout << "name:" << p.second << "age:" << p.first << endl;

}

void test01() {
	set<int> s;  //创建容器

	//插入数据，只有insert
	s.insert(10);
	s.insert(40);
	s.insert(20);  
	s.insert(50);  
	s.insert(30);

	printSet(s);

	//指定排序为从大到小排序

}

class Person {
public:
	Person(string name, int age) : name(name), age(age) {}

	string name;
	int age;
};

class comparePerson {
public:
	bool operator()(const Person& p1, const Person& p2) const{   //使用引用防止拷贝构造的出现，注意这里的const，不加会报错，以后回来追究原因
		//希望以降序年龄的方式进行排序
		return p1.age > p2.age;
	}
};

//自定义元素类型的set
void test02() {
	//set<Person> s;  //如果直接使用这句，set将不知道使用什么参数进行排序，所以会报错
	set<Person, comparePerson> s;

	//先创建对象，初始化
	Person p1("刘备", 24);
	Person p2("关羽", 22);
	Person p3("张飞", 20);
	Person p4("刘备", 24);

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