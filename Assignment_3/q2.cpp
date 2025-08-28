#include <iostream>
using namespace std;

#define MAXLEN 100

class Stack
{
    char arrLen[MAXLEN];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == MAXLEN - 1;
    }
    void push(char a)
    {
        if (!isFull())
        {
            top++;
            arrLen[top] = a;
        }
        cout << "Pushed " << arrLen[top] << endl;
    }
    void pop()
    {
        if (!isEmpty())
        {
            cout << "Popped " << arrLen[top--] << endl;
        }
    }
    void display()
    {
        cout<<endl<<endl;
        for (int i = 0; i <= top; i++)
        {
            cout << arrLen[i];
        }
        cout << endl<<endl;
    }
    char peek()
    {   if(!isEmpty()){
    return arrLen[top];
    }
    else{
        cout<<"Stack is empty"<<endl;
        return '\0';
    }   
    }
};

int main()
{
    string a = "DataStructure";
    Stack b;
    for(int i = 0 ; i < a.length();i++){
        b.push(a[i]);
    }
    Stack rev;
    while(!b.isEmpty()){
        rev.push(b.peek());
        b.pop();
    }
    rev.display();
    return 0;
}