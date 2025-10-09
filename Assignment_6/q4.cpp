#include<iostream>
using namespace std;

class Node{
    char data;
    Node* prev;
    Node* next;
    public:
    Node(char data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }
    friend void insertAtTail(Node* &tail , char data);
    friend void printLL(Node* head);
    friend void getSize(Node* head);
    friend void checkPalindrome(Node* head,Node* tail);
};

void insertAtTail(Node* &tail , char data){
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
void checkPalindrome(Node* head,Node* tail){
    string a="";
    string b="";
    while(head){
        a+=head->data;
        head=head->next;
    }
    while(tail){
        b+=tail->data;
        tail=tail->prev;
    }
    if(a==b)cout<<"palindrome"<<endl;
    else cout<<"Not palindrome"<<endl;
}
int main(){
    Node* head= new Node('a');
    Node* tail= head;
    insertAtTail(tail,'b');
    insertAtTail(tail,'c');
    insertAtTail(tail,'c');
    insertAtTail(tail,'b');
    insertAtTail(tail,'a');
    printLL(head);
    checkPalindrome(head,tail);
}