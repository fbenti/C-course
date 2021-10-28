#include <iostream>
#include "math.h"
using namespace std;

double pi(int n) 
{   
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow(-1,i)/(2*i+1);
    }
    return sum*4;
}

int main()
{   
    int n;
    cin >> n;
    cout << pi(n) << endl;
    return 0;
}