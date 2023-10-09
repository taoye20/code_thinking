#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        //1，确定dp数组代表的含义：数组保存fib数列
        vector<int> dp(n + 1);

        //确定递推公式
        //初始化参数
        if (n <= 1) return n;
        dp[0] = 0;
        dp[1] = 1;

        //递推顺序从前往后
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