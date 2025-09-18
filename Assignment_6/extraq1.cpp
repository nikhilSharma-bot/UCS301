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
    void displayK(int a){
        int count = 0;
        Node* temp = head;
        while (temp) { 
            if(count++%a==0){
                if(temp->data==INT16_MIN) return;
                cout << temp->data << " ";  
                temp->data=INT16_MIN;
            }
            temp = temp->next;
        }
    }
};


int main() {
    LinkedList l;
    l.insertBeg(13);
    l.insertBeg(12);
    l.insertBeg(11);
    l.insertBeg(10);
    l.insertBeg(9);
    l.insertBeg(8);
    l.insertBeg(7);
    l.insertBeg(6);
    l.insertBeg(5);
    l.insertBeg(4);
    l.insertBeg(3);
    l.insertBeg(2);
    l.insertBeg(1);
    l.display();
    l.displayK(3);
}
