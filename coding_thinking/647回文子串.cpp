#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {  // ע�����˳��
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) { // ���һ �� �����
                        result++;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1]) { // �����
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
}solution;

int main() {
    string s = "aaa";
    cout << solution.countSubstrings(s) << endl;
    return 0;
}