#include <iostream>
#include <string> 
using namespace std;

int main()
{
    //read a positive integer
    string temp;
    cin >> temp;
    while ( stoi(temp) < 0) {
        cin >> temp;
    }
    int n = stoi(temp);

    int idx = 0;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            cout << i ;
            if (n>1)
                cout << " * ";
        }   
    }
    cout << endl;
    return 0;
}