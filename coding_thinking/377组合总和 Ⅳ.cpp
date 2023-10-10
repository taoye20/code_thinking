#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;

        //��Ϻ����е�forѭ��˳���ǲ�ͬ�ģ���Ҫ������ᣬ����Ϊ����
        //��������ɣ���������Ϊ����ʱ����ѡ��ͬ����Ʒ���Է���
        //���������ϣ�(1,3)��(3,1)�ǲ�����ͬʱ���ڵģ���ô�Ͱ�����Ʒ�������ȳ�����Ʒ1������ִ�С�İ���·�������ٿ�����һ����Ʒ
        for (int j = 0; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (j >= nums[i]) dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
}solution;

int main() {
    vector<int> nums = { 1,2,3 };
    int target = 4;
    cout << solution.combinationSum4(nums, target) << endl;
    return 0;
}