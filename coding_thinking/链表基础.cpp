#include<iostream>
using namespace std;

////����һ������ڵ�
////������
//struct ListNode  //����class����Ϊ������Ҫ������������
//{
//	int val;
//	ListNode* next;  //����ָ��
//	//ListNode(int x) : val(x), next(nullptr) {}  //�вι��캯����Ҳ���Բ���д���������Զ�Я��
//};
//
//int main() {
//	//��ʼ������
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

//��������Ϊn������
ListNode* CreatList(int n) {
	ListNode* head = new ListNode;
	ListNode* p = head;
	ListNode* p_tmp = head;
	for (int i = 0; i < n - 1; i++) {  //ѭ����ӽڵ㲢��ֵ
		cout << "����ֵ��";
		cin >> p->val;
		p = new ListNode;   //���������½ڵ�
		p_tmp->next = p;
		p_tmp = p;
	}
	cout << "����ֵ��";
	cin >> p->val;
	p->next = nullptr;  //����βָ���
	return head;
}

int main() {
	ListNode* head = CreatList(3);
	cout << head->next->next->next->val << endl;
	return 0;
}