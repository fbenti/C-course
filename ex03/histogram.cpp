#include <iostream>
// #include <new>
#include "math.h"

using namespace std;

int main()
{
    int l, n, x, k;
    int m = 0;
    cin >> l;
    cin >> n;
    
    // when initialize a pointer set in to null
    // int *set = nullptr; 
    // set = new int[n];
    int *set = new int[n];
    int *hist = new int[l];

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > m)
            m = x;
        set[i] = x;
    }
    k = ceil(float(m)/float(l)); 
    
    for (int i = 0; i < n; i++)
    {   
        int result = floor(float(set[i])/float(k));
        hist[result] += 1;
    }

    if (m % l == 0)
        hist[l-1] += 1;

    for (int i = 0; i < l; i++)
    {
        cout << k*i << ": " << hist[i] << endl;
    }

    // REMEMBER TO DEALLOCATE MEMORY
    delete[] set;
    delete[] hist;
    return 0;
}