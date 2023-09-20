#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmd(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmd);
        int res = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i - 1][1] < points[i][0]) {
                res++;
            }
            else {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }
        return res;
    }
}solution;

int main() {
    vector<vector<int>> points = { {1,2} };
    int res = solution.findMinArrowShots(points);
    cout << res << endl;
    return 0;
}