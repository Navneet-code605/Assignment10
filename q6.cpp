#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool checkDuplicates(Node* root, unordered_set<int>& seen) {
    if (root == nullptr) return false;

    // If value already exists in set → duplicate found
    if (seen.find(root->data) != seen.end()) {
        return true;
    }

    // Insert current node value into set
    seen.insert(root->data);

    // Recursively check left and right subtrees
    return checkDuplicates(root->left, seen) || checkDuplicates(root->right, seen);
}

bool containsDuplicates(Node* root) {
    unordered_set<int> seen;
    return checkDuplicates(root, seen);
}

int main() {
    // Example tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   2   <-- duplicate value (2)

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(2); // duplicate

    if (containsDuplicates(root)) {
        cout << "Duplicates Found" << endl;
    } else {
        cout << "No Duplicates" << endl;
    }

    return 0;
}
