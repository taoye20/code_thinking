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
	ListNode* tmp = nullptr;
	for (int i = 0; i < n - 1; i++) {
		cout << "����ֵ��";
		cin >> p->val;
		p = new ListNode;
		p_tmp->next = p;
		p_tmp = p;
		if (i == 2) tmp = p;
	}
	cout << "����ֵ��";
	cin >> p->val;
	p->next = tmp;
	return head;
}

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				ListNode* tmp = head;
				while (tmp != fast) {
					tmp = tmp->next;
					fast = fast->next;
				}
				return fast;
			}
		}
		return nullptr;
	}
}solution;

int main() {
	int n = 6;  //������
	ListNode* head = CreatList(n);
	head = solution.detectCycle(head);
	cout << head->val << endl;
	return 0;
}