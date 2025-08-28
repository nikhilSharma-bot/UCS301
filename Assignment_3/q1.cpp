#include <iostream>
using namespace std;

#define MAXLEN 100

class Stack
{
    int arrLen[MAXLEN];
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
    void push(int a)
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
        for (int i = 0; i <= top; i++)
        {
            cout << arrLen[i] << " ";
        }
        cout << endl;
    }
    void peek()
    {   if(!isEmpty()){
cout << "Peeking at " << arrLen[top] << endl;
    }
    else{
        cout<<"Stack is empty"<<endl;
    }
        
    }
};

int main()
{
    Stack sa;
    int flag = 1;
    while (flag == 1)
    {
        int a;
        cout << "Menu\n 1.Push element\n2.Pop Element\n3.Check if stack is empty\n4.Check if stack is full.\n5.Peek top element\n6.Display Stack\n7.Exit\nMake your choice : ";
        cin >> a;
        switch (a)
        {
        case 1:
            cout << "Enter element to push : " << endl;
            int c;
            cin >> c;
            sa.push(c);
            break;
        case 2:
            sa.pop();
            break;
        case 3:
            if (sa.isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;
        case 4:
            if (sa.isFull())
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            break;
        case 5:
            sa.peek();
            break;
        case 6:
            cout << "Displaying stack " << endl;
            sa.display();
            break;
        case 7:
            cout << "Exiting menu " << endl;
            flag = 0;
            break;
        }
    }
    return 0;
}