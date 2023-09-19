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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummyHead = new ListNode;
		dummyHead->next = head;
		ListNode* fast = dummyHead;
		ListNode* slow = dummyHead;
		while (n--) {
			fast = fast->next;
		}
		while (fast->next != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		ListNode* tmp = slow->next;
		slow->next = slow->next->next;
		delete tmp;
		return dummyHead->next;
	}
}solution;

int main() {
	int n = 6;  //链表长度
	ListNode* head = CreatList(n);
	head = solution.removeNthFromEnd(head, 2); 
	while (head != nullptr) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}