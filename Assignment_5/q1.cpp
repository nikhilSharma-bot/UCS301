#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }
    void insertBeg(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }
    void insertEnd(int val) {
        Node* n = new Node(val);
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) { insertBeg(val); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (!temp->next) return;
        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }
    void deleteBeg() {
        if (!head) return;
        Node* t = head;
        head = head->next;
        delete t;
    }
    void deleteEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) { deleteBeg(); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (!temp->next) return;
        Node* t = temp->next;
        temp->next = temp->next->next;
        delete t;
    }
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) { cout << "Found at position " << pos << endl; return; }
            temp = temp->next; pos++;
        }
        cout << "Not Found" << endl;
    }
    void display() {
        Node* temp = head;
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    int choice, val, key;
    while (true) {
        cin >> choice;
        if (choice == 1) { cin >> val; l.insertBeg(val); }
        else if (choice == 2) { cin >> val; l.insertEnd(val); }
        else if (choice == 3) { cin >> key >> val; l.insertAfter(key, val); }
        else if (choice == 4) { cin >> key >> val; l.insertBefore(key, val); }
        else if (choice == 5) l.deleteBeg();
        else if (choice == 6) l.deleteEnd();
        else if (choice == 7) { cin >> key; l.deleteNode(key); }
        else if (choice == 8) { cin >> key; l.search(key); }
        else if (choice == 9) l.display();
        else break;
    }
}
