#include<iostream>
using namespace std;


/*
在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

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
			tmp = nullptr;  //为了防止之后的程序调用了该参数但是是一个随意的地址，因此要把该指针指会null
			_size--;
		}
	}

private:
	int _size;   //命名规范
	ListNode* _dummyHead;
};


int main() {
	while (head != nullptr) {
		cout << head->val << endl;
		head = head->next;
	}
	return 0;
}