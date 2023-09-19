#include<iostream>
using namespace std;


/*
����������ʵ����Щ���ܣ�

get(index)����ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
addAtTail(val)����ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
addAtIndex(index,val)���������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ㡣
deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣

*/


class MyLinkedList {
public:
	MyLinkedList() {
		_dummyHead = new ListNode(0);
		_size = 0;
	}

	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode(int val) : val(val), next(nullptr) {}
	};


	int get(int index) {
		if (index > _size - 1 || index < 0) {
			return -1;
		}
		ListNode* cur = _dummyHead->next;
		while (index--) {
			cur = cur->next;
		}
		return cur->val;
	}

	void addAtHead(int val) {
		ListNode* newnode = new ListNode(val);
		newnode->next = _dummyHead->next;
		_dummyHead->next = newnode;
		_size++;
	}

	void addAtTail(int val) {
		ListNode* cur = _dummyHead;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		ListNode* newnode = new ListNode(val);
		cur->next = newnode;
		_size++;
	}

	void addAtIndex(int index, int val) {
		if (index < 0) index = 0;
		if (index > _size) return;
		ListNode* newnode = new ListNode(val);
		ListNode* cur = _dummyHead;
		while (index--) {
			cur = cur->next;
		}
		newnode->next = cur->next;
		cur->next = newnode;
		_size++;
	}

	void deleteAtIndex(int index) {
		if (index >= 0 && index < _size) {
			ListNode* cur = _dummyHead;
			while (index--) {
				cur = cur->next;
			}
			ListNode* tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
			tmp = nullptr;  //Ϊ�˷�ֹ֮��ĳ�������˸ò���������һ������ĵ�ַ�����Ҫ�Ѹ�ָ��ָ��null
			_size--;
		}
	}

private:
	int _size;   //�����淶
	ListNode* _dummyHead;
};


int main() {
	while (head != nullptr) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}