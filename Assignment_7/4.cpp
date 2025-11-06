#include <iostream>
using namespace std;

void mergeSort(int *arr, int start, int end)
{
    int mid = (start + end) / 2;
    if (start < end)
    {
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        int *temp = new int[end - start + 1]();
        int i = 0;
        int left = start;
        int right = mid + 1;
        while (left <= mid && right <= end)
        {

            if (arr[left] < arr[right])
            {
                temp[i++] = arr[left];
                left++;
            }
            else
            {
                temp[i++] = arr[right];
                right++;
            }
        }
        while (left <= mid)
            temp[i++] = arr[left++];
        while (right <= end)
            temp[i++] = arr[right++];
        for (int j = 0; j < i; j++)
        {
            arr[start + j] = temp[j];
        }
        delete[] temp;
    }
}

int main()
{
    int arr[] = {1, 3, 5, 12, 625, 123, 12, 6, 233, 6, 7, 432, 13};
    int n = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}