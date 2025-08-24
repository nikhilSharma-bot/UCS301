#include <iostream>
using namespace std;

int linearMissing(int arr[], int n)
{
    for (int i = 1; i <= n + 1; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
            if (arr[j] == i)
                found = true;
        if (!found)
            return i;
    }
    return -1;
}

int binaryMissing(int arr[], int n)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] != mid + 1)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l + 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 6}, n = 5;
    cout << "Linear: " << linearMissing(arr, n) << "\n";
    cout << "Binary: " << binaryMissing(arr, n) << "\n";
}
