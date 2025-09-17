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
    int deleteOccurrences(int key) {
        int count = 0;
        while (head && head->data == key) {
            Node* t = head; head = head->next; delete t; count++;
        }
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* t = curr->next;
                curr->next = t->next;
                delete t; count++;
            } else curr = curr->next;
        }
        return count;
    }
    void display() {
        Node* t = head;
        while (t) { cout << t->data << " "; t = t->next; }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1); l.insertEnd(2); l.insertEnd(1); l.insertEnd(2);
    l.insertEnd(1); l.insertEnd(3); l.insertEnd(1);
    int c = l.deleteOccurrences(1);
    cout << "Count: " << c << endl;
    l.display();
}
