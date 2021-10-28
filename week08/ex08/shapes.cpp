#include "shapes.h"
#include <cmath>


Rectangle::Rectangle(double x,double y) {
    this->h = x;
    this->w = y;
}

double Rectangle::area(void) {
    return this->w * this->h;
}
double Rectangle::perimeter(void) {
    return 2*(this->w + this->h);
}

double Rectangle::height(void) {
    return this->h;
}

double Rectangle::width(void) {
    return this->w;
}

void Rectangle::rotate(void) {
    double temp = this->h;
    this->h = this->w;
    this->w = temp;
}

Square::Square(double x) : Rectangle(x, x) {
    this->length = x;
}

double Square::area(void) {
    return pow(this->length,2);
}

double Square::perimeter(void) {
    return this->length * 4;
}

double Square::height(void) {
    return this->length;
}

double Square::width(void) {
    return this->length;
}

Circle::Circle(double x) {
    this->radius = x;
}

double Circle::area(void) {
    return pow(this->radius,2)*M_PI;
}

double Circle::perimeter(void) {
    return 2*M_PI*this->radius;
}

double Circle::height(void) {
    return 2*this->radius;
}

double Circle::width(void) {
    return 2*this->radius;
}

void Circle::rotate(void) {
    return;
}