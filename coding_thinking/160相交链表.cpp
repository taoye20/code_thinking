#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() {}
	ListNode(int a) : val(a), next(nullptr) {}
};

//��������Ϊn����������ֵ
ListNode* CreatList(int n) {
	ListNode* head = new ListNode;
	ListNode* p = head;
	ListNode* p_tmp = head;
	for (int i = 0; i < n - 1; i++) {
		cout << "����ֵ��";
		cin >> p->val;
		p = new ListNode;
		p_tmp->next = p;
		p_tmp = p;
	}
	cout << "����ֵ��";
	cin >> p->val;
	p->next = nullptr;
	return head;
}

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		
	}
}solution;

int main() {
	int n = 6;  //������
	ListNode* head = CreatList(n);
	head = solution.getIntersectionNode(head, 2);
	while (head != nullptr) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}