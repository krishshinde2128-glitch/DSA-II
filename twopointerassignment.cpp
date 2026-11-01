#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int removeDuplicatesReference(const vector<int>& arr, vector<int>& unique) {
    unique.clear();
    for (int value : arr) {
        bool alreadyAdded = false;
        for (int existing : unique) {
            if (existing == value) {
                alreadyAdded = true;
                break;
            }
        }
        if (!alreadyAdded) unique.push_back(value);
    }
    return static_cast<int>(unique.size());
}

int removeDuplicatesTwoPointer(vector<int>& arr) {
    if (arr.empty()) return 0;

    int slow = 0;
    for (int fast = 1; fast < static_cast<int>(arr.size()); ++fast) {
        if (arr[fast] != arr[slow]) {
            ++slow;
            arr[slow] = arr[fast];
        }
    }
    return slow + 1;
}

pair<int, int> pairSumBruteForce(const vector<int>& arr, int target) {
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        for (int j = i + 1; j < static_cast<int>(arr.size()); ++j) {
            if (arr[i] + arr[j] == target) return {i, j};
        }
    }
    return {-1, -1};
}

pair<int, int> pairSumTwoPointer(const vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return {left, right};
        if (sum < target) ++left;   
        else --right;              
    }
    return {-1, -1};
}

void printVectorPrefix(const vector<int>& arr, int k) {
    cout << "[";
    for (int i = 0; i < k; ++i) {
        if (i) cout << ", ";
        cout << arr[i];
    }
    cout << "]";
}

int main() {
    vector<vector<int>> duplicateTests = {
        {1, 1, 2, 2, 2, 3, 4, 4},
        {5},
        {},
        {-3, -3, -1, 0, 0}
    };

    cout << "PART A: Remove Duplicates\n";
    for (const auto& input : duplicateTests) {
        vector<int> reference;
        int refK = removeDuplicatesReference(input, reference);
        vector<int> optimized = input;
        int k = removeDuplicatesTwoPointer(optimized);

        cout << "Input: ";
        cout << "[";
        for (int i = 0; i < static_cast<int>(input.size()); ++i) {
            if (i) cout << ", ";
            cout << input[i];
        }
        cout << "]\nReference: ";
        printVectorPrefix(reference, refK);
        cout << " (k=" << refK << ")\nOptimized: ";
        printVectorPrefix(optimized, k);
        cout << " (k=" << k << ")\n\n";
    }

    struct PairTest { vector<int> arr; int target; };
    vector<PairTest> pairTests = {
        {{1, 2, 4, 7, 11, 15}, 15},
        {{1, 3, 5, 8}, 7},
        {{2, 4, 6}, 20},
        {{1, 2, 2, 3}, 4}
    };

    cout << "PART B: Pair Sum\n";
    for (const auto& test : pairTests) {
        auto brute = pairSumBruteForce(test.arr, test.target);
        auto fast = pairSumTwoPointer(test.arr, test.target);
        cout << "Target " << test.target << " | Brute force indices: ("
             << brute.first << ", " << brute.second << ") | Two pointers indices: ("
             << fast.first << ", " << fast.second << ")";
        if (fast.first != -1) {
            cout << " | Values: " << test.arr[fast.first] << " + " << test.arr[fast.second];
        }
        cout << "\n";
    }
    return 0;
}