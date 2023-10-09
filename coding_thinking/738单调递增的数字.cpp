#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i] < strNum[i - 1]) {
                strNum[i - 1]--;
                flag = i;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
}solution;

int main() {
    int n = 323;
    int res = solution.monotoneIncreasingDigits(n);
    cout << res << endl;
    return 0;
}