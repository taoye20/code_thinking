#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() {}
	ListNode(int a) : val(a), next(nullptr) {}
};

//创建长度为n的链表，并赋值
ListNode* CreatList(int n) {
	ListNode* head = new ListNode;
	ListNode* p = head;
	ListNode* p_tmp = head;
	for (int i = 0; i < n - 1; i++) {
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
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = dummyHead;
		ListNode* tmp1 = nullptr;
		ListNode* tmp2 = nullptr;
		while (cur->next != nullptr && cur->next->next != nullptr) {
			tmp1 = cur->next;
			cur->next = cur->next->next;
			tmp2 = cur->next->next;
			cur->next->next = tmp1;
			tmp1->next = tmp2;
			cur = tmp1;
		}
		return dummyHead->next;
	}
}solution;

int main() {
	int n = 6;  //链表长度
	ListNode* head = CreatList(n);
	head = solution.swapPairs(head);
	while (head != nullptr) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}