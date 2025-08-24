#include <iostream>
using namespace std;

int main()
{
    char str1[100], str2[100], result[200];
    int i, j, len1, len2, choice;

    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Length of Strings\n";
        cout << "2. Copy String\n";
        cout << "3. Concatenate\n";
        cout << "4. Compare\n";
        cout << "5. Reverse\n";
        cout << "6. Toggle Case\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Length
            len1 = 0;
            len2 = 0;
            for (i = 0; str1[i] != '\0'; i++)
                len1++;
            for (i = 0; str2[i] != '\0'; i++)
                len2++;
            cout << "Length of str1: " << len1 << "\n";
            cout << "Length of str2: " << len2 << "\n";
            break;

        case 2: // Copy str1 -> result
            for (i = 0; str1[i] != '\0'; i++)
                result[i] = str1[i];
            result[i] = '\0';
            cout << "Copied string: " << result << "\n";
            break;

        case 3: // Concatenate
            for (i = 0; str1[i] != '\0'; i++)
                result[i] = str1[i];
            for (j = 0; str2[j] != '\0'; j++)
                result[i + j] = str2[j];
            result[i + j] = '\0';
            cout << "Concatenated string: " << result << "\n";
            break;

        case 4: // Compare
            i = 0;
            while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
                i++;
            if (str1[i] == str2[i])
                cout << "Strings are equal\n";
            else
                cout << "Strings are NOT equal\n";
            break;

        case 5: // Reverse str1
            len1 = 0;
            for (i = 0; str1[i] != '\0'; i++)
                len1++;
            cout << "Reverse of str1: ";
            for (i = len1 - 1; i >= 0; i--)
                cout << str1[i];
            cout << "\n";
            break;

        case 6: // Toggle case
            cout << "Toggled str1: ";
            for (i = 0; str1[i] != '\0'; i++)
            {
                if (str1[i] >= 'a' && str1[i] <= 'z')
                    cout << (char)(str1[i] - 32);
                else if (str1[i] >= 'A' && str1[i] <= 'Z')
                    cout << (char)(str1[i] + 32);
                else
                    cout << str1[i];
            }
            cout << "\n";
            break;

        case 7:
            return 0;
        }
    }
}
