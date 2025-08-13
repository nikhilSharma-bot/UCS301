#include <iostream>
using namespace std;

    int main()
    {
        int arr[100], n = 0, choice, pos, val, i, search, found;

        while (true)
        {
            cout << "\n----MENU----\n";
            cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1: 
                cout << "Enter number of elements: ";
                cin >> n;
                cout << "Enter elements: ";
                for (i = 0; i < n; i++)
                    cin >> arr[i];
                break;

            case 2:
                if (n == 0)
                    cout << "Array empty\n";
                else
                {
                    cout << "Array: ";
                    for (i = 0; i < n; i++)
                        cout << arr[i] << " ";
                    cout << "\n";
                }
                break;

            case 3:
                cout << "Enter position (1-" << n + 1 << "): ";
                cin >> pos;
                if (pos < 1 || pos > n + 1)
                {
                    cout << "Invalid position!\n";
                    break;
                }
                cout << "Enter value: ";
                cin >> val;
                for (i = n; i >= pos; i--)
                    arr[i] = arr[i - 1];
                arr[pos - 1] = val;
                n++;
                break;

            case 4:
                cout << "Enter position (1-" << n << "): ";
                cin >> pos;
                if (pos < 1 || pos > n)
                {
                    cout << "Invalid position!\n";
                    break;
                }
                for (i = pos - 1; i < n - 1; i++)
                    arr[i] = arr[i + 1];
                n--;
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> search;
                found = 0;
                for (i = 0; i < n; i++)
                {
                    if (arr[i] == search)
                    {
                        cout << "Found at position " << i + 1 << "\n";
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    cout << "Not found\n";
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice!\n";
            }
        }
    }
