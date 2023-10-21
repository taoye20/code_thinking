#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wlist_set(wordList.begin(), wordList.end());   //方便寻找快速
        if (wlist_set.find(endWord) == wlist_set.end()) return 0;
        unordered_map<string, int> path_map;   //记录已经赋值过的和赋的路径数值
        path_map[beginWord] = 1;
        queue<string> que;
        que.push(beginWord);

        while (!que.empty()) {
            string word = que.front();
            que.pop();
            for (int i = 0; i < word.size(); i++) {
                string newword = word;
                for (int j = 0; j < 26; j++) {
                    newword[i] = j + 'a';
                    if (wlist_set.find(newword) != wlist_set.end() && path_map.find(newword) == path_map.end()) {
                        path_map[newword] = path_map[word] + 1;
                        if (newword == endWord) return path_map[newword];
                        que.push(newword);
                    }
                }
            }
        }
        return 0;
    }
}solution;

int main() {
    string begin = "hit";
    string end = "cog";
    vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };
    cout << solution.ladderLength(begin, end, wordList) << endl;
    return 0;
}