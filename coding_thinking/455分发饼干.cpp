#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    //int findContentChildren(vector<int>& g, vector<int>& s) {
    //    sort(g.begin(), g.end());
    //    sort(s.begin(), s.end());
    //    int index = s.size() - 1;
    //    int res = 0;
    //    for (int i = g.size() - 1; i >= 0 && index >= 0; i--) {
    //        if (g[i] <= s[index]) {
    //            res++;
    //            index--;
    //        }
    //    }
    //    return res;
    //}

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int index = 0;
        for (int i = 0; i < s.size() && index < g.size(); i++) {
            if (g[index] <= s[i]) {
                index++;
                res++;
            }
        }
        return res;
    }
}solution;

int main() {
    vector<int> g = { 1,2 };
    vector<int> s = { 1,2,3 };
    int res = solution.findContentChildren(g, s);
    cout << res << endl;
    return 0;
}