#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums2.size(); i++) {
            map[nums2[i]] = i;
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (map.find(nums1[i]) != map.end()) {
                for (int j = map[nums1[i]]; j < nums2.size(); j++) {
                    if (nums2[j] > nums1[i]) {
                        res[i] = nums2[j];
                        break;
                    }
                }
            }
        }
        return res;
    }
}solution;

int main() {
    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };
    vector<int> res = solution.nextGreaterElement(nums1, nums2);
    for (int i : res) {
        cout << i << endl;
    }
    return 0;
}