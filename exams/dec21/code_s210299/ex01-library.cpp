#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n) {
    Square **board = new Square *[n];
    for (int i = 0; i < n; i++){
        board[i] = new Square[n];
        for (int j = 0; j < n; j++) {
            board[i][j].piece = Piece::none;
            board[i][j].team = Team::nobody;
        }
    }
    return board;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            if (c[i][j].piece == Piece::none){
                cout << "_ ";
            }
            else if (c[i][j].piece == Piece::rook) {
                if (c[i][j].team == Team::black) {
                    cout << "R ";
                }
                else {cout << "r ";}
            }
            else {
                if (c[i][j].team == Team::black) {
                    cout << "B ";
                }
                else {cout << "b ";}
            }
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n,
          int r1, int c1, int r2, int c2) {
    if(c[r1][c1].piece == Piece::none)
        return false;
    else if (r1==r2 && c1==c2)
        return false;
    else if (c[r1][c1].team != Team::nobody
             && c[r1][c1].team == c[r2][c2].team)
        return false;
    if (c[r1][c1].piece == Piece::rook) {
        if (c1 == c2 || r1 == r2) {
            c[r2][c2].piece = c[r1][c1].piece;
            c[r2][c2].team = c[r1][c1].team;
        }
        else return false;
    }
    else if (c[r1][c1].piece == Piece::bishop) {
        if (abs(c1 - c2) == abs(r1 - r2)) {
            c[r2][c2].piece = c[r1][c1].piece;
            c[r2][c2].team = c[r1][c1].team;
        }
        else return false;
    }
    c[r1][c1].piece = Piece::none;
    c[r1][c1].team = Team::nobody;
    return true;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n,
                int row, int col) {
    if (c[row][col].piece == Piece::none) return false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if (c[i][j].piece == Piece::none) {
                continue;
            }
            else if (c[i][j].piece == Piece::rook) {
                if ((row == i || col == j) &&
                    c[i][j].team != c[row][col].team)
                return true;
            }
            else if (c[i][j].piece == Piece::bishop) {
                if (abs(row -i) == abs(col - j) &&
                    c[i][j].team != c[row][col].team)
                return true;
            }
        }
    }
    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        delete[] c[i];
    }
    delete[] c;
}
