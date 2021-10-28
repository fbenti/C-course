#include "vector2d.h"
#include <cmath>

/*
Vector addition does  change the vector for which it was called	Vector addition does  change the vector for which it was called
Vector/scalar addition does  change the vector for which it was called
--> v1 + v2 == v1 is true because we modify v1 and then compare it with v1 

*/

template<class T>
v2d<T>::v2d(T a, T b) {
    this->x = a;
    this->y = b;
}

template<class T>
v2d<T>::v2d(const v2d<T> &v) {
    this->x = v.x;
    this->y = v.y;
}

template<class T>
v2d<T>::~v2d() {
    return;
}

template<class T>
v2d<T> &v2d<T>::operator=(const v2d<T> &v) {
    this->x = v.x;
    this->y = v.y;
    return *this; // return the object by reference!!!
}

template<class T>
v2d<T> & v2d<T>::operator+(const v2d<T> &v) {
    this->x += v.x;
    this->y += v.y;
    return *this;
}

template<class T>
T v2d<T>::operator*(const v2d<T> &v) {
    return T(this->x * v.x + this->y * v.y);
}

template<class T>
v2d<T> & v2d<T>::operator*(double k) {
    this->x *= k;
    this->y *= k;
    return *this;
}

template<class T>
double v2d<T>::length() {
    return double(sqrt(*this * *this)); // pass the object by reference!!!
}

