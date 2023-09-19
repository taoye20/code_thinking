#include<iostream>
using namespace std;

class KMP {
public:
	//����ƥ��ο��ַ�������״̬ת�Ʊ�
	KMP(string pat) {
		this->pat = pat;
		int m = pat.length();
		dp = new int *[m];
		for (int i = 0; i < m; i++) {
			dp[i] = new int[256];
			for (int j = 0; j < 256; j++) {
				dp[i][j] = 0;
			}
		}

		//��ʼ��״̬ת�Ʊ�[state][curinput] = [destination_state]
		dp[0][pat[0]] = 1;  //ֻ�е��ڵ�һ���ַ���ƥ�����ת�Ƶ���һ��״̬

		//����Ӱ��״̬
		int x = 0;

		//��ʼΪת�Ʊ�ֵ
		for (int j = 1; j < m; j++) {
			for (int c = 0; c < 256; c++) {
				dp[j][c] = dp[x][c];
			}
			dp[j][pat[j]] = j + 1;
			x = dp[x][pat[j]];  //�ⲽ�ǳ�������Ӱ��״̬�뵱ǰ״̬ƥ��ķ�����ͬ����ôx�ͻ�ǰ��
		}
	}

	int search(string txt) {
		int j = 0;
		int m = pat.length();
		for (int i = 0; i < txt.length(); i++) {
			j = dp[j][txt[i]];    //ת��״̬
			if (j == m) return i - m + 1;
		}
		return -1;
	}
private:
	string pat;
	int** dp;
};

int main() {
	KMP kmp("aaab");
	int res = kmp.search("aaacaaab");
	cout << res << endl;
	return 0;
}