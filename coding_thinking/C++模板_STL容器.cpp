#include<iostream>
#include<vector> //引入容器
using namespace std;

//STL标准模板库提供了通用的类和函数的模板，这些模板类和函数可以实现多种流行和常用的算法和数据结构，如向量、链表、队列、栈。
int main() {

	//创建数组容器，初始化可以不定义长度，具有数组性质且拥有高级功能
	vector<int> v;
	//vector<int> v = { 1, 2, 3, 4, 5 };  //初始化方法
	
	//查看容器最初的大小
	cout << "容器最初大小：" << v.size() << endl;



	//为容器赋值
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
	}

	//查看容器的大小，在数组中我们使用的是sizeof函数来计算数组实际的内存大小，容器该函数返回元素个数
	cout << "容器目前大小：" << v.size() << endl;



	//访问容器元素的两种方法
	//1.数组访问
	for (int i = 0; i < v.size(); i++) {
		cout << "第" << i << "个数据的值为：" << v[i] << endl;
	}

	//2.迭代器访问
	vector<int>::iterator n = v.begin(); //v.begin()是一个指针，指向第一个元素
	while (n != v.end()) {       //end指向最后一个元素的后一个地址
		cout << "迭代器指向的值为：" << *n << endl;
		n++;
	}


	//插入元素
	//方法1
	v.insert(v.begin() + 4, 100);  //位置，值

	//方法2
	vector<int> test{ 7, 8, 9 };
	v.insert(v.end(), test.begin(), test.end());



	//删除元素
	n = v.erase(v.begin() + 2);   //返回指针指向下一个值位置
	cout << "\n" << "容器删除元素后大小：" << v.size() << endl;
	while (n != v.end()) {       //end指向最后一个元素的后一个地址
		cout << "迭代器指向的值为：" << *n << endl;
		n++;
	}
}