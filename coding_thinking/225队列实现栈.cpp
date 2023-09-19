#include<iostream>
#include<queue>
using namespace std;

/*
ʹ�ö���ʵ��ջ�����в�����

push(x) -- Ԫ�� x ��ջ
pop() -- �Ƴ�ջ��Ԫ��
top() -- ��ȡջ��Ԫ��
empty() -- ����ջ�Ƿ�Ϊ��
ע��:

��ֻ��ʹ�ö��еĻ�������-- Ҳ���� push to back, peek/pop from front, size, �� is empty ��Щ�����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���� deque��˫�˶��У���ģ��һ������ , ֻҪ�Ǳ�׼�Ķ��в������ɡ�
����Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������
*/

class MyStack {
public:
	queue<int> que;

	void push(int x) {
		que.push(x);
	}

	void pop() {
		int n = que.size() - 1;
		while (n--) {
			que.push(que.front());
			que.pop();
		}
		que.pop();
	}

	int top() {
		int n = que.size() - 1;
		while (n--) {
			que.push(que.front());
			que.pop();
		}
		int res = que.front();
		que.push(res);
		que.pop();
		return res;
	}

	bool empty() {
		return que.empty();
	}
};

int main() {
	Mystack st;
	st.push(1);
	st.push(2);
	cout << st.top() << endl;
	st.pop();   // ע�ⵯ���Ĳ���
	cout << st.top() << endl;
	st.push(3);
	st.push(4);
	cout << st.top() << endl;
	st.pop();  // ע�ⵯ���Ĳ���    
	st.pop();
	st.pop();
	st.empty();
}