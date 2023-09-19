#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
    };
    vector<string> res;
    string path;
    void backtracking(string& digits, int digitsIndex) {
        if (path.length() == digits.length()) {
            res.push_back(path);
            return;
        }
        int digit = digits[digitsIndex] - '0';
        for (int i = 0; i < letterMap[digit].length(); i++) {
            path.push_back(letterMap[digit][i]);
            backtracking(digits, digitsIndex + 1);
            path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return res;
        backtracking(digits, 0);
        return res;
    }
}solution;

int main() {
    vector<string> res = solution.letterCombinations("23");
    for (string i : res) {
        cout << i << endl;
    }
    return 0;
}
