#include<iostream>
using namespace std;

class KMP {
public:
	//根据匹配参考字符串构建状态转移表
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

		//初始化状态转移表[state][curinput] = [destination_state]
		dp[0][pat[0]] = 1;  //只有等于第一个字符的匹配才能转移到下一个状态

		//设置影子状态
		int x = 0;

		//开始为转移表赋值
		for (int j = 1; j < m; j++) {
			for (int c = 0; c < 256; c++) {
				dp[j][c] = dp[x][c];
			}
			dp[j][pat[j]] = j + 1;
			x = dp[x][pat[j]];  //这步非常精妙，如果影子状态与当前状态匹配的符号相同，那么x就会前进
		}
	}

	int search(string txt) {
		int j = 0;
		int m = pat.length();
		for (int i = 0; i < txt.length(); i++) {
			j = dp[j][txt[i]];    //转移状态
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