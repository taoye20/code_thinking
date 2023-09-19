#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    bool isstring(string s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void backtracking(string s, int startIndex) {
        if (startIndex >= s.length()) {
            res.push_back(path);
            return; 
        }
        for (int i = startIndex; i < s.length(); i++) {
            if (isstring(s, startIndex, i)) {
                path.push_back(s.substr(startIndex, i - startIndex + 1));  //注意这里使用的库函数
            }
            else continue;
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
}solution;

int main() {
    string s = "aab";
    vector<vector<string>> res = solution.partition(s);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

