#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findCommonElements(const vector<int>& A, const vector<int>& B) {
    unordered_set<int> setA(A.begin(), A.end());  // store elements of A
    vector<int> common;

    for (int num : B) {
        if (setA.find(num) != setA.end()) {
            common.push_back(num);  // found common element
        }
    }
    return common;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    vector<int> result = findCommonElements(A, B);

    cout << "Common elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
