#include<iostream>
#include<vector>
using namespace std;

class Solultion {
public:
	vector<int> changen(vector<int>& n) {
		int fast = 0;
		int slow = 0;
		while (fast < n.size()) {
			while (n[slow] % 2 == 0 && slow < n.size()) {
				slow++;
			}
			fast = slow + 1;
			while (n[slow] % 2 == 0 && fast < n.size()) {
				fast++;
			}
			n[slow] = (n[fast] + n[slow]) / 2;
			n.erase(n.begin() + fast);
		}
		return n;
	}
}solution;

int main() {
	vector<int> n = { 3, 3, 3, 5 };
	solution.changen(n);
	for (vector<int>::iterator it = n.begin(); it != n.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}