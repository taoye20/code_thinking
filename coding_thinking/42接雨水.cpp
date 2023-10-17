#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        vector<int> lHeight(height.size(), 0);
        vector<int> rHeight(height.size(), 0);
        lHeight[0] = height[0];
        rHeight[height.size() - 1] = height[height.size() - 1];

        for (int i = 1; i < height.size(); i++) {
            lHeight[i] = max(height[i], lHeight[i - 1]);
        }
        for (int j = height.size() - 2; j >= 0; j--) {
            rHeight[j] = max(height[j], rHeight[j + 1]);
        }

        int res = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            res += min(lHeight[i], rHeight[i]) - height[i];
        }
        return res;
    }
}solution;

int main() {
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << solution.trap(height) << endl;
    return 0;
}