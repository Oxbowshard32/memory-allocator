#include <iostream>
using namespace std;

// This struct represents a node in a linked list. It contains an integer value and a pointer to the next node.
// To run type ./linked

struct Node {
    int value;
    Node* next;
};

int main() {
    // Create three nodes
    Node a = {10, nullptr};
    Node b = {20, nullptr};
    Node c = {30, nullptr};

    // Link them together
    a.next = &b;
    b.next = &c;

    // Walk the list and print each value
    Node* current = &a;
    while (current != nullptr) {
        cout << current->value << endl;
        current = current->next;
    }
}