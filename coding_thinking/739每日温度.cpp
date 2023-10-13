#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
}solution;

int main() {
    vector<int> tem = { 73,74,75,71,69,72,76,73 };
    vector<int> res = solution.dailyTemperatures(tem);
    for (int i : res) {
        cout << i << endl;
    }
    return 0;
}