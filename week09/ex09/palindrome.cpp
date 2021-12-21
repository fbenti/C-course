#include <iostream>
#include <vector>
#include <sstream>      // std::istringstream
#include <string>  
using namespace std;


void palindrome(vector<int> vec, uint size) {
    vector<int> reversed(vec);
    // for (int i = 0; i < size; i++) {
    // cout << reversed[i] << " " ;
    // }

    if (size == 0)
        cout << "yes" << endl;
    else {
        if (size % 2 == 0) {
            for (int i = 1; i < size-1; i++) {
                int temp = vec[size-i];
                reversed[size-i] = vec[i];
                reversed[i] = temp;
            }
        }
        else{
            for (int i = 1; i < size-1; i++) {
                if (i==size+1/2)
                    reversed[i-1] = vec[i-1];
                else {
                    int temp = vec[size-i];
                    reversed[size-i] = vec[i-1];
                    reversed[i-1] = temp;
                }
            }
        }
    }
    // for (int i = 0; i < size; i++) {
    //     cout << reversed[i] << " " ;
    // }
    bool equal = false;
    for (int i = 0; i < size; i++) {
        if (vec[i] == reversed[i])
            equal = true;
        else {
            // cout << vec[i] << "  " << reversed[i] << endl;
            cout << "no" << endl;
            equal = false;
            break;
        }
    }
    if (equal) cout << "yes" << endl;
    return;
}



int main() {
    vector<int> vec;

    string line;
    getline( cin, line );
    
    istringstream is( line );
    int n;
    while( is >> n ) {
        vec.push_back(n);
    }

    palindrome(vec, vec.size());

    return 0;
}