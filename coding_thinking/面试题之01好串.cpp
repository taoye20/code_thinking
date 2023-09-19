#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	bool isGood(vector<string>& vec, int beginIndex, int endIndex) {
		stack<string> st;
		for (int i = beginIndex; i <= endIndex; i++) {
			if (st.empty() && vec[i] == "1") return false;
			else if (vec[i] == "1") st.pop();
			else if (vec[i] == "0") st.push("0");
		}
		return true;
	}

	int numofGood(vector<string>& vec) {
		int beginIndex = 0;
		int endIndex = 0;
		int count = 0;
		//while (vec[beginIndex] == "1") {
		//	beginIndex++;
		//	endIndex++;
		//}
		while (endIndex < vec.size()) {
			for (int i = beginIndex; i <= endIndex; i++) {
				if(isGood(vec, i, endIndex)) count++;
			}
			endIndex++;
		}
		return count;
	}
}solution;

int main() {
	vector<string> vec = { "1", "0", "0" };
	cout << solution.numofGood(vec);
	return 0;
}