#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q)
{
    if (q.size() % 2 != 0)
        return;
    int halfSize = q.size() / 2;
    queue<int> firstHalf;
    for (int i = 0; i < halfSize; i++)
    {
        firstHalf.push(q.front());
        q.pop();
    }
    while (!firstHalf.empty())
    {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        q.push(arr[i]);
    interleaveQueue(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
