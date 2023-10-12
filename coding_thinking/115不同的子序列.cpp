#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        //dp��ʾ��s��i-1Ϊ��β��t����j-1Ϊ��βʱ��s�������а������ٸ�t
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        //��ʼ��
        for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                //���һ������β���ַ���ȣ����·��ͨ��dp[i-1][j-1]Ӧ�����̳С�ͬʱ����s����һ���ַ���β��ʱ���s����t��������
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

                //�����������β�ַ������ʱ����ô�ͽ�������֮ǰ������
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