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
	for (int i = 0; i < n-1; i++) {
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
	ListNode* removeElements(ListNode* head, int val) {
		//��������ͷ�ڵ�
		ListNode* dummyHead = new ListNode;
		dummyHead->next = head;
		ListNode* cur = dummyHead;

		//����ɾ��
		while (cur->next != nullptr) {
			if (cur->next->val == val) {
				ListNode* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			}
			else cur = cur->next;
		}

		//ɾ������ڵ�
		head = dummyHead->next;  //���ǳ���Ҫ����Ϊ���ԭhead��ɾ���ˣ���ôû�����ͻᵼ�·��ش���
		delete dummyHead;
		return head;
	}
}solution;

int main() {
	int n = 5;  //������
	ListNode* head = CreatList(n);
	head = solution.removeElements(head, 5);
	while (head != nullptr) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}