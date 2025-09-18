#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int a) : data(a) {}
};
void insertionNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        newNode->next = newNode;
        tail = newNode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
        if (curr == tail)
        {
            tail = temp;
        }
    }
}
void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail->next; 
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != tail->next);

    cout << "Head" << endl;
}

void delElement(int element, Node *&tail)
{
    Node *delNode = tail;
    int count = 0;
    do
    {
        delNode = delNode->next;
        count++;
    } while (delNode->data != element);
    int i = 1;
    Node *newNode = tail;
    while (i++ < count)
    {
        newNode = newNode->next;
    }
    newNode->next = delNode->next;
    if (delNode == tail && delNode->next == tail)
    {
        tail = NULL; 
    }
    else if (delNode == tail)
    {
        tail = newNode;
    }
    delete delNode;
}

Node* searchNode(Node* tail, int key) {
    if (tail == NULL) return NULL;
    Node* curr = tail->next;
    do {
        if (curr->data == key)
            return curr;
        curr = curr->next;
    } while (curr != tail->next);
    return NULL;
}

int main()
{
    Node *tail = NULL;
    int choice, element, data, key;
    while (true)
    {
        cout << "1. Insert\n2. Delete\n3. Print\n4. Search\n5. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element after which to insert: ";
            cin >> element;
            cout << "Enter data to insert: ";
            cin >> data;
            insertionNode(tail, element, data);
            break;
        case 2:
            cout << "Enter element to delete: ";
            cin >> element;
            delElement(element, tail);
            break;
        case 3:
            print(tail);
            break;
        case 4:
            cout << "Enter element to search: ";
            cin >> key;
            cout << searchNode(tail, key) << endl;
            break;
        case 5:
            return 0;
        }
    }
}

