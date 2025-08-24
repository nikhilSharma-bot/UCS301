#include <iostream>
using namespace std;

// Diagonal Matrix
void diagonalMatrix(int n)
{
    int diag[50];
    cout << "Enter diagonal elements: ";
    for (int i = 0; i < n; i++)
        cin >> diag[i];

    cout << "Diagonal Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << diag[i] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

// Tri-Diagonal Matrix
void triDiagonal(int n)
{
    int tri[50];
    cout << "Enter " << 3 * n - 2 << " elements (lower, diag, upper): ";
    for (int i = 0; i < 3 * n - 2; i++)
        cin >> tri[i];

    cout << "Tri-Diagonal Matrix:\n";
    int k1 = 0, k2 = n - 1, k3 = 2 * n - 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << tri[k2 + i] << " ";
            else if (i == j + 1)
                cout << tri[k1 + j] << " ";
            else if (j == i + 1)
                cout << tri[k3 + i] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

// Lower Triangular
void lowerTriangular(int n)
{
    int size = n * (n + 1) / 2;
    int lower[100];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
        cin >> lower[i];

    cout << "Lower Triangular Matrix:\n";
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << lower[k++] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

// Upper Triangular
void upperTriangular(int n)
{
    int size = n * (n + 1) / 2;
    int upper[100];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
        cin >> upper[i];

    cout << "Upper Triangular Matrix:\n";
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
                cout << upper[k++] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

// Symmetric
void symmetricMatrix(int n)
{
    int size = n * (n + 1) / 2;
    int sym[100];
    cout << "Enter " << size << " elements (lower triangle): ";
    for (int i = 0; i < size; i++)
        cin >> sym[i];

    cout << "Symmetric Matrix:\n";
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << sym[k++] << " ";
            else
                cout << sym[(j * (j - 1)) / 2 + (i - 1)] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, choice;
    cout << "Enter size of matrix: ";
    cin >> n;

    cout << "\n1. Diagonal Matrix\n2. Tri-Diagonal Matrix\n3. Lower Triangular\n4. Upper Triangular\n5. Symmetric\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        diagonalMatrix(n);
        break;
    case 2:
        triDiagonal(n);
        break;
    case 3:
        lowerTriangular(n);
        break;
    case 4:
        upperTriangular(n);
        break;
    case 5:
        symmetricMatrix(n);
        break;
    default:
        cout << "Invalid Choice\n";
    }
    return 0;
}