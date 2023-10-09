#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int distant[26] = { 0 };
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            distant[s[i] - 'a'] = i;
        }
        int index = 0;
        int begin = 0;
        for (int i = 0; i < s.size(); i++) {
            index = max(index, distant[s[i] - 'a']);
            if (i == index) {
                res.push_back(index - begin + 1);
                begin = index + 1;
            }
        }
        return res;
    }
}solution;

int main() {
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = solution.partitionLabels(s);
    for (int i : res) {
        cout << i << endl;
    }
    return 0;
}