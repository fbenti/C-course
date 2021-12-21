#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Vector **createField(unsigned int m, unsigned int n, Vector v) {
    Vector **mtrx = new Vector*[m];
    for (int i = 0; i < m; i++) {
        mtrx[i] = new Vector[n];
        for (int j = 0; j < n; j++) {
            mtrx[i][j].x = v.x;
            mtrx[i][j].y = v.y;
        }
    }
    return mtrx;
}

// Task 1(b).  Implement this function
void displayField(Vector **A, unsigned int m, unsigned int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << '(' << A[i][j].x;
            cout << ',' << A[i][j].y << ')' << ' ';
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
void addFields(Vector **A, Vector **B, Vector **C,
               unsigned int m, unsigned int n) {
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            C[i][j].x = A[i][j].x + B[i][j].x;
            C[i][j].y = A[i][j].y + B[i][j].y;
        }
    }
}

// Task 1(d).  Implement this function
void scaleField(Vector **A, double c,
                unsigned int m, unsigned int n) {
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            A[i][j].x = A[i][j].x * c;
            A[i][j].y = A[i][j].y * c;
        }
    }
}

// Do not modify
void deleteField(Vector **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; ++i) {
        delete[] A[i];
    }
    delete[] A;
}
