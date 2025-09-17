#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }
    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    int findMiddle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1); l.insertEnd(2); l.insertEnd(3);
    l.insertEnd(4); l.insertEnd(5);
    cout << l.findMiddle() << endl;
}