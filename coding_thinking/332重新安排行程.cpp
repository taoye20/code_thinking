#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& result) {
        if (result.size() >= ticketNum + 1) return true;
        for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
            if (target.second > 0) {
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                target.second++;
                result.pop_back();
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        for (vector<string> vec : tickets) {
            targets[vec[0]][vec[1]]++;
        }
        res.push_back("JFK");
        backtracking(tickets.size(), res);
        return res;
    }
}solution;

int main() {
    vector<vector<string>> tickets = { {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"} ,{"LHR", "SFO"} };
    vector<string> res = solution.findItinerary(tickets);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}