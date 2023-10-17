#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0); // ����ͷ������Ԫ��0
        heights.push_back(0); // ����β������Ԫ��0
        st.push(0);
        int result = 0;
        for (int i = 1; i < heights.size(); i++) {
            while (heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int w = i - st.top() - 1;
                int h = heights[mid];
                result = max(result, w * h);
            }
            st.push(i);
        }
        return result;
    }
}solution;

int main() {
    vector<int> heights = { 2,1,5,6,2,3 };
    cout << solution.largestRectangleArea(heights) << endl;
    return 0;
}