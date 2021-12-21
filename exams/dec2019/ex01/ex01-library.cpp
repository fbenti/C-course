#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Implement this function
cell ** createAndInitBoard(int n){
	cell **board = new cell *[n];
	for (int i = 0; i < n; i++) {
		board[i] = new cell[n];
		for (int j = 0; j < n; j++) {
			board[i][j].color = computeColor(i,j);
			if (i < 3 && board[i][j].color == cellColor::dark)
				board[i][j].status = cellStatus::blackPiece;
			else if ((i >= (n-3)  && board[i][j].color == cellColor::dark))
				board[i][j].status = cellStatus::whitePiece;
			else
				board[i][j].status = cellStatus::emptyC;
		}
	}
	return board;
}

//Exercise 1 (b) Implement this function
cell ** duplicateBoard(cell ** A, int n){
	cell **board = new cell *[n];
	for (int i = 0; i < n; i++) 
		board[i] = new cell[n];
	copy(&A[0][0], &A[0][0]+(n+1)*(n+1), &board[0][0]);
	return board;

	// cell ** board = new cell*[n];
	// for(int r=0;r<n;r++){
	// 	board[r]=new cell[n];
	// 	for(int c=0;c<n;c++){
	// 		board[r][c]=A[r][c];
	// 	}
	// }
	// return board;
}

//Exercise 1 (c) Implement this function
bool moveRight(cell ** A,int n,int r, int c){
	if (A[r][c].status == cellStatus::whitePiece 
			&& r-1 >= 0 && c+1 < n
			&& A[r-1][c+1].status == cellStatus::emptyC) {
		A[r-1][c+1].status = cellStatus::whitePiece;
		A[r][c].status = cellStatus::emptyC;
		return true;
	}
	if (A[r][c].status == cellStatus::blackPiece 
			&& r+1 < n && c-1 >= 0
			&& A[r+1][c-1].status == cellStatus::emptyC) {
		A[r+1][c-1].status = cellStatus::blackPiece;
		A[r][c].status = cellStatus::emptyC;
		return true;
	}
	return false;
}

//Exercise 1 (d) Implement this function
bool moveLeft(cell ** A,int n,int r, int c){
	if (A[r][c].status == cellStatus::whitePiece 
			&& r-1 >= 0 && c-1 >= 0
			&& A[r-1][c-1].status == cellStatus::emptyC) {
		A[r-1][c-1].status = cellStatus::whitePiece;
		A[r][c].status = cellStatus::emptyC;
		return true;
	}
	if (A[r][c].status == cellStatus::blackPiece 
			&& r+1 < n && c+1 < n
			&& A[r+1][c+1].status == cellStatus::emptyC) {
		A[r+1][c+1].status = cellStatus::blackPiece;
		A[r][c].status = cellStatus::emptyC;
		return true;
	}
	return false;
}
//Do not modify
cellColor computeColor(int r,int c){
	if((r%2 == 0 && c%2 == 0) || (r%2 != 0 && c%2 != 0)){
		return bright;
	}
	return dark;
}

//Do not modify
void printBoard(cell ** A, int n){
	cout << ' ';
	for(int c=0;c<n;c++){
		cout << c;
	}
	cout << endl;
	for(int r=0;r<n;r++){
		cout << r;
		for(int c=0;c<n;c++){
			//Print ' ' or '#' if empty, or the piece color (W or B)
			switch (A[r][c].status) {
			case emptyC:
				cout << ((A[r][c].color==bright)?' ':'#');
				break;
			case whitePiece:
				cout << "W";
				break;
			case blackPiece:
				cout << "B";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}
