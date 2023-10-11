#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	////»ØËÝËã·¨µÄ¸´Ï°
	//bool backtracking(const string& s, unordered_set<string> wordSet, int startIndex) {
	//	if (startIndex >= s.size()) return true;
	//	for (int i = startIndex; i < s.size(); i++) {
	//		string word = s.substr(startIndex, i - startIndex + 1);
	//		if (wordSet.find(word) != wordSet.end() && backtracking(s, wordSet, i + 1)) return true;
	//	}
	//	return false;
	//}

	//bool wordBreak(string s, vector<string>& wordDict) {
	//	unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
	//	return backtracking(s, wordSet, 0);
	//}

	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.length() + 1, 0);
		dp[0] = true;
		for (int j = 1; j <= s.size(); j++) {
			for (int i = 0; i < wordDict.size(); i++) {
				if (j < wordDict[i].size()) continue;
				string word = s.substr(j - wordDict[i].size(), wordDict[i].size());
				if (word.compare(wordDict[i]) == 0 && dp[j - wordDict[i].size()] == true) {
					dp[j] = true;
				}
			}
		}
		return dp[s.size()];
	}
}solution;

int main() {
	string s = "leetcode";
	vector<string> wordDict = { "leet", "code" };
	cout << solution.wordBreak(s, wordDict) << endl;
	return 0;
}