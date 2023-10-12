#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //bool isSubsequence(string s, string t) {
    //    int j = 0;
    //    for (int i = 0; i < s.size(); i++) {
    //        if (j >= t.size()) return false;
    //        while (s[i] != t[j]) {
    //            j++;
    //            if (j >= t.size()) return false;
    //        }
    //        j++;
    //    }
    //    return true;
    //}

    //动态规划方法
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;  //dp表示在扫描到此时时，前面满足对应的符号数
                else dp[i][j] = dp[i][j - 1];
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
}solution;

int main() {
    string s = "aaaaaa";
    string t = "bbaaaa";
    cout << solution.isSubsequence(s, t) << endl;
    return 0;
}