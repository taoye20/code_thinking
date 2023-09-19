#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

//创建长度为n的链表，并赋值
ListNode* CreatList(int n) {
	ListNode* head = new ListNode;
	ListNode* p = head;
	ListNode* p_tmp = head;
	for (int i = 0; i < n-1; i++) {
		cout << "输入值：";
		cin >> p->val;
		p = new ListNode;
		p_tmp->next = p;
		p_tmp = p;
	}
	cout << "输入值：";
	cin >> p->val;
	p->next = nullptr;
	return head;
}

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		//创建虚拟头节点
		ListNode* dummyHead = new ListNode;
		dummyHead->next = head;
		ListNode* cur = dummyHead;

		//查找删除
		while (cur->next != nullptr) {
			if (cur->next->val == val) {
				ListNode* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
			else cur = cur->next;
		}

		//删除虚拟节点
		head = dummyHead->next;  //这句非常重要，因为如果原head被删除了，那么没有这句就会导致返回错误
		delete dummyHead;
		return head;
	}
}solution;

int main() {
	int n = 5;  //链表长度
	ListNode* head = CreatList(n);
	head = solution.removeElements(head, 5);
	while (head != nullptr) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}