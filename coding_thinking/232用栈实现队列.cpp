#include<iostream>
#include<stack>
using namespace std;

/*
ʹ��ջʵ�ֶ��е����в�����

push(x) -- ��һ��Ԫ�ط�����е�β����
pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
peek() -- ���ض����ײ���Ԫ�ء�
empty() -- ���ض����Ƿ�Ϊ�ա�

ʾ��:

MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // ���� 1
queue.pop();   // ���� 1
queue.empty(); // ���� false
*/

class MyQueue {
public:
	stack<int> stin;
	stack<int> stout;

	MyQueue() {}

	MyQueue(int x) {
		stin.push(x);
	}

	void push(int x) {
		stin.push(x);
	}

	int pop() {
		if (stout.empty()) {
			while (!stin.empty()) {
				stout.push(stin.top());
				stin.pop();
			}
		}
		int tmp = stout.top();
		stout.pop();
		return tmp;
	}

	int peek() {
		int res = this->pop();
		stout.push(res);
		return res;
	}

	bool empty() {
		if (stin.empty() && stout.empty()) return true;
		else return false;
	}
};

int main() {
	MyQueue queue;
	queue.push(1);
	queue.push(2);
	cout << queue.peek() << endl;  // ���� 1
	queue.pop();   // ���� 1
	cout << queue.empty() << endl; // ���� false
	return 0;
}
