#include <iostream>
#include <vector>
#include <algorithm>

bool isPossible(const std::vector<int>& permutation, int k) {
    int n = permutation.size();

    // Check if k is larger than n
    if (k > n) {
        return false;
    }

    // Copy the permutation and sort it
    std::vector<int> sortedPermutation = permutation;
    std::sort(sortedPermutation.begin(), sortedPermutation.end());

    // Check if there is a subsequence of length k in the sorted permutation
    for (int i = 0; i <= n - k; i++) {
        bool found = true;
        for (int j = i; j < i + k; j++) {
            if (permutation[j] != sortedPermutation[j - i]) {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }

    // Check if there is a subsequence of length k-1 that can be obtained
    // by swapping two elements in the original permutation
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            std::vector<int> swappedPermutation = permutation;
            std::swap(swappedPermutation[i], swappedPermutation[j]);
            std::sort(swappedPermutation.begin() + i, swappedPermutation.begin() + i + k);
            bool found = true;
            for (int m = i; m < i + k; m++) {
                if (swappedPermutation[m] != sortedPermutation[m]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }

    return false;
}

int main() {

}