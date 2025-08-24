#include <iostream>
using namespace std;

struct Triplet {
    int row, col, val;
};

void printTriplet(Triplet mat[], int size) {
    cout << "Row Col Val\n";
    for (int i = 0; i < size; i++) {
        cout << mat[i].row << "   " << mat[i].col << "   " << mat[i].val << endl;
    }
}

void transpose(Triplet mat[], Triplet trans[], int size) {
    for (int i = 0; i < size; i++) {
        trans[i].row = mat[i].col;
        trans[i].col = mat[i].row;
        trans[i].val = mat[i].val;
    }
}

int add(Triplet A[], int sizeA, Triplet B[], int sizeB, Triplet C[]) {
    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col))
            C[k++] = A[i++];
        else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col))
            C[k++] = B[j++];
        else {
            C[k] = A[i];
            C[k++].val = A[i++].val + B[j++].val;
        }
    }
    while (i < sizeA) C[k++] = A[i++];
    while (j < sizeB) C[k++] = B[j++];
    return k;
}

int multiply(Triplet A[], int sizeA, Triplet B[], int sizeB, Triplet C[]) {
    int k = 0;
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (A[i].col == B[j].row) {
                C[k].row = A[i].row;
                C[k].col = B[j].col;
                C[k].val = A[i].val * B[j].val;
                k++;
            }
        }
    }
    return k;
}

int main() {
    Triplet A[] = {{0, 0, 1}, {0, 2, 2}, {1, 1, 3}};
    Triplet B[] = {{0, 1, 4}, {1, 1, 5}, {2, 0, 6}};
    int sizeA = 3, sizeB = 3;

    cout << "Matrix A in Triplet form:\n";
    printTriplet(A, sizeA);
    cout << "\nMatrix B in Triplet form:\n";
    printTriplet(B, sizeB);

    Triplet T[10];
    transpose(A, T, sizeA);
    cout << "\nTranspose of A:\n";
    printTriplet(T, sizeA);

    Triplet C[20];
    int sizeC = add(A, sizeA, B, sizeB, C);
    cout << "\nAddition (A + B):\n";
    printTriplet(C, sizeC);

    Triplet M[20];
    int sizeM = multiply(A, sizeA, B, sizeB, M);
    cout << "\nMultiplication (A * B):\n";
    printTriplet(M, sizeM);

    return 0;
}
