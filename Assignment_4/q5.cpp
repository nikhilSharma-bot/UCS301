#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q1.push(x);
    }
    void pop()
    {
        if (q1.empty())
            return;
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }
    int top()
    {
        if (q1.empty())
            return -1;
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q2.push(val);
        q1.pop();
        swap(q1, q2);
        return val;
    }
    bool empty()
    {
        return q1.empty();
    }
};

class StackOneQueue
{
    queue<int> q;

public:
    void push(int x)
    {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        if (!q.empty())
            q.pop();
    }
    int top()
    {
        return q.empty() ? -1 : q.front();
    }
    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    int choice;
    cout << "Choose implementation:\n1. Two Queues\n2. One Queue\n";
    cin >> choice;

    if (choice == 1)
    {
        StackTwoQueues st;
        st.push(10);
        st.push(20);
        st.push(30);
        cout << st.top() << endl;
        st.pop();
        cout << st.top() << endl;
    }
    else if (choice == 2)
    {
        StackOneQueue st;
        st.push(10);
        st.push(20);
        st.push(30);
        cout << st.top() << endl;
        st.pop();
        cout << st.top() << endl;
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
