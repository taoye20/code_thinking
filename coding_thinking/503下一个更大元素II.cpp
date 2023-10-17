#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> n(nums.begin(), nums.end());
        n.insert(n.end(), nums.begin(), nums.end());
        vector<int> res(n.size(), -1);
        stack<int> st;
        st.push(0);

        for (int i = 1; i < n.size(); i++) {
            while (!st.empty() && n[i] > n[st.top()]) {
                res[st.top()] = n[i];
                st.pop();
            }
            st.push(i);
        }
        res.resize(nums.size());
        return res;
    }
}solution;

int main() {
    vector<int> nums = { 1,2,1 };
    vector<int> res = solution.nextGreaterElements(nums);
    for (int i : res) {
        cout << i << endl;
    }
    return 0;
}