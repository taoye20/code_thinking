#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {  //i/2是因为后面的j和i-j是对称的可以不用重复计算了
                dp[i] = max({ dp[i], j * (i - j), j * dp[i - j] });
            }
        }
        return dp[n];
    }
}solution;

int main() {
    cout << solution.integerBreak(10) << endl;
    return 0;
}