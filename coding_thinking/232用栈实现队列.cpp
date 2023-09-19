#include<iostream>
#include<stack>
using namespace std;

/*
使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。

示例:

MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
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
	cout << queue.peek() << endl;  // 返回 1
	queue.pop();   // 返回 1
	cout << queue.empty() << endl; // 返回 false
	return 0;
}
