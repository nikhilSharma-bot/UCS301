#include <iostream>
using namespace std;

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90}, n = 7;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
