#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        //dp表示在s以i-1为结尾，t在以j-1为结尾时，s子序列中包含多少个t
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        //初始化
        for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                //情况一：当结尾的字符相等，则该路径通，dp[i-1][j-1]应当被继承。同时加上s以上一个字符结尾的时候该s包含t的数量。
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

                //情况二：当结尾字符不相等时，那么就仅仅保持之前的数量
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
}solution;

int main() {
    string s = "rabbbit";
    string t = "rabbit";
    cout << solution.numDistinct(s, t) << endl;
    return 0;
}