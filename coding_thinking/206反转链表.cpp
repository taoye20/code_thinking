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

//递归的方法，等同于上面的循环
//class Solution {
//public:
//	ListNode* reverse(ListNode* pre, ListNode* cur) {
//		if (cur == NULL) return pre;
//		ListNode* temp = cur->next;
//		cur->next = pre;
//		// 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
//		// pre = cur;
//		// cur = temp;
//		return reverse(cur, temp);
//	}
//	ListNode* reverseList(ListNode* head) {
//		// 和双指针法初始化是一样的逻辑
//		// ListNode* cur = head;
//		// ListNode* pre = NULL;
//		return reverse(NULL, head);
//	}
//
//};

int main() {
	int n = 5;  //链表长度
	ListNode* head = CreatList(n);
	head = solution.reverseList(head);
	while (head != nullptr) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}