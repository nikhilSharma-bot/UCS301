#include <iostream>
using namespace std;
int main()
{
    int R, C;
    cin >> R >> C;
    int mat[10][10];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> mat[i][j];
    for (int i = 0; i < R; i++)
    {
        int sumRow = 0;
        for (int j = 0; j < C; j++)
            sumRow += mat[i][j];
        cout << sumRow << " ";
    }
    cout << "\n";
    for (int j = 0; j < C; j++)
    {
        int sumCol = 0;
        for (int i = 0; i < R; i++)
            sumCol += mat[i][j];
        cout << sumCol << " ";
    }
}
