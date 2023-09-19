#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
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
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) return head;
		ListNode* cur = head;
		ListNode* pre = nullptr;
		ListNode* tmp;
		while (cur != nullptr) {
			tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
}solution;

//�ݹ�ķ�������ͬ�������ѭ��
//class Solution {
//public:
//	ListNode* reverse(ListNode* pre, ListNode* cur) {
//		if (cur == NULL) return pre;
//		ListNode* temp = cur->next;
//		cur->next = pre;
//		// ���Ժ�˫ָ�뷨�Ĵ�����жԱȣ����µݹ��д������ʵ��������������
//		// pre = cur;
//		// cur = temp;
//		return reverse(cur, temp);
//	}
//	ListNode* reverseList(ListNode* head) {
//		// ��˫ָ�뷨��ʼ����һ�����߼�
//		// ListNode* cur = head;
//		// ListNode* pre = NULL;
//		return reverse(NULL, head);
//	}
//
//};

int main() {
	int n = 5;  //������
	ListNode* head = CreatList(n);
	head = solution.reverseList(head);
	while (head != nullptr) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}