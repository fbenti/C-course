#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c) {
    // dinamically allocate a 2-D array of size n x m
    Complex **mtrx = new Complex*[m]; 
    for (int i = 0; i < m; i++) {
        mtrx[i] = new Complex[n];
        for (int j = 0; j < n; j++) {
            mtrx[i][j].re = c.re;
            mtrx[i][j].im = c.im;
        }
    }
    return mtrx;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j].re ;
            if (A[i][j].im >= 0) cout << '+';
            cout << A[i][j].im << 'i'  << ' ';
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n) {
    Complex d = {1,0};
    Complex o = {0,0};

    Complex **mtrx = new Complex*[n]; 
    for (int i = 0; i < n; i++) {
        mtrx[i] = new Complex[n];
        for (int j = 0; j < n; j++) {
            if (i == j) {
                mtrx[i][j] = d;
            }
            else {
                mtrx[i][j] = {0,0};
            }
        }
    }
    return mtrx;

}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p) {
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++) {
            Complex sum = {0,0};
            for (int k = 0; k < n; k++) {
                Complex mul = mult(A[i][k],B[k][j]);
                sum = add(sum,mul);
            }
            C[i][j] = sum;
        }
    }
}

// Do not modify
Complex add(Complex c, Complex d) {
    Complex result = { c.re + d.re, c.im + d.im };
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d) {
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; i++) { delete[] A[i]; }
    delete[] A;
}
