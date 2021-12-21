#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Check and correct if necessary
double * createAndInitArray(unsigned int n, double value){
	double * A = new double[n];
	for(unsigned int i = 0; i < n; i++){
		A[i] = value;
	}
	return A;
}

//Exercise 1 (b) Implement this function
double * duplicateArray(double * A, unsigned int n){
	double * arr = new double[n];
	for(unsigned int i = 0; i < n; i++){
		arr[i] = A[i];
	}
	return arr;
}

//Exercise 1 (c) Implement this function
void deallocateArray(double * A){
	delete [] A;
}

//Exercise 1 (d) Implement this function
double * toFahrenheit(double * A, unsigned int n){
	double *arr = new double[n];
	for(unsigned int i = 0; i < n; i++){
		arr[i] = 32 + 1.8*A[i];
	}
	return arr;
}

//Do not modify
void printArray(double * A, unsigned int n, string descr){
	cout<< "Printing: " << descr << endl;
	for(unsigned int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}
	cout << "\n\n";
}
