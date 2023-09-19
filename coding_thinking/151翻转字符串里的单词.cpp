#include<iostream>
using namespace std;

/*
����һ���ַ����������ת�ַ����е�ÿ�����ʡ�

ʾ�� 1��
����: "the sky is blue"
���: "blue is sky the"

ʾ�� 2��
����: "  hello world!  "
���: "world! hello"
����: �����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����

ʾ�� 3��
����: "a good   example"
���: "example good a"
����: ����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
*/

class Solution {
public:
	//��ת����
	void reverse(string& s,int begin,int end) {
		while (begin < end) {
			swap(s[begin], s[end]);
			begin++;
			end--;
		}
	}

	//ȥ������ո�ĺ���
	void removeSpace(string& s) {
		int slow = 0, fast = 0;
		for (; fast < s.size(); fast++) {
			if (s[fast] != ' ') {
				if (slow != 0) s[slow++] = ' ';
				while (s[fast] != ' ' && fast < s.size()) {  //ע��ÿ��whileʱҪ�������
					s[slow++] = s[fast++];
				}
			}
		}
		s.resize(slow);  //�ǵòü���С���������ʱ���������
	}

	//���ܵĺ���
	string reverseWords(string s) {
		//��ȥ������ո�
		removeSpace(s);
		//�����巴ת
		reverse(s, 0, s.size() - 1);
		//�����ʷ�ת
		for (int i = 0; i < s.size(); i++) {
			int j = i;
			while (s[j] != ' ' && j < s.size()) {
				j++;
			}
			reverse(s, i, j - 1);
			i = j;
		}
		return s;
	}
}solution;

int main() {
	string s = "a good   example";
	string res = solution.reverseWords(s);
	cout << res << endl;
	return 0;
}