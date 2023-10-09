#include<iostream>
#include<vector>
using namespace std;

//ʹ�û��ݵķ��������Ǵ������󣬶������׳�ʱ
//class Solution {
//public:
//	vector<int> path;
//	vector<int> res;
//	int resValue = 0;
//	void traversal(int startIndex, int weight, int value, vector<int>& n_weight, vector<int>& n_value) {
//		for (int i = startIndex; i < n_weight.size(); i++) {
//			weight -= n_weight[i];
//			value += n_value[i];
//			if (weight < 0) {
//				weight += n_weight[i];
//				value -= n_value[i];
//				if (value > resValue) {
//					resValue = value;
//					res = path;
//				}
//				return;
//			}
//			tarversal(startIndex + 1, weight, value, n_weight, n_value);
//			weight += n_weight[i];
//			value -= n_value[i];
//		}
//	}
//
//	int back(int weight, vector<int>& n_weight, vector<int>& n_value) {
//		traversal(0, weight, 0, n_weight, n_value);
//		return resValue;
//	}
//}solution;

//��������Ϊ��̬�滮����
//dpΪ��ά����i��jΪ���������д����i����Ʒ���б�ʾռ�õ��ݻ�j��dp�е�ֵ�����ֵ
//��ô���ƹ�ʽ����д��.1,��������Ʒi��dp[i][j] = dp[i-1][j]. 2,������Ʒi��dp[i][j] = dp[i-1][j-weight[i]] + value[i];
//class Solution {
//public:
//	int bag(int bagWeight, vector<int> weight, vector<int> value) {
//		vector<vector<int>> dp(weight.size(), vector<int>(bagWeight + 1, 0));
//		for (int i = weight[0]; i <= bagWeight; i++) {
//			dp[0][i] = value[0];
//		}
//		for (int i = 1; i < weight.size(); i++) {
//			for (int j = 1; j <= bagWeight; j++) {
//				if (j < weight[i]) continue;
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
//			}
//		}
//		return dp[weight.size() - 1][bagWeight];
//	}
//}solution;

//һά���ö�̬�滮��ʱ�̼�סdp�ĺ������Ķ�����ʲô
class Solution {
public:
	int bag(int bagWeight, vector<int> weight, vector<int> value) {
		vector<int> dp(bagWeight + 1, 0);
		for (int i = 0; i < weight.size(); i++) {
			for (int j = bagWeight; j >= weight[i]; j--) {  //j--����Ϊ��ͬһ�н��в����������˸������е����ݣ�������˳��ֵ����ִ���
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);  //�൱��ɨ��ÿһ����Ʒȥ���±����еļ�ֵ
			}
		}
		return dp[bagWeight];
	}
}solution;


int main() {
	vector<int> n_weight = { 1,3,4 };
	vector<int> n_value = { 15,20,30 };
	cout << solution.bag(4, n_weight, n_value) << endl;
	return 0;
}