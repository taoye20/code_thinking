#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    bool isvalid(const string& s, int start, int end) {
        if (start > end) return false; //这里没加会出错，最后一个点可能打在末尾并输出了true
        if (s[start] == '0' && start != end) return false;
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') return false;
            num = num * 10 + s[i] - '0';
            if (num > 255) return false;
        }
        return true;
    }

    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (isvalid(s, startIndex, s.size() - 1)) {
                res.push_back(s);
                return;
            }
        }
        for (int i = startIndex; i < startIndex + 3 && i < s.size(); i++) {
            if (isvalid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracking(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }
            else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)return res;
        backtracking(s, 0, 0);
        return res;
    }
}solution;

int main() {
    vector<string> res = solution.restoreIpAddresses("25525511135");
    for (string i : res) cout << i << endl;
    return 0;
}

