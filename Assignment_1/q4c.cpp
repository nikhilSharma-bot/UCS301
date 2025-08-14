#include <iostream>
using namespace std;
int main()
{
    int r, c;
    cin >> r >> c;
    int M[10][10], T[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> M[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            T[j][i] = M[i][j];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
            cout << T[i][j] << " ";
        cout << "\n";
    }
}
