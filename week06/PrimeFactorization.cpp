#include "PrimeFactorization.h"

prime factorize(int x) {
    prime arrays;
    int j = 0;
    for (int i = 2; i <= x; i++) {
        if (x%i == 0)
            arrays.corr_num[j++] = i;
        while (x % i == 0) {
            x /= i;
            arrays.array[i-2] += 1;
        }        
    }
    return arrays;
};