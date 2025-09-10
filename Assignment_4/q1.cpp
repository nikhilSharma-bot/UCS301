/*Develop a menu driven program demonstrating the following operations on simple
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/
#include <iostream>
using namespace std;
#define MAXLEN 100
class Queue
{
    int arrLen[MAXLEN];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }
    bool isFull()
    {
        return rear == MAXLEN - 1;
    }
    void enqueue(int a)
    {
        if (!isFull())
        {
            if (isEmpty())
            {
                front = 0;
            }
            rear++;
            arrLen[rear] = a;
        }
    }
    void dequeue()
    {
        if (!isEmpty())
        {
            cout << "Dequeued " << arrLen[front] << endl;
            front++;
            if (front > rear)
            {
                front = rear = -1;
                cout << "Queue is empty now" << endl;
            }
        }
    }
    void display()
    {
        if (!isEmpty())
        {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arrLen[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Queue is empty" << endl;
        } 
    }
    int peek()
    {
        if (!isEmpty())
        {
            return arrLen[front];
        }
        else
        {
            cout << "Queue is empty" << endl;
            return '\0';
        }
    }
};
Queue q;
int main()
{
    int choice;
    do
    {
        cout << "Menu:\n1.Enqueue\n2.Dequeue\n3.Is Empty\n4.Is Full\n5.Display\n6.Peek\n7.Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int element;
            cout << "Enter element to enqueue: ";
            cin >> element;
            q.enqueue(element);
            break;
        }
        case 2:
            q.dequeue();
            break;
        case 3:
            if (q.isEmpty())
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;
            break;
        case 4:
            if (q.isFull())
                cout << "Queue is full" << endl;
            else
                cout << "Queue is not full" << endl;
            break;
        case 5:
            q.display();
            break;
        case 6:
        {
            int front = q.peek();
            if (front != '\0')
            {
                cout << "Front element is: " << front << endl;
            }
        }
        break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        }
    } while (choice != 7);
    return 0;
}
