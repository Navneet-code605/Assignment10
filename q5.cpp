#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;  // store node addresses
    Node* current = head;

    while (current != nullptr) {
        if (visited.find(current) != visited.end()) {
            return true;  // cycle detected
        }
        visited.insert(current);
        current = current->next;
    }
    return false;  // no cycle
}

int main() {
    // Create nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // Build linked list: 1 → 2 → 3 → 4 → back to 2
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;  // cycle here

    if (hasCycle(n1)) {
        cout << "Linked list contains a cycle." << endl;
    } else {
        cout << "Linked list does not contain a cycle." << endl;
    }

    return 0;
}
