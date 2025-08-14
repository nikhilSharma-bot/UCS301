#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[100], uniqueArr[100], m = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        bool isUnique = true;
        for (int j = 0; j < m; j++)
        {
            if (arr[i] == uniqueArr[j])
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
            uniqueArr[m++] = arr[i];
    }
    for (int i = 0; i < m; i++)
        cout << uniqueArr[i] << " ";
}
