#include "ex04-library.h"
#include <iostream>

//Do not modify
Piece::~Piece(){}

//Do not modify
void Piece::printPosition(){
	cout << "(" << r << "," << c << ")" << endl;
}

//Exercise 4 (a) implement methods of WhitePiece
WhitePiece::WhitePiece(int row, int col) {
	this->r = row;
	this->c = col;
}

string WhitePiece::getColor() {
	return "white";
}

string WhitePiece::printCode() {
	return "W";
}

void WhitePiece::moveRight() {
	this->r -= 1;
	this->c += 1;
}

void WhitePiece::moveLeft() {
	this->r -= 1;
	this->c -= 1;
}

//Exercise 4 (b) implement methods of BlackPiece
BlackPiece::BlackPiece(int row, int col) {
	this->r = row;
	this->c = col;
}

string BlackPiece::getColor() {
	return "black";
}

string BlackPiece::printCode() {
	return "B";
}

void BlackPiece::moveRight() {
	this->r += 1;
	this->c -= 1;
}

void BlackPiece::moveLeft() {
	this->r += 1;
	this->c += 1;
}