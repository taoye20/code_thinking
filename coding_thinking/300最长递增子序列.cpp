#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp��ʾ��iΪ����ĩ��ʱ���ĵ�����������
        vector<int> dp(nums.size(), 1); //ע���ʼ��Ӧ������Ϊ1�����ٳ���Ϊ�Լ�
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > res) res = dp[i];  //������ҵ������
        }
        //return dp[nums.size() - 1];  //�����Ǵ���ģ���Ϊ���һ���������ڵ����в�һ�����������
        return res;
    }
}solution;

int main() {
    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    cout << solution.lengthOfLIS(nums) << endl;
    return 0;
}