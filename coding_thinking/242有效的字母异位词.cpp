#include<iostream>
using namespace std;

/*
���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�

ʾ�� 1: ����: s = "anagram", t = "nagaram" ���: true

ʾ�� 2: ����: s = "rat", t = "car" ���: false

˵��: ����Լ����ַ���ֻ����Сд��ĸ��
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