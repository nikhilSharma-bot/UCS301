#include<iostream>
using namespace std;

class Node{
    int data;
    Node* prev;
    Node* next;
    public:
    Node(int data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }
    friend void insertAtTail(Node* &tail , int data);
    friend void printLL(Node* head);
    friend void getSize(Node* head);
};
void getSize(Node* head){
    int count=0;
    while(head){
        count++;
        head=head->next;
    }
    cout<<"Nos nodes are->"<<count<<endl;
}
void insertAtTail(Node* &tail , int data){
        Node* temp = new Node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
void printLL(Node* head){
while(head){
    cout<<head->data<<" ";
    head=head->next;
}
cout<<"NULL"<<endl;
}
int main(){
    Node* head= new Node(1);
    Node* tail= head;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    getSize(head);
    insertAtTail(tail,4);
    getSize(head);
    insertAtTail(tail,5);
    getSize(head);
    insertAtTail(tail,6);
    getSize(head);
    printLL(head);
}