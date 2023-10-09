#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        //1��ȷ��dp�������ĺ��壺���鱣��fib����
        vector<int> dp(n + 1);

        //ȷ�����ƹ�ʽ
        //��ʼ������
        if (n <= 1) return n;
        dp[0] = 0;
        dp[1] = 1;

        //����˳���ǰ����
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}solution;

int main() {
    cout << solution.fib(3) << endl;
    return 0;
}