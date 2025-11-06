#include <iostream>
using namespace std;

int main()
{
    int arr[] = {6,2,8,4,10};
    int n = sizeof(arr) / sizeof(int);
    int i = 0;
    while (i != n-1)
    {
      int min = i;
        for (int l = i+1; l < n; l++)
        {
            if (arr[l] < arr[min])
            {
                min = l;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}