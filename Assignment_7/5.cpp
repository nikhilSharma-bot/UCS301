#include <iostream>
using namespace std;

int partition(int *arr, int start, int end){
int pivot = arr[end];
int i = start - 1;
for(int j = start ; j<end ; j++){
    if(arr[j]<pivot){
        swap(arr[++i],arr[j]);
    }
}
swap(arr[i+1], arr[end]);
return i+1;

}
void quickSort(int *arr, int start, int end)
{

if(start>=end) return;
int pivot = partition(arr,start,end);
quickSort(arr,start,pivot-1);
quickSort(arr,pivot+1,end);

}

int main()
{
    int arr[] = {10,80,30,90,40,70};
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}