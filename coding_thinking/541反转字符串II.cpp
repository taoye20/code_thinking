#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            if (i + k > s.size()) {
                reverse(s.begin() + i, s.end());
                return s;
            }
            else {
                reverse(s.begin() + i, s.begin() + i + k);
            }
        }
        return s;
    }
}solution;

int main() {
    string s = "abcdefg";
    int k = 2;
    string res = solution.reverseStr(s, k);
    cout << res << endl;
}