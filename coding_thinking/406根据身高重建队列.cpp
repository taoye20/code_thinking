#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];  //ע�⣬�������߶�һ���Ĵ���ʱ��Ӧ������λǰ���ȷ��ʣ���Ϊ��Ŀ����ǰ��������Ǹ߶��Ǵ��ڵ��ڣ�����Ҳ��
        else return a[0] > b[0];
    }

    //vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    //    //sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {return a[0] > b[0]; });
    //    sort(people.begin(), people.end(), cmp);
    //    vector<vector<int>> res;
    //    for (int i = 0; i < people.size(); i++) {
    //        int position = people[i][1];
    //        res.insert(res.begin() + position, people[i]);
    //    }
    //    return res;
    //}

    //ʹ��list����Ч�����
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> res;
        for (int i = 0; i < people.size(); i++) {
            int position = people[i][1];
            list<vector<int>>::iterator it = res.begin();
            while (position--) {
                it++;
            }
            res.insert(it, people[i]);
        }
        vector<vector<int>> result(res.begin(), res.end());
        return result;
    }
}solution;

int main() {
    vector<vector<int>> people = { {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2} };
    vector<vector<int>> res = solution.reconstructQueue(people);
    for (vector<int> i : res) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}