#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int zeroNum = 0, oneNum = 0;
            for (char s : str) {
                if (s == '0') zeroNum++;
                else oneNum++;
            }
            for (int i = m; i >= zeroNum; i--) {
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
}solution;

int main() {
    vector<string> strs = { "10", "0001", "111001", "1", "0" };
    int m = 5;
    int n = 3;
    cout << solution.findMaxForm(strs, m, n) << endl;
    return 0;
}