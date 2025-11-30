#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> seen;  // hash set to store elements
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;  // duplicate found
        }
        seen.insert(num);
    }
    return false;  // no duplicates
}

int main() {
    // Example usage:
    vector<int> arr = {1, 2, 3, 4, 5, 1};

    if (containsDuplicate(arr)) {
        cout << "Array contains duplicates." << endl;
    } else {
        cout << "Array does not contain duplicates." << endl;
    }

    return 0;
}
