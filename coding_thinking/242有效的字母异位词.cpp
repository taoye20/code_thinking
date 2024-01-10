#include<iostream>
using namespace std;

/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1: 输入: s = "anagram", t = "nagaram" 输出: true

示例 2: 输入: s = "rat", t = "car" 输出: false

说明: 你可以假设字符串只包含小写字母。
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int hash[26] = { 0 };
        for (char c : s) {
            hash[c - 'a']++;
        }
        for (char c : t) {
            hash[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) return false;
        }
        return true;
    }
}solution;

//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        int recode[26] = { 0 };
//        for (int i = 0; i < s.size(); i++) {
//            recode[s[i] - 'a']++;
//        }
//        for (int i = 0; i < t.size(); i++) {
//            recode[t[i] - 'a']--;
//        }
//        for (int i = 0; i < 26; i++) {
//            if (recode[i] != 0) return false;
//        }
//        return true;
//    }
//}solution;

int main() {
    string s = "aee";
    string t = "eae";
    cout << solution.isAnagram(s, t) << endl;
	return 0;
}