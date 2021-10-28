#include "Fraction.h"
#include "PrimeFactorization.h"

#include <iostream>
#include <cmath>

// Constructor
fraction::fraction(int n, int d) {
    this->numerator = n;
    denominator = d;
}

void fraction::add(fraction f) {
    int d = this->denominator * f.denominator;
    numerator = d / this->denominator * this->numerator + d/f.denominator * f.numerator;
    denominator = d;
    prime arrays_n = factorize(numerator);
    prime arrays_d = factorize(denominator);

    bool simplify = false;
    for(int i = 0; i <10; i++) {
        if (arrays_n.array[i] != 0 && arrays_d.array[i] != 0)
            simplify = true;
            break;
    }

    if (simplify) {
        numerator = 0;
        denominator = 0;
        for (int i = 0; i < 10; i++) {
            if (arrays_n.array[i] >= arrays_d.array[i]) {
                arrays_n.array[i] -= arrays_d.array[i];
                arrays_d.array[i] = 0;
            }
            else {
                arrays_d.array[i] -= arrays_n.array[i];
                arrays_n.array[i] = 0;
            }     
            if (arrays_n.array[i] != 0) numerator += pow(arrays_n.corr_num[i], arrays_n.array[i]);

            if (arrays_d.array[i] != 0) denominator += pow(arrays_d.corr_num[i], arrays_d.array[i]);
        }
        if (numerator == 0) numerator = 1;
        if (denominator == 0) denominator = 1;
    }
}

void fraction::mult(fraction f) {
    numerator = this->numerator * f.numerator;
    denominator = this->denominator * f.denominator;
    prime arrays_n = factorize(numerator);
    prime arrays_d = factorize(denominator);

    bool simplify = false;
    for(int i = 0; i <10; i++) {
        if (arrays_n.array[i] != 0 && arrays_d.array[i] != 0)
            simplify = true;
            break;
    }
    if (simplify) {
        numerator = 0;
        denominator = 0;
        for (int i = 0; i < 10; i++) {
            if (arrays_n.array[i] >= arrays_d.array[i]) {
                arrays_n.array[i] -= arrays_d.array[i];
                arrays_d.array[i] = 0;
            }
            else {
                arrays_d.array[i] -= arrays_n.array[i];
                arrays_n.array[i] = 0;
            }     
            if (arrays_n.array[i] != 0) numerator += pow(arrays_n.corr_num[i], arrays_n.array[i]);

            if (arrays_d.array[i] != 0) denominator += pow(arrays_d.corr_num[i], arrays_d.array[i]);
        }
        if (numerator == 0) numerator = 1;
        if (denominator == 0) denominator = 1;
    }

}

void fraction::div(fraction f) {
    numerator = this->numerator * f.denominator;
    denominator = this->denominator * f.numerator;
    prime arrays_n = factorize(numerator);
    prime arrays_d = factorize(denominator);

    bool simplify = false;
    for(int i = 0; i <10; i++) {
        if (arrays_n.array[i] != 0 && arrays_d.array[i] != 0)
            simplify = true;
            break;
    }

    if (simplify) {
        numerator = 0;
        denominator = 0;
        for (int i = 0; i < 10; i++) {
            if (arrays_n.array[i] >= arrays_d.array[i]) {
                arrays_n.array[i] -= arrays_d.array[i];
                arrays_d.array[i] = 0;
            }
            else {
                arrays_d.array[i] -= arrays_n.array[i];
                arrays_n.array[i] = 0;
            }     
            if (arrays_n.array[i] != 0) numerator += pow(arrays_n.corr_num[i], arrays_n.array[i]);

            if (arrays_d.array[i] != 0) denominator += pow(arrays_d.corr_num[i], arrays_d.array[i]);
        }
        if (numerator == 0) numerator = 1;
        if (denominator == 0) denominator = 1;
    }

}

void fraction::display(void) {
    std::cout << this->numerator << " / "  << this->denominator << std::endl;
}