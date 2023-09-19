#include<iostream>
using namespace std;

////创建一个链表节点
////单链表
//struct ListNode  //不用class是因为链表主要用作数据类型
//{
//	int val;
//	ListNode* next;  //该类指针
//	//ListNode(int x) : val(x), next(nullptr) {}  //有参构造函数，也可以不书写，编译器自动携带
//};
//
//int main() {
//	//初始化链表
//	//ListNode* head = new ListNode(5);
//	ListNode* head = new ListNode;
//	head->val = 5;
//	cout << head->val << endl;
//	return 0;
//}


struct ListNode
{
	int val;
	ListNode* next;
};

//创建长度为n的链表
ListNode* CreatList(int n) {
	ListNode* head = new ListNode;
	ListNode* p = head;
	ListNode* p_tmp = head;
	for (int i = 0; i < n - 1; i++) {  //循环添加节点并赋值
		cout << "输入值：";
		cin >> p->val;
		p = new ListNode;   //堆区开辟新节点
		p_tmp->next = p;
		p_tmp = p;
	}
	cout << "输入值：";
	cin >> p->val;
	p->next = nullptr;  //链表尾指向空
	return head;
}

int main() {
	ListNode* head = CreatList(3);
	cout << head->next->next->next->val << endl;
	return 0;
}