#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void countFrequency(const vector<int>& nums) {
    unordered_map<int, int> freq;  // hash map to store frequency

    // Count occurrences
    for (int num : nums) {
        freq[num]++;  // increment count for each number
    }

    // Print frequencies
    cout << "Frequencies of elements:" << endl;
    for (auto& pair : freq) {
        cout << pair.first << " -> " << pair.second << endl;
    }
}

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};

    countFrequency(nums);

    return 0;
}
